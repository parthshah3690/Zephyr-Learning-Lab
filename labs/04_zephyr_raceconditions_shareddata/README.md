<<<<<<< HEAD
# Lab 04 - Zephyr Race Conditions & Shared Data
=======
# Lab 03 - Zephyr Race Conditions & Shared Data
>>>>>>> ade9cf5a950c0eca345bcf70a6bcb47dc43569e4

## Objective

Understand how race conditions occur in a multi-threaded RTOS application when multiple threads access shared data without any synchronization mechanism.

This lab intentionally demonstrates an unsafe design that will be improved in subsequent labs using mutexes, semaphores, events, and message queues.

## Concepts

- Race Conditions
- Shared Data

# Application Architecture

```text
                    Zephyr Scheduler

                          |
        -----------------------------------------
        |                  |                    |
        v                  v                    v

 Sensor Thread     Communication Thread   Power Manager Thread

        |                  |                    |
        |                  |                    |
        +------------------+--------------------+

                           |

                           v

                    system_status

              (Shared Memory - Unsafe)

## Build

west build -b qemu_cortex_m3 -p always .

## Run

west build -t run

## Expected Output

*** Booting Zephyr ***

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
[00:00:27.270,000] <inf> sensor_manager: Temperature value : 52 degC
[00:00:28.280,000] <inf> sensor_manager: Temperature value : 53 degC
[00:00:29.290,000] <inf> sensor_manager: Temperature value : 54 degC
[00:00:30.030,000] <inf> power_manager: Reading system status...
[00:00:30.030,000] <inf> power_manager: Temperature : 55, Vehicle Speed : 0, Communication : OK
[00:00:30.030,000] <inf> power_manager: Power state : ACTIVE
[00:00:30.060,000] <inf> system_manager: System health check running...
[00:00:30.100,000] <inf> comm_manager: Communication status OK
[00:00:30.300,000] <inf> sensor_manager: Temperature value : 55 degC
[00:00:31.310,000] <inf> sensor_manager: Temperature value : 56 degC
[00:00:32.320,000] <inf> sensor_manager: Temperature value : 57 degC
[00:00:33.110,000] <inf> comm_manager: Communication status OK
[00:00:33.330,000] <inf> sensor_manager: Temperature value : 58 degC
[00:00:34.340,000] <inf> sensor_manager: Temperature value : 59 degC
[00:00:35.070,000] <inf> system_manager: System health check running...
[00:00:35.350,000] <inf> sensor_manager: Temperature value : 60 degC
[00:00:36.120,000] <inf> comm_manager: Communication status OK
[00:00:36.360,000] <inf> sensor_manager: Temperature value : 61 degC
[00:00:37.370,000] <inf> sensor_manager: Temperature value : 62 degC
[00:00:38.380,000] <inf> sensor_manager: Temperature value : 63 degC
[00:00:39.130,000] <inf> comm_manager: Communication status OK
[00:00:39.390,000] <inf> sensor_manager: Temperature value : 64 degC
[00:00:40.040,000] <inf> power_manager: Reading system status...
[00:00:40.040,000] <inf> power_manager: Temperature : 65, Vehicle Speed : 0, Communication : OK
[00:00:40.040,000] <inf> power_manager: Power state : ACTIVE
[00:00:40.080,000] <inf> system_manager: System health check running...
[00:00:40.400,000] <inf> sensor_manager: Temperature value : 65 degC
[00:00:41.410,000] <inf> sensor_manager: Temperature value : 66 degC
[00:00:42.140,000] <inf> comm_manager: Communication status OK
[00:00:42.420,000] <inf> sensor_manager: Temperature value : 67 degC
[00:00:43.430,000] <inf> sensor_manager: Temperature value : 68 degC
[00:00:44.440,000] <inf> sensor_manager: Temperature value : 69 degC
[00:00:45.090,000] <inf> system_manager: System health check running...
[00:00:45.150,000] <inf> comm_manager: Communication status OK
[00:00:45.450,000] <inf> sensor_manager: Temperature value : 70 degC
[00:00:46.460,000] <inf> sensor_manager: Temperature value : 71 degC
[00:00:47.470,000] <inf> sensor_manager: Temperature value : 72 degC
[00:00:48.160,000] <inf> comm_manager: Communication status OK
[00:00:48.480,000] <inf> sensor_manager: Temperature value : 73 degC
[00:00:49.490,000] <inf> sensor_manager: Temperature value : 74 degC
[00:00:50.050,000] <inf> power_manager: Reading system status...
[00:00:50.050,000] <inf> power_manager: Temperature : 75, Vehicle Speed : 0, Communication : OK
[00:00:50.050,000] <inf> power_manager: Power state : ACTIVE
[00:00:50.100,000] <inf> system_manager: System health check running...
[00:00:50.500,000] <inf> sensor_manager: Temperature value : 75 degC
[00:00:51.170,000] <inf> comm_manager: Communication status OK
[00:00:51.510,000] <inf> sensor_manager: Temperature value : 76 degC
[00:00:52.520,000] <inf> sensor_manager: Temperature value : 77 degC
[00:00:53.530,000] <inf> sensor_manager: Temperature value : 78 degC
[00:00:54.180,000] <inf> comm_manager: Communication status OK
[00:00:54.540,000] <inf> sensor_manager: Temperature value : 79 degC
[00:00:55.110,000] <inf> system_manager: System health check running...
[00:00:55.550,000] <inf> sensor_manager: Temperature value : 80 degC
[00:00:56.560,000] <inf> sensor_manager: Temperature value : 81 degC
[00:00:57.190,000] <inf> comm_manager: Communication status OK
[00:00:57.570,000] <inf> sensor_manager: Temperature value : 82 degC
[00:00:58.580,000] <inf> sensor_manager: Temperature value : 83 degC
[00:00:59.590,000] <inf> sensor_manager: Temperature value : 84 degC
[00:01:00.010,000] <inf> main: Checking Stack size for all running threads...
[00:01:00.060,000] <inf> power_manager: Reading system status...
[00:01:00.060,000] <inf> power_manager: Temperature : 85, Vehicle Speed : 0, Communication : OK
[00:01:00.060,000] <inf> power_manager: Power state : ACTIVE
[00:01:00.060,000] <wrn> power_manager: High temperature detected
[00:01:00.120,000] <inf> system_manager: System health check running...
[00:01:00.200,000] <inf> comm_manager: Communication status OK
[00:01:00.600,000] <inf> sensor_manager: Temperature value : 85 degC
[00:01:01.610,000] <inf> sensor_manager: Temperature value : 86 degC
[00:01:02.620,000] <inf> sensor_manager: Temperature value : 87 degC
[00:01:03.210,000] <inf> comm_manager: Communication status OK
[00:01:03.630,000] <inf> sensor_manager: Temperature value : 88 degC
[00:01:04.640,000] <inf> sensor_manager: Temperature value : 89 degC
[00:01:05.130,000] <inf> system_manager: System health check running...
[00:01:05.650,000] <inf> sensor_manager: Temperature value : 90 degC
[00:01:06.220,000] <inf> comm_manager: Communication status OK
[00:01:06.660,000] <inf> sensor_manager: Temperature value : 91 degC
[00:01:07.670,000] <inf> sensor_manager: Temperature value : 92 degC
[00:01:08.680,000] <inf> sensor_manager: Temperature value : 93 degC
[00:01:09.230,000] <inf> comm_manager: Communication status OK
[00:01:09.690,000] <inf> sensor_manager: Temperature value : 94 degC