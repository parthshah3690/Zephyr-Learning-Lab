#include "power_manager.h"
#include "system_manager.h"

LOG_MODULE_REGISTER(power_manager);

typedef enum
{
    POWER_INIT,
    POWER_ACTIVE,
    POWER_IDLE,
    POWER_SLEEP
}power_state_t;

static power_state_t state = POWER_INIT;

void power_manager_init(void)
{
    state = POWER_INIT;
    LOG_INF("Power management initialized");
}

void power_manager_thread(void* p1, void* p2, void* p3)
{
    ARG_UNUSED(p1);
    ARG_UNUSED(p2);
    ARG_UNUSED(p3);

    while (true)
    {
        LOG_INF("Reading system status...");
        system_status_t system_status = system_manager_get_system_status();

        LOG_INF("Temperature : %d, Vehicle Speed : %u, Communication : %s", system_status.temperature, system_status.vehicle_speed, system_status.communication_ok ? "OK" : "FAIL");
        
        switch (state)
        {
            case POWER_INIT:
            {
                LOG_INF("Power state : INIT");
                state = POWER_ACTIVE;
                break;
            }

            case POWER_ACTIVE:
            {
                LOG_INF("Power state : ACTIVE");
                if (system_status.temperature > 80)
                {
                    LOG_WRN("High temperature detected");
                    state = POWER_IDLE;
                }
                else
                {
                    state = POWER_ACTIVE;
                }
                break;
            }

            case POWER_IDLE:
            {
                LOG_INF("Power state : IDLE");
                if (system_status.communication_ok == false)
                {
                    LOG_WRN("Communication lost");
                    state = POWER_SLEEP;
                }
                break;
            }

            case POWER_SLEEP:
            {
                LOG_INF("Power state : SLEEP");
                state = POWER_ACTIVE;
                break;
            }
        
            default:
            {
                state = POWER_INIT;
                break;
            }
        }

        k_sleep(K_SECONDS(10));
    }
}