#include "system_manager.h"

LOG_MODULE_REGISTER(system_manager);

static system_status_t system_status =
{
    .temperature = 25,
    .vehicle_speed = 0,
    .communication_ok = false
};

// Create MUTEX
static struct k_mutex system_manager_mutex;

void system_manager_init(void)
{
    LOG_INF("System initialization started");
    LOG_DBG("Checking hardware configuration");
    LOG_INF("System initialization completed");

    // initialize mutex
    (void) k_mutex_init(&system_manager_mutex);
}

void system_manager_set_temperature(int32_t temperature)
{
    (void) k_mutex_lock(&system_manager_mutex, K_FOREVER);
    system_status.temperature = temperature;
    (void) k_mutex_unlock(&system_manager_mutex);

}

void system_manager_set_communication_status(bool communication_ok)
{
    (void) k_mutex_lock(&system_manager_mutex, K_FOREVER);
    system_status.communication_ok = communication_ok;
    (void) k_mutex_unlock(&system_manager_mutex);
}

system_status_t system_manager_get_system_status(void)
{
    system_status_t local_system_status;

    (void) k_mutex_lock(&system_manager_mutex, K_FOREVER);
    local_system_status = system_status;
    (void) k_mutex_unlock(&system_manager_mutex);

    return local_system_status;
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