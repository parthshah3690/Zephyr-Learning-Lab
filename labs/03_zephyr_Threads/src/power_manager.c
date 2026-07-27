#include "power_manager.h"

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
                state = POWER_IDLE;
                break;
            }

            case POWER_IDLE:
            {
                LOG_INF("Power state : IDLE");
                state = POWER_SLEEP;
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
                state = POWER_ACTIVE;
                break;
            }
        }

        k_sleep(K_SECONDS(10));
    }
}