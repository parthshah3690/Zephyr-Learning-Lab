#include "comm_manager.h"
#include "system_manager.h"

LOG_MODULE_REGISTER(comm_manager);

void comm_manager_thread(void* p1, void* p2, void* p3)
{
    ARG_UNUSED(p1);
    ARG_UNUSED(p2);
    ARG_UNUSED(p3);

    while (true) 
    {
        LOG_INF("Communication status OK");
        system_manager_set_communication_status(true);
        k_sleep(K_SECONDS(3));
    }
}