// trinamic.cpp
#include "cmsis_os.h"
#include "trinamic.h"
#include "config.h"
#include "gpio.h"
#include "hwio_pindef.h"
#include "../Marlin/src/module/stepper.h"
#include "TMCStepper.h"
#include "bsod.h"
#include "metric.h"
#include <device/board.h>
#include "eeprom.h"

using namespace buddy::hw;
#if HAS_DRIVER(TMC2130)
static TMC2130Stepper *pStep[4] = { nullptr, nullptr, nullptr, nullptr };
#elif HAS_DRIVER(TMC2209)
static TMC2209Stepper *pStep[4] = { nullptr, nullptr, nullptr, nullptr };
#endif

static uint16_t tmc_sg[4];      // stallguard result for each axis
static uint8_t tmc_sg_mask = 7; // stallguard result sampling mask (bit0-x, bit1-y, ...), xyz by default
static uint8_t tmc_sg_axis = 0; // current axis for stallguard result sampling (0-x, 1-y, ...)

static tmc_sg_sample_cb_t *tmc_sg_sample_cb = NULL; // sg sample callback

tmc_reg_t tmc_reg_map[] = {
    /*  { cmd_name, reg_adr, write, read }, */
    { "gconf", 0x00, true, true },
    { "gstat", 0x01, true, true },
#if HAS_DRIVER(TMC2130)
    { "ioin", 0x04, false, true },
#endif
#if HAS_DRIVER(TMC2209)
    { "ifcnt", 0x02, false, true },
    { "slaveconf", 0x03, true, false },
    { "otp_prog", 0x04, true, false },
    { "otp_read", 0x05, false, true },
    { "ioin", 0x06, false, true },
    { "factory_conf", 0x07, true, true },
#endif
    { "ihold_irun", 0x10, true, false },
    { "tpower_down", 0x11, true, false },
    { "tstep", 0x12, false, true },
    { "tpwmthrs", 0x13, true, false },
    { "tcoolthrs", 0x14, true, false },
#if HAS_DRIVER(TMC2130)
    { "thigh", 0x15, true, false },
#endif
#if HAS_DRIVER(TMC2209)
    { "vactual", 0x22, true, false },
#endif
#if HAS_DRIVER(TMC2130)
    { "xdirect", 0x2D, true, true },
    { "vdcmin", 0x33, true, false },
#endif
#if HAS_DRIVER(TMC2209)
    { "sgthrs", 0x40, true, false },
    { "sg_result", 0x41, false, true },
    { "coolconf", 0x42, true, false },
#endif
#if HAS_DRIVER(TMC2130)
    { "mslut0", 0x60, true, false },
    { "mslut1", 0x61, true, false },
    { "mslut2", 0x62, true, false },
    { "mslut3", 0x63, true, false },
    { "mslut4", 0x64, true, false },
    { "mslut5", 0x65, true, false },
    { "mslut6", 0x66, true, false },
    { "mslut7", 0x67, true, false },
    { "mslutsel", 0x68, true, false },
    { "mslutstart", 0x69, true, false },
#endif
    { "mscnt", 0x6A, false, true },
    { "mscuract", 0x6B, false, true },
    { "chopconf", 0x6C, true, true },
#if HAS_DRIVER(TMC2130)
    { "coolconf", 0x6D, true, false },
    { "dcctrl", 0x6D, true, false },
#endif
    { "drv_status", 0x6F, false, true },
    { "pwmconf", 0x70, true, true },
    { "pwm_scale", 0x71, false, true },
#if HAS_DRIVER(TMC2209)
    { "pwm_auto", 0x72, false, true },
#endif
#if HAS_DRIVER(TMC2130)
    { "encm_ctrl", 0x72, true, false },
    { "lost_steps", 0x73, false, true },
#endif
    { NULL, 0x00, false, false },
};

osMutexDef(tmc_mutex);
osMutexId tmc_mutex_id;

