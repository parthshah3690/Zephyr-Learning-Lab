#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(sensor_manager);

void sensor_manager_process(void)
{
    static int32_t temperature = 25;
    LOG_INF("Temperature value : %d degC", temperature);

    if (temperature > 30)
    {
        LOG_WRN("Temperature is high");
    }
    temperature++;
}