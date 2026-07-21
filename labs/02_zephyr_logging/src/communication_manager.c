#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(communication_manager);

void communication_manager_process(void)
{
    static int32_t counter = 0;

    if (counter++ >= 10000)
    {
        counter = 0;
    }

    LOG_INF("Communication cycle %d", counter);

    if(counter % 5 == 0)
    {
        LOG_ERR("Communication timeout detected");
    }
}