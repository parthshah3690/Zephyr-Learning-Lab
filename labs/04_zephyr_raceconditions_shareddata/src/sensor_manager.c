#include "sensor_manager.h"
#include "system_manager.h"

LOG_MODULE_REGISTER(sensor_manager);

void sensor_manager_thread(void* p1, void* p2, void* p3)
{
    ARG_UNUSED(p1);
    ARG_UNUSED(p2);
    ARG_UNUSED(p3);
    
    int temperature = 25;

    while (true)
    {
        LOG_INF("Temperature value : %d degC", temperature);

        if (temperature < 100)
        {
            temperature++;
        }
        system_status.temperature = temperature;

        k_sleep(K_SECONDS(1));
    }
}