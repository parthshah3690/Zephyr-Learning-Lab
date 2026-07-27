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

// Create Semaphore
struct k_sem system_status_update_sem;

void system_manager_init(void)
{
    LOG_INF("System initialization started");
    LOG_DBG("Checking hardware configuration");
    LOG_INF("System initialization completed");

    // initialize mutex
    (void) k_mutex_init(&system_manager_mutex);

    // initialize semaphore
    (void) k_sem_init(&system_status_update_sem, 0, 1);
}

void system_manager_set_temperature(int32_t temperature)
{
    bool changed = false;

    (void) k_mutex_lock(&system_manager_mutex, K_FOREVER);
    if (system_status.temperature != temperature)
    {
        system_status.temperature = temperature;
        changed = true;
    }
    (void) k_mutex_unlock(&system_manager_mutex);

    if (changed)
    {
        (void) k_sem_give(&system_status_update_sem);
    }
}

void system_manager_set_communication_status(bool communication_ok)
{
    bool changed = false;

    (void) k_mutex_lock(&system_manager_mutex, K_FOREVER);
    if (system_status.communication_ok != communication_ok)
    {
        system_status.communication_ok = communication_ok;
        changed = true;
    }
    (void) k_mutex_unlock(&system_manager_mutex);

    if (changed)
    {
        (void) k_sem_give(&system_status_update_sem);
    }
}

system_status_t system_manager_get_system_status(void)
{
    system_status_t local_system_status;

    (void) k_mutex_lock(&system_manager_mutex, K_FOREVER);
    local_system_status = system_status;
    (void) k_mutex_unlock(&system_manager_mutex);

    return local_system_status;
}

void system_manager_wait_for_an_update(void)
{
    (void) k_sem_take(&system_status_update_sem, K_FOREVER);
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