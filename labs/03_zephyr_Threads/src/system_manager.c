#include "system_manager.h"

LOG_MODULE_REGISTER(system_manager);

void system_manager_init(void)
{
    LOG_INF("System initialization started");
    LOG_DBG("Checking hardware configuration");
    LOG_INF("System initialization completed");
}

void system_manager_thread(void* p1, void* p2, void* p3)
{
    ARG_UNUSED(p1);
    ARG_UNUSED(p2);
    ARG_UNUSED(p3);

    while(true)
    {
        LOG_INF("System health check running...");
        k_sleep(K_SECONDS(5));
    }
}