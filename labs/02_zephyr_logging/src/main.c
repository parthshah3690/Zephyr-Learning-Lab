#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main);

void power_manager_init(void);
void system_manager_init(void);
void sensor_manager_process(void);
void communication_manager_process(void);

int main(void)
{
    LOG_INF("Zephyr Logging started!");

    power_manager_init();
    system_manager_init();

    while (true)
    {
        sensor_manager_process();
        communication_manager_process();

        k_sleep(K_SECONDS(1));
    }
    return 0;
}