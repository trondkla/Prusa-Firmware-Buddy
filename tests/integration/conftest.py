import sys
import binascii
import functools
import asyncio
import pytest_asyncio
from _pytest.stash import StashKey
from _pytest.reports import CollectReport
import hashlib
import pytest
import json
import shutil
from pathlib import Path
import platform
import logging

logger = logging.getLogger('conftest')

# add the /utils to PATH so we can use the `simulator` package
project_root = Path(__file__).resolve().parent.parent.parent
utils_dir = project_root / 'utils'
sys.path.insert(0, str(utils_dir))

from .actions import screen
from simulator import Simulator, MachineType, Printer


def pytest_addoption(parser):
    # yapf: disable
    parser.addoption(
        '--simulator',
        type=str,
        help='path to the simulator\'s binary to use',
    )
    parser.addoption(
        '--firmware',
        type=str,
        required=True,
        help='path to the firmware (.bin file) to test',
    )
    parser.addoption(
        '--enable-graphic',
        action='store_true',
        help='Enable graphic of QEMU to see what\'s happenning',
    )
    # yapf: enable


@pytest.fixture
def simulator_path(pytestconfig) -> Path:
    path_str = pytestconfig.getoption('--simulator')
    if path_str:
        return Path(path_str)

    # use default from dependencies directory
    path = Simulator.default_simulator_path()
    if path:
        return path

    raise pytest.UsageError('failed to find default simulator'
                            '(try to run bootstrap.py) and none was'
                            'specified using the --simulator')


@pytest.fixture
def data_dir(pytestconfig) -> Path:
    return project_root / 'tests' / 'integration' / 'data'


@pytest.fixture
def firmware_path(pytestconfig):
    return Path(pytestconfig.getoption('--firmware'))


@pytest.fixture
def simulator_scriptio_port(unused_tcp_port_factory):
    return unused_tcp_port_factory()


@pytest.fixture
def qemu_img_path(simulator_path) -> Path:
    if platform.system() == "Windows":
        qemu_img_exe_path = simulator_path.parent / "qemu-img.exe"
        return Path(qemu_img_exe_path)
    else:
        return "qemu-img" # on linux system this tool is a part of qemu-utils package


async def create_qcow2_image_file(qemu_img_binary_path, file_name, file_size):
    params = ['create', '-f', 'qcow2', '-o', 'preallocation=metadata', str(file_name), str(file_size)]
    logger.info('starting qemu_img with command: %s %s', qemu_img_binary_path, ' '.join(params))
    process = await asyncio.create_subprocess_exec(str(qemu_img_binary_path), *params)
    return_code = await process.wait()
    if return_code != 0:
        raise Exception("qemu_img returned " +str(return_code))


@pytest_asyncio.fixture
async def snapshots_image_file_path(qemu_img_path, tmpdir):
    snapshots_path = tmpdir / 'snapshots.qcow2'
    file_size = 2**23
    await create_qcow2_image_file(qemu_img_path, snapshots_path, file_size)
    return snapshots_path

@pytest.fixture
def debug_command_file_path(tmpdir):
    file = tmpdir / 'debug_command.txt'
    return file

@pytest.fixture
def simulator_proxy_port(unused_tcp_port_factory):
    return unused_tcp_port_factory()


def get_language_code(lang):
    data = [ord(c) for c in lang]
    return data[1] << 8 | data[0]


@pytest.fixture
def eeprom_variables():
    return {
        'LANGUAGE': get_language_code('en'),  # default lang for tests
        'RUN_SELFTEST': 0,  # skip wizard
        'PL_PASSWORD': "0123456789",
    }


def get_hash(*items):
    ctx = hashlib.sha256()
    for item in items:
        if isinstance(item, str):
            ctx.update(item.encode('utf-8'))
        elif isinstance(item, bytes):
            ctx.update(item)
        elif isinstance(item, Path):
            with open(item, 'rb') as f:
                for chunk in iter(lambda: f.read(1024), b''):
                    ctx.update(chunk)
        else:
            raise ValueError('invalid value type %s', type(item))
    return ctx.hexdigest()


async def prepare_xflash_content(firmware_path, basic_printer_arguments,
                                 tmpdir, flash):
    flash_dir = tmpdir.mkdir('flash_for_xflash_init')
    shutil.copyfile(str(firmware_path.with_suffix('.bbf')),
                    str(flash_dir / 'firmware.bbf'))

    async def wait_for_bootstrap(printer: Printer):
        while await screen.is_booting(printer):
            pass

    async with Simulator.run(**basic_printer_arguments,
                             mount_dir_as_flash=flash_dir,
                             xflash_content=flash) as printer:
        try:
            await asyncio.wait_for(wait_for_bootstrap(printer), timeout=600.0)
        except asyncio.TimeoutError:
            pytest.fail('timed out while waiting for xflash bootstrap')


@pytest_asyncio.fixture
async def xflash_content(basic_printer_arguments, firmware_path, tmpdir,
                         request, qemu_img_path):
    # create empty xflash content
    xflash_size = 2**23
    xflash_path = tmpdir / 'xflash.qcow2'
    await create_qcow2_image_file(qemu_img_path, xflash_path, xflash_size)

    # xflash content
    requested_xflash_hash = get_hash('v1', Path(firmware_path))
    key = f'xflash-content:{requested_xflash_hash}'
    xflash_content = request.config.cache.get(key, None)
    if xflash_content:
        with open(xflash_path, 'wb') as f:
            f.write(binascii.unhexlify(xflash_content))
            return xflash_path

    await prepare_xflash_content(
        firmware_path,
        basic_printer_arguments=basic_printer_arguments,
        tmpdir=tmpdir,
        flash=xflash_path)

    # save it for later
    request.config.cache.set(key, xflash_path.read_binary().hex())

    # and finally return
    return xflash_path


