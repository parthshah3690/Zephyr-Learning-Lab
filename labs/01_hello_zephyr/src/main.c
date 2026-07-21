#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);

static const int32_t SLEEP_DELAY_MS = 5000U; // sleep for 5000ms

int main(void)
{
    LOG_INF("Hello Zephyr Learning Lab!");

    while (true)
    {
        LOG_INF("Zephyr is running...");
        (void) k_msleep(SLEEP_DELAY_MS);
    }
    return 0;
}