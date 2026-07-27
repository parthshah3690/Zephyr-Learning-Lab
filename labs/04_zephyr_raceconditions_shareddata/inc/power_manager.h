#ifndef _POWER_MANAGER_H_
#define _POWER_MANAGER_H_

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

extern void power_manager_init(void);
extern void power_manager_thread(void* p1, void* p2, void* p3);

#endif // _POWER_MANAGER_H_