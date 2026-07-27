
# Lab 05 - Zephyr Mutex

## Objective

Learn how to protect shared resources using a **Zephyr Mutex**.
This lab extends **Lab 04** by eliminating race conditions when multiple threads access the shared system status.

## Concepts

### Mutex

A mutex (Mutual Exclusion) is a synchronization primitive that ensures exclusive access to a shared resource.
Only one thread may own a mutex at any given time.

### Critical Section

A critical section is the portion of code that accesses shared data and must not be executed concurrently by multiple threads.
Keep critical sections as short as possible to improve system responsiveness.

---

### Data Ownership

The shared `system_status` structure is owned by the System Manager module.
Application threads communicate with the System Manager through public APIs instead of directly modifying shared data.
This improves software modularity and reduces coupling.

# Application Architecture

```text
                    Zephyr Scheduler

                          |
        -----------------------------------------
        |                  |                    |
        v                  v                    v

 Sensor Thread     Communication Thread   Power Manager Thread

        |                  |                    |
        +------------------+--------------------+
                           |
                    System Manager
                           |
                     +-------------+
                     |   Mutex     |
                     +-------------+
                           |
                    system_status
```

---

## Build

west build -b qemu_cortex_m3 -p always .

## Run

west build -t run

## Expected Output

*** Booting Zephyr OS build v4.4.0-8172-g1c2bf123944d ***
[00:00:00.000,000] <inf> power_manager: Power management initialized
[00:00:00.000,000] <inf> system_manager: System initialization started
[00:00:00.000,000] <inf> system_manager: System initialization completed
[00:00:00.000,000] <inf> main: Creating Threads...
[00:00:00.000,000] <inf> comm_manager: Communication status OK
[00:00:00.000,000] <inf> sensor_manager: Temperature value : 25 degC
[00:00:00.000,000] <inf> system_manager: System health check running...
[00:00:00.000,000] <inf> power_manager: Reading system status...
[00:00:00.000,000] <inf> power_manager: Temperature : 26, Vehicle Speed : 0, Communication : OK
[00:00:00.000,000] <inf> power_manager: Power state : INIT
[00:00:00.000,000] <inf> main: Checking Stack size for all running threads...
[00:00:01.010,000] <inf> sensor_manager: Temperature value : 26 degC
[00:00:02.020,000] <inf> sensor_manager: Temperature value : 27 degC
[00:00:03.010,000] <inf> comm_manager: Communication status OK
[00:00:03.030,000] <inf> sensor_manager: Temperature value : 28 degC
[00:00:04.040,000] <inf> sensor_manager: Temperature value : 29 degC
[00:00:05.010,000] <inf> system_manager: System health check running...
[00:00:05.050,000] <inf> sensor_manager: Temperature value : 30 degC
[00:00:06.020,000] <inf> comm_manager: Communication status OK
[00:00:06.060,000] <inf> sensor_manager: Temperature value : 31 degC
[00:00:07.070,000] <inf> sensor_manager: Temperature value : 32 degC
[00:00:08.080,000] <inf> sensor_manager: Temperature value : 33 degC
[00:00:09.030,000] <inf> comm_manager: Communication status OK
[00:00:09.090,000] <inf> sensor_manager: Temperature value : 34 degC
[00:00:10.010,000] <inf> power_manager: Reading system status...
[00:00:10.010,000] <inf> power_manager: Temperature : 35, Vehicle Speed : 0, Communication : OK
[00:00:10.010,000] <inf> power_manager: Power state : ACTIVE
[00:00:10.020,000] <inf> system_manager: System health check running...
[00:00:10.100,000] <inf> sensor_manager: Temperature value : 35 degC
[00:00:11.110,000] <inf> sensor_manager: Temperature value : 36 degC
[00:00:12.040,000] <inf> comm_manager: Communication status OK
[00:00:12.120,000] <inf> sensor_manager: Temperature value : 37 degC
[00:00:13.130,000] <inf> sensor_manager: Temperature value : 38 degC
[00:00:14.140,000] <inf> sensor_manager: Temperature value : 39 degC
[00:00:15.030,000] <inf> system_manager: System health check running...
[00:00:15.050,000] <inf> comm_manager: Communication status OK
[00:00:15.150,000] <inf> sensor_manager: Temperature value : 40 degC
[00:00:16.160,000] <inf> sensor_manager: Temperature value : 41 degC
[00:00:17.170,000] <inf> sensor_manager: Temperature value : 42 degC
[00:00:18.060,000] <inf> comm_manager: Communication status OK
[00:00:18.180,000] <inf> sensor_manager: Temperature value : 43 degC
[00:00:19.190,000] <inf> sensor_manager: Temperature value : 44 degC
[00:00:20.020,000] <inf> power_manager: Reading system status...
[00:00:20.020,000] <inf> power_manager: Temperature : 45, Vehicle Speed : 0, Communication : OK
[00:00:20.020,000] <inf> power_manager: Power state : ACTIVE