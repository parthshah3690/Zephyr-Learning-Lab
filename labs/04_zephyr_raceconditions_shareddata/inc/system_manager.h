#ifndef _SYSTEM_MANAGER_H_
#define _SYSTEM_MANAGER_H_

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

typedef struct 
{
    int32_t temperature;
    uint32_t vehicle_speed;
    bool communication_ok;
}system_status_t;

extern system_status_t system_status;

extern void system_manager_init(void);
extern void system_manager_thread(void* p1, void* p2, void* p3);

#endif // _SYSTEM_MANAGER_H_