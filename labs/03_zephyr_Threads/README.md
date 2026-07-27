# Lab 03 - Zephyr Threads & Scheduling

## Objective

Learn how to create, configure, and manage multiple threads in Zephyr RTOS.

This lab transforms a sequential application into a multi-threaded RTOS application where independent software components execute concurrently under the control of the Zephyr scheduler.

## Concepts

- Threads
- Thread Scheduling

## Build

west build -b qemu_cortex_m3 -p always .

## Run

west build -t run

## Expected Output

```text
*** Booting Zephyr OS build v4.4.0-8172-g1c2bf123944d ***
[00:00:00.000,000] <inf> power_manager: Power management initialized
[00:00:00.000,000] <inf> system_manager: System initialization started
[00:00:00.000,000] <inf> system_manager: System initialization completed
[00:00:00.000,000] <inf> main: Creating Threads...
[00:00:00.000,000] <inf> comm_manager: Communication status OK
[00:00:00.000,000] <inf> sensor_manager: Temperature value : 25 degC
[00:00:00.000,000] <inf> system_manager: System health check running...
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
[00:00:20.020,000] <inf> power_manager: Power state : IDLE
[00:00:20.040,000] <inf> system_manager: System health check running...
[00:00:20.200,000] <inf> sensor_manager: Temperature value : 45 degC
[00:00:21.070,000] <inf> comm_manager: Communication status OK
[00:00:21.210,000] <inf> sensor_manager: Temperature value : 46 degC
[00:00:22.220,000] <inf> sensor_manager: Temperature value : 47 degC
[00:00:23.230,000] <inf> sensor_manager: Temperature value : 48 degC
[00:00:24.080,000] <inf> comm_manager: Communication status OK
[00:00:24.240,000] <inf> sensor_manager: Temperature value : 49 degC
[00:00:25.050,000] <inf> system_manager: System health check running...
[00:00:25.250,000] <inf> sensor_manager: Temperature value : 50 degC
[00:00:26.260,000] <inf> sensor_manager: Temperature value : 51 degC
[00:00:27.090,000] <inf> comm_manager: Communication status OK
```