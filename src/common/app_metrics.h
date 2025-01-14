#pragma once
#include <timing.h>

namespace Buddy {
namespace Metrics {
    void RecordMarlinVariables();
    void RecordRuntimeStats();
    void RecordPowerStats();
    void RecordPrintFilename();
    void record_dwarf_mcu_temperature();

    struct RunApproxEvery {
        uint32_t interval_ms;
        uint32_t last_run_timestamp;

        constexpr RunApproxEvery(uint32_t interval_ms)
            : interval_ms(interval_ms)
            , last_run_timestamp(0) {
        }

        bool operator()() {
            if (ticks_diff(ticks_ms(), last_run_timestamp) > static_cast<int32_t>(interval_ms)) {
                last_run_timestamp = ticks_ms();
                return true;
            } else {
                return false;
            }
        }
    };
}
}
