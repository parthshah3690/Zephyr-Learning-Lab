#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(system_manager);

void system_manager_init(void)
{
    LOG_INF("System initialization started");
    LOG_DBG("Checking hardware configuration");
    LOG_INF("System initialization completed");
}