extern "C" {

uint8_t tmc_get_sg_mask() { return tmc_sg_mask; }
uint8_t tmc_get_sg_axis() { return tmc_sg_axis; }
tmc_sg_sample_cb_t *tmc_get_sg_sample_cb() { return tmc_sg_sample_cb; }

void tmc_set_sg_mask(uint8_t mask) { tmc_sg_mask = mask; }
void tmc_set_sg_axis(uint8_t axis) { tmc_sg_axis = axis; }
void tmc_set_sg_sample_cb(tmc_sg_sample_cb_t *cb) { tmc_sg_sample_cb = cb; }

void tmc_delay(uint16_t time) // delay for switching tmc step pin level
{
    volatile uint16_t tmc_delay;
    for (tmc_delay = 0; tmc_delay < time; time--) {
    }
}

void tmc_enable_wavetable(bool enabled, bool X, bool Y, bool Z) {
#ifdef HAS_TMC_WAVETABLE
    if (enabled) {
        (void)0;
    #ifndef HAS_LDO_400_STEP
        #error "wavetable not defined for this motor type"
    #endif
    }
    if (enabled && Y) {
        pStep[Y_AXIS]->write(0x69, 0x00f80000);
        pStep[Y_AXIS]->write(0x60, 0x56ad6b6a);
        pStep[Y_AXIS]->write(0x61, 0x54aaaaab);
        pStep[Y_AXIS]->write(0x62, 0x44449252);
        pStep[Y_AXIS]->write(0x63, 0x00020208);
        pStep[Y_AXIS]->write(0x64, 0xefe00000);
        pStep[Y_AXIS]->write(0x65, 0xadbb777b);
        pStep[Y_AXIS]->write(0x66, 0x252aaab5);
        pStep[Y_AXIS]->write(0x67, 0x00810889);
        pStep[Y_AXIS]->write(0x68, 0xff940159);
    }
    if (enabled && X) {
        pStep[X_AXIS]->write(0x69, 0x00f80000);
        pStep[X_AXIS]->write(0x60, 0x5ad6dada);
        pStep[X_AXIS]->write(0x61, 0x4a9556ab);
        pStep[X_AXIS]->write(0x62, 0x84444929);
        pStep[X_AXIS]->write(0x63, 0x00001020);
        pStep[X_AXIS]->write(0x64, 0xbefe0000);
        pStep[X_AXIS]->write(0x65, 0x5b6eeeef);
        pStep[X_AXIS]->write(0x66, 0x4a55556b);
        pStep[X_AXIS]->write(0x67, 0x00810892);
        pStep[X_AXIS]->write(0x68, 0xff900159);
    }
    if (enabled && Z) {
        pStep[Z_AXIS]->write(0x69, 0x00f80000);
        pStep[Z_AXIS]->write(0x60, 0xb77bbdf6);
        pStep[Z_AXIS]->write(0x61, 0xa5556b6d);
        pStep[Z_AXIS]->write(0x62, 0x10210924);
        pStep[Z_AXIS]->write(0x63, 0x7f800000);
        pStep[Z_AXIS]->write(0x64, 0xf77befbf);
        pStep[Z_AXIS]->write(0x65, 0xdbb76eee);
        pStep[Z_AXIS]->write(0x66, 0x55555ada);
        pStep[Z_AXIS]->write(0x67, 0x0102224a);
        pStep[Z_AXIS]->write(0x68, 0xff760159);
    }
    if (!enabled && Y) {
        pStep[Y_AXIS]->write(0x69, 0x00F70000);
        pStep[Y_AXIS]->write(0x60, 0xAAAAB554);
        pStep[Y_AXIS]->write(0x61, 0x4A9554AA);
        pStep[Y_AXIS]->write(0x62, 0x24492929);
        pStep[Y_AXIS]->write(0x63, 0x10104222);
        pStep[Y_AXIS]->write(0x64, 0xFBFFFFFF);
        pStep[Y_AXIS]->write(0x65, 0xB5BB777D);
        pStep[Y_AXIS]->write(0x66, 0x49295556);
        pStep[Y_AXIS]->write(0x67, 0x00404222);
        pStep[Y_AXIS]->write(0x68, 0xFFFF8056);
    }
    if (!enabled && X) {
        pStep[X_AXIS]->write(0x69, 0x00F70000);
        pStep[X_AXIS]->write(0x60, 0xAAAAB554);
        pStep[X_AXIS]->write(0x61, 0x4A9554AA);
        pStep[X_AXIS]->write(0x62, 0x24492929);
        pStep[X_AXIS]->write(0x63, 0x10104222);
        pStep[X_AXIS]->write(0x64, 0xFBFFFFFF);
        pStep[X_AXIS]->write(0x65, 0xB5BB777D);
        pStep[X_AXIS]->write(0x66, 0x49295556);
        pStep[X_AXIS]->write(0x67, 0x00404222);
        pStep[X_AXIS]->write(0x68, 0xFFFF8056);
    }
    if (!enabled && Z) {
        pStep[Z_AXIS]->write(0x69, 0x00F70000);
        pStep[Z_AXIS]->write(0x60, 0xAAAAB554);
        pStep[Z_AXIS]->write(0x61, 0x4A9554AA);
        pStep[Z_AXIS]->write(0x62, 0x24492929);
        pStep[Z_AXIS]->write(0x63, 0x10104222);
        pStep[Z_AXIS]->write(0x64, 0xFBFFFFFF);
        pStep[Z_AXIS]->write(0x65, 0xB5BB777D);
        pStep[Z_AXIS]->write(0x66, 0x49295556);
        pStep[Z_AXIS]->write(0x67, 0x00404222);
        pStep[Z_AXIS]->write(0x68, 0xFFFF8056);
    }
#else
    (void)(enabled && X && Y && Z);
#endif //HAS_TMC_WAVETABLE
}

void init_tmc(void) {
    init_tmc_bare_minimum();
    //pointers to TMCStepper instances
    pStep[X_AXIS] = &stepperX;
    pStep[Y_AXIS] = &stepperY;
    pStep[Z_AXIS] = &stepperZ;
    pStep[E_AXIS] = &stepperE0;
    //set TCOOLTHRS
    pStep[X_AXIS]->TCOOLTHRS(400);
    pStep[Y_AXIS]->TCOOLTHRS(400);
    pStep[Z_AXIS]->TCOOLTHRS(400);
    pStep[E_AXIS]->TCOOLTHRS(400);
#if HAS_DRIVER(TMC2209)
    pStep[X_AXIS]->SGTHRS(130);
    pStep[Y_AXIS]->SGTHRS(130);
    pStep[Z_AXIS]->SGTHRS(100);
    pStep[E_AXIS]->SGTHRS(100);
#endif
}

void init_tmc_bare_minimum(void) {
    tmc_mutex_id = osMutexCreate(osMutex(tmc_mutex));

    //pointers to TMCStepper instances
    pStep[X_AXIS] = &stepperX;
    pStep[Y_AXIS] = &stepperY;
    pStep[Z_AXIS] = &stepperZ;
    pStep[E_AXIS] = &stepperE0;
#if HAS_DRIVER(TMC2209)
    pStep[X_AXIS]->SLAVECONF(0x300);
    pStep[Y_AXIS]->SLAVECONF(0x300);
    pStep[Z_AXIS]->SLAVECONF(0x300);
    pStep[E_AXIS]->SLAVECONF(0x300);
#endif

#ifdef HAS_TMC_WAVETABLE
    tmc_enable_wavetable(eeprom_get_bool(EEVAR_TMC_WAVETABLE_ENABLED), true, true, true);
#endif
}

/// Acquire lock for mutual exclusive access to the trinamic's serial port
///
/// This implements a weak symbol declared within the TMCStepper library
bool tmc_serial_lock_acquire(void) {
    return osMutexWait(tmc_mutex_id, osWaitForever) == osOK;
}

/// Release lock for mutual exclusive access to the trinamic's serial port
///
/// This implements a weak symbol declared within the TMCStepper library
void tmc_serial_lock_release(void) {
    osMutexRelease(tmc_mutex_id);
}

/// Called when an error occurs when communicating with the TMC over serial
///
/// This implements a weak symbol declared within the TMCStepper library
void tmc_communication_error(void) {
    bsod("trinamic communication error");
}

static char tmc_slave_addr_to_axis_character([[maybe_unused]] uint8_t slave_addr) {
    return '?';
}

static char should_log_register_operation(uint8_t reg_addr) {
    if (reg_addr == 0x02 /*IFCNT*/ || reg_addr == 0x41 /*SG_RESULT*/) {
        return false;
    } else {
        return true;
    }
}

static const char *tmc_reg_addr_to_name(uint8_t addr) {
    tmc_reg_t *tmc_reg = tmc_reg_map;
    while (tmc_reg->cmd_name != NULL) {
        if (tmc_reg->reg_adr == addr)
            return tmc_reg->cmd_name;
        tmc_reg++;
    }
    return "UNKNOWN";
}

void tmc_register_write_hook(uint8_t slave_addr, uint8_t reg_addr, uint32_t val) {
    if (!should_log_register_operation(reg_addr))
        return;
    static metric_t metric_write = METRIC("tmc_write", METRIC_VALUE_CUSTOM, 0, METRIC_HANDLER_ENABLE_ALL);
    metric_record_custom(&metric_write, ",ax=%c reg=%ui,regn=\"%s\",value=%ui",
        tmc_slave_addr_to_axis_character(slave_addr), reg_addr, tmc_reg_addr_to_name(reg_addr), val);
}

void tmc_register_read_hook(uint8_t slave_addr, uint8_t reg_addr, uint32_t val) {
    if (!should_log_register_operation(reg_addr))
        return;
    static metric_t metric_write = METRIC("tmc_read", METRIC_VALUE_CUSTOM, 0, METRIC_HANDLER_ENABLE_ALL);
    metric_record_custom(&metric_write, ",ax=%c reg=%ui,regn=\"%s\",value=%ui",
        tmc_slave_addr_to_axis_character(slave_addr), reg_addr, tmc_reg_addr_to_name(reg_addr), val);
}

// this function performs stallguard sample for single axis
// return value contain bitmask of sampled axis, in case of nonzero return value this call take 5ms
//  Now we are using stepper.axis_is_moving and value is set to zero for stopped motor,
//  right way is reading tstep and comparing it to TCOOLTHRS, but it takes time (read register).
//  Using stepper.axis_is_moving is simple but in some cases we get bad samples (tstep > TCOOLTHRS).
//  Maybe we can improve this by calculating tstep from stepper variables.
uint8_t tmc_sample(void) {
    uint8_t mask = 0;
    if (tmc_sg_mask) {
        while ((tmc_sg_mask & (1 << tmc_sg_axis)) == 0)
            tmc_sg_axis = (tmc_sg_axis + 1) & 0x03;
        if (stepper.axis_is_moving((AxisEnum)tmc_sg_axis)) {
            mask = (1 << tmc_sg_axis);
#if HAS_DRIVER(TMC2130)
            tmc_sg[tmc_sg_axis] = pStep[tmc_sg_axis]->sg_result();
#elif HAS_DRIVER(TMC2209)
            tmc_sg[tmc_sg_axis] = pStep[tmc_sg_axis]->SG_RESULT();
#endif
        } else
            tmc_sg[tmc_sg_axis] = 0;
        if (tmc_sg_sample_cb)
            tmc_sg_sample_cb(tmc_sg_axis, tmc_sg[tmc_sg_axis]);
        tmc_sg_axis = (tmc_sg_axis + 1) & 0x03;
    }
    return mask;
}

extern uint16_t tmc_get_last_sg_sample(uint8_t axis) {
    return tmc_sg[axis];
}

} //extern "C"
