#ifndef _SYSTEM_MANAGER_H_
#define _SYSTEM_MANAGER_H_

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

extern void system_manager_init(void);
extern void system_manager_thread(void* p1, void* p2, void* p3);

#endif // _SYSTEM_MANAGER_H_