async def prepare_eeprom_content(eeprom_variables, basic_printer_arguments,
                                 xflash_content, tmpdir, eeprom_bank_1: Path,
                                 eeprom_bank_2: Path):
    flash_dir = tmpdir.mkdir('flash_for_eeprom_init')
    with open(flash_dir / 'AUTO.GCO', 'w') as f:
        for variable_name, variable_value in eeprom_variables.items():
            f.write(f'M505 {variable_name} {variable_value}\n')

    async def wait_for_eeprom_load(printer: Printer):
        while await screen.is_booting(printer):
            pass

    async with Simulator.run(**basic_printer_arguments,
                             mount_dir_as_flash=flash_dir,
                             xflash_content=xflash_content,
                             eeprom_content=(eeprom_bank_1,
                                             eeprom_bank_2)) as printer:
        try:
            await asyncio.wait_for(wait_for_eeprom_load(printer), timeout=30.0)
            await asyncio.sleep(10)
        except asyncio.TimeoutError:
            pytest.fail('timed out while waiting for eeprom setup; '
                        'please check your firmware is compiled with '
                        '-DCUSTOM_COMPILE_OPTIONS:STRING=-DAUTOSTART_GCODE=1')


@pytest_asyncio.fixture
async def eeprom_content(eeprom_variables, basic_printer_arguments,
                         xflash_content, tmpdir, firmware_path, request, qemu_img_path):
    # create empty eeprom banks
    bank_size = 65536
    bank_1 = tmpdir / 'eeprom_bank1.qcow2'
    bank_2 = tmpdir / 'eeprom_bank2.qcow2'
    await create_qcow2_image_file(qemu_img_path, bank_1, bank_size)
    await create_qcow2_image_file(qemu_img_path, bank_2, bank_size)
    bank_paths = (bank_1, bank_2)

    # empty eeprom requested
    if not eeprom_variables:
        return bank_paths

    # look into cache and recover the eeprom content if we have it already
    requested_eeprom_hash = get_hash('v1', Path(firmware_path),
                                     json.dumps(eeprom_variables))
    key = f'eeprom-content:{requested_eeprom_hash}'
    eeprom_content = request.config.cache.get(key, None)
    if eeprom_content:
        for bank_path, bank_content_hex in zip(bank_paths, eeprom_content):
            with open(bank_path, 'wb') as f:
                f.write(binascii.unhexlify(bank_content_hex))
        return bank_paths

    # generate the eeprom content
    await prepare_eeprom_content(eeprom_variables, basic_printer_arguments,
                                 xflash_content, tmpdir, bank_1, bank_2)

    # save it for later
    eeprom_content = []
    for bank_path in bank_paths:
        with open(bank_path, 'rb') as f:
            eeprom_content.append(f.read().hex())
    request.config.cache.set(key, eeprom_content)

    # and finally return
    return bank_paths


@pytest.fixture
def printer_flash_dir(tmpdir):
    return tmpdir.mkdir('printer_flash_dir')



@pytest.fixture
def basic_printer_arguments(simulator_path, firmware_path,
                            simulator_scriptio_port, simulator_proxy_port,
                            tmpdir, pytestconfig) -> dict:
    enable_graphic = pytestconfig.getoption('--enable-graphic')

    return dict(simulator_path=simulator_path,
                machine=MachineType.MINI,
                firmware_path=firmware_path,
                scriptio_port=simulator_scriptio_port,
                http_proxy_port=simulator_proxy_port,
                tmpdir=Path(tmpdir.mkdir('simulator')),
                nographic=not enable_graphic)


phase_report_key = StashKey[dict[str, CollectReport]]()

@pytest_asyncio.fixture
async def printer_factory(basic_printer_arguments, xflash_content,
                          eeprom_content, printer_flash_dir, 
                          snapshots_image_file_path, debug_command_file_path,
                          request):
    def is_test_failed():
        report = request.node.stash.get(phase_report_key, {})
        setup_passed = report["setup"].passed if "setup" in report else True
        call_passed = report["call"].passed if "call" in report else True
        logging.info(f"TestReport [contains phase, phase succeeded]: Setup: [{'setup' in report}, {setup_passed}], Call: [{'call' in report}, {call_passed}]")
        return not setup_passed or not call_passed

    return functools.partial(Simulator.run,
                             **basic_printer_arguments,
                             eeprom_content=eeprom_content,
                             xflash_content=xflash_content,
                             mount_dir_as_flash=printer_flash_dir,
                             snapshots_path=snapshots_image_file_path,
                             file_path_to_save_command_for_debugging=debug_command_file_path,
                             should_save_crashdump_func=is_test_failed)


@pytest_asyncio.fixture
async def printer(printer_factory):
    async with printer_factory() as printer:
        yield printer


# inspired by this: https://docs.pytest.org/en/latest/example/simple.html#making-test-result-information-available-in-fixtures
@pytest.hookimpl(tryfirst=True, hookwrapper=True)
def pytest_runtest_makereport(item, call):
    # execute all other hooks to obtain the report object
    outcome = yield
    rep = outcome.get_result()
    # store test results for each phase of a call, which can
    # be "setup", "call", "teardown"
    item.stash.setdefault(phase_report_key, {})[rep.when] = rep
    logging.info(f"Saving test result for phase '{rep.when}'. Success: {rep.passed}")
