#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(power_manager);

void power_manager_init(void)
{
    LOG_INF("Power management initialized");
}