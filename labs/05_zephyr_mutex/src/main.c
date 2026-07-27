#include "common.h"
#include <zephyr/kernel/thread.h>

LOG_MODULE_REGISTER(main);

#define THREAD_STACK_SIZE 1024

#if defined (CONFIG_THREAD_STACK_INFO) && defined (CONFIG_THREAD_ANALYZER)
#define STACK_THREAD_PRIORITY 10
#endif
#define POWER_THREAD_PRIORITY 5
#define SYSTEM_THREAD_PRIORITY 4
#define SENSOR_THREAD_PRIORITY 3
#define COMM_THREAD_PRIORITY 2

#if defined (CONFIG_THREAD_STACK_INFO) && defined (CONFIG_THREAD_ANALYZER)
K_THREAD_STACK_DEFINE(stackmon_stack, THREAD_STACK_SIZE);
#endif
K_THREAD_STACK_DEFINE(power_stack, THREAD_STACK_SIZE);
K_THREAD_STACK_DEFINE(system_stack, THREAD_STACK_SIZE);
K_THREAD_STACK_DEFINE(sensor_stack, THREAD_STACK_SIZE);
K_THREAD_STACK_DEFINE(comm_stack, THREAD_STACK_SIZE);

// create thread data
static struct k_thread stack_thread_data;
static struct k_thread power_thread_data;
static struct k_thread system_thread_data;
static struct k_thread sensor_thread_data;
static struct k_thread comm_thread_data;
static struct k_thread comm_thread_data;

#if defined (CONFIG_THREAD_STACK_INFO) && defined (CONFIG_THREAD_ANALYZER)
static void stack_mon_thread(void* p1, void* p2, void* p3)
{
    while (true)
    {
        LOG_INF("Checking Stack size for all running threads...");
        size_t unused;
        k_thread_stack_space_get(&sensor_thread_data, &unused);
        if (unused <= ((THREAD_STACK_SIZE * 20) / 100))
        {
            LOG_WRN ("Stack size of Sensor Manager thread used over 80%%. Left: %d", unused);
        }

        k_thread_stack_space_get(&comm_thread_data, &unused);
        if (unused <= ((THREAD_STACK_SIZE * 20) / 100))
        {
            LOG_WRN ("Stack size of Comm Manager thread used over 80%%. Left: %d", unused);
        }

        k_thread_stack_space_get(&system_thread_data, &unused);
        if (unused <= ((THREAD_STACK_SIZE * 20) / 100))
        {
            LOG_WRN ("Stack size of System Manager thread used over 80%%. Left: %d", unused);
        }

        k_thread_stack_space_get(&power_thread_data, &unused);
        if (unused <= ((THREAD_STACK_SIZE * 20) / 100))
        {
            LOG_WRN ("Stack size of Power Manager thread used over 80%%. Left: %d", unused);
        }

        k_sleep(K_SECONDS(60));
    }
}
#endif

void create_all_threads(void)
{
    LOG_INF("Creating Threads...");

    // Create Sensor thread with priority 3
    k_thread_create(&sensor_thread_data, sensor_stack, THREAD_STACK_SIZE, sensor_manager_thread, NULL, NULL, NULL, SENSOR_THREAD_PRIORITY, 0, K_NO_WAIT);
    k_thread_name_set(&sensor_thread_data, "SensorManager");

    // Create communication thread with priority 2
    k_thread_create(&comm_thread_data, comm_stack, THREAD_STACK_SIZE, comm_manager_thread, NULL, NULL, NULL, COMM_THREAD_PRIORITY, 0, K_NO_WAIT);
    k_thread_name_set(&sensor_thread_data, "CommManager");

    // Create System manager thread with priority 4
    k_thread_create(&system_thread_data, system_stack, THREAD_STACK_SIZE, system_manager_thread, NULL, NULL, NULL, SYSTEM_THREAD_PRIORITY, 0, K_NO_WAIT);
    k_thread_name_set(&sensor_thread_data, "SystemManager");

    // Create Power manager thread with priority 5
    k_thread_create(&power_thread_data, power_stack, THREAD_STACK_SIZE, power_manager_thread, NULL, NULL, NULL, POWER_THREAD_PRIORITY, 0, K_NO_WAIT);
    k_thread_name_set(&sensor_thread_data, "PowerManager");

    #if defined (CONFIG_THREAD_STACK_INFO) && defined (CONFIG_THREAD_ANALYZER)
    // Create Stack monitoring thread with priority 10
    k_thread_create(&stack_thread_data, stackmon_stack, THREAD_STACK_SIZE, stack_mon_thread, NULL, NULL, NULL, STACK_THREAD_PRIORITY, 0, K_NO_WAIT);
    k_thread_name_set(&sensor_thread_data, "PowerManager");
    #endif

}

int main(void)
{
    power_manager_init();
    system_manager_init();

    create_all_threads();

    while (true)
    {
        k_sleep(K_FOREVER);
    }
    return 0;
}