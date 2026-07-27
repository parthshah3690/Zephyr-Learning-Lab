#ifndef _COMM_MANAGER_H_
#define _COMM_MANAGER_H_

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

extern void comm_manager_thread(void* p1, void* p2, void* p3);

#endif // _COMM_MANAGER_H_