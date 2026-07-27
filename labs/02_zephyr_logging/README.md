# Lab 02 - Zephyr Logging Framework

## Objective

Understand Zephyr application structure and build system.

## Concepts

- west
- CMake
- prj.conf
- Logging

## Build

west build -b qemu_cortex_m3 -p always .

## Run

west build -t run

## Expected Output
```text
*** Booting Zephyr OS build v4.4.0-8172-g1c2bf123944d ***
[00:00:00.000,000] <inf> main: Zephyr Logging started!
[00:00:00.000,000] <inf> system_manager: System initialization started
[00:00:00.000,000] <inf> system_manager: System initialization completed
[00:00:00.000,000] <inf> sensor_manager: Temperature value : 25 degC
[00:00:00.000,000] <inf> communication_manager: Communication cycle 1
[00:00:01.010,000] <inf> sensor_manager: Temperature value : 26 degC
[00:00:01.010,000] <inf> communication_manager: Communication cycle 2
[00:00:02.020,000] <inf> sensor_manager: Temperature value : 27 degC
[00:00:02.020,000] <inf> communication_manager: Communication cycle 3
[00:00:03.030,000] <inf> sensor_manager: Temperature value : 28 degC
[00:00:03.030,000] <inf> communication_manager: Communication cycle 4
[00:00:04.040,000] <inf> sensor_manager: Temperature value : 29 degC
[00:00:04.040,000] <inf> communication_manager: Communication cycle 5
[00:00:04.040,000] <err> communication_manager: Communication timeout detected
[00:00:05.050,000] <inf> sensor_manager: Temperature value : 30 degC
[00:00:05.050,000] <inf> communication_manager: Communication cycle 6
[00:00:06.060,000] <inf> sensor_manager: Temperature value : 31 degC
[00:00:06.060,000] <wrn> sensor_manager: Temperature is high
[00:00:06.060,000] <inf> communication_manager: Communication cycle 7
[00:00:07.070,000] <inf> sensor_manager: Temperature value : 32 degC
[00:00:07.070,000] <wrn> sensor_manager: Temperature is high
[00:00:07.070,000] <inf> communication_manager: Communication cycle 8
[00:00:08.080,000] <inf> sensor_manager: Temperature value : 33 degC
[00:00:08.080,000] <wrn> sensor_manager: Temperature is high
[00:00:08.080,000] <inf> communication_manager: Communication cycle 9
[00:00:09.090,000] <inf> sensor_manager: Temperature value : 34 degC
[00:00:09.090,000] <wrn> sensor_manager: Temperature is high
[00:00:09.090,000] <inf> communication_manager: Communication cycle 10
[00:00:09.090,000] <err> communication_manager: Communication timeout detected
[00:00:10.100,000] <inf> sensor_manager: Temperature value : 35 degC
[00:00:10.100,000] <wrn> sensor_manager: Temperature is high
[00:00:10.100,000] <inf> communication_manager: Communication cycle 11
[00:00:11.110,000] <inf> sensor_manager: Temperature value : 36 degC
[00:00:11.110,000] <wrn> sensor_manager: Temperature is high
[00:00:11.110,000] <inf> communication_manager: Communication cycle 12
[00:00:12.120,000] <inf> sensor_manager: Temperature value : 37 degC
[00:00:12.120,000] <wrn> sensor_manager: Temperature is high
[00:00:12.120,000] <inf> communication_manager: Communication cycle 13
[00:00:13.130,000] <inf> sensor_manager: Temperature value : 38 degC
[00:00:13.130,000] <wrn> sensor_manager: Temperature is high
[00:00:13.130,000] <inf> communication_manager: Communication cycle 14
[00:00:14.140,000] <inf> sensor_manager: Temperature value : 39 degC
[00:00:14.140,000] <wrn> sensor_manager: Temperature is high
[00:00:14.140,000] <inf> communication_manager: Communication cycle 15
[00:00:14.140,000] <err> communication_manager: Communication timeout detected
[00:00:15.150,000] <inf> sensor_manager: Temperature value : 40 degC
[00:00:15.150,000] <wrn> sensor_manager: Temperature is high
[00:00:15.150,000] <inf> communication_manager: Communication cycle 16
[00:00:16.160,000] <inf> sensor_manager: Temperature value : 41 degC
[00:00:16.160,000] <wrn> sensor_manager: Temperature is high
[00:00:16.160,000] <inf> communication_manager: Communication cycle 17
[00:00:17.170,000] <inf> sensor_manager: Temperature value : 42 degC
[00:00:17.170,000] <wrn> sensor_manager: Temperature is high
[00:00:17.170,000] <inf> communication_manager: Communication cycle 18
[00:00:18.180,000] <inf> sensor_manager: Temperature value : 43 degC
[00:00:18.180,000] <wrn> sensor_manager: Temperature is high
[00:00:18.180,000] <inf> communication_manager: Communication cycle 19
[00:00:19.190,000] <inf> sensor_manager: Temperature value : 44 degC
[00:00:19.190,000] <wrn> sensor_manager: Temperature is high
[00:00:19.190,000] <inf> communication_manager: Communication cycle 20
[00:00:19.190,000] <err> communication_manager: Communication timeout detected
[00:00:20.200,000] <inf> sensor_manager: Temperature value : 45 degC
[00:00:20.200,000] <wrn> sensor_manager: Temperature is high
[00:00:20.200,000] <inf> communication_manager: Communication cycle 21
[00:00:21.210,000] <inf> sensor_manager: Temperature value : 46 degC
[00:00:21.210,000] <wrn> sensor_manager: Temperature is high
[00:00:21.210,000] <inf> communication_manager: Communication cycle 22
[00:00:22.220,000] <inf> sensor_manager: Temperature value : 47 degC
[00:00:22.220,000] <wrn> sensor_manager: Temperature is high
[00:00:22.220,000] <inf> communication_manager: Communication cycle 23
[00:00:23.230,000] <inf> sensor_manager: Temperature value : 48 degC
[00:00:23.230,000] <wrn> sensor_manager: Temperature is high
[00:00:23.230,000] <inf> communication_manager: Communication cycle 24
[00:00:24.240,000] <inf> sensor_manager: Temperature value : 49 degC
[00:00:24.240,000] <wrn> sensor_manager: Temperature is high
[00:00:24.240,000] <inf> communication_manager: Communication cycle 25
[00:00:24.240,000] <err> communication_manager: Communication timeout detected
[00:00:25.250,000] <inf> sensor_manager: Temperature value : 50 degC
[00:00:25.250,000] <wrn> sensor_manager: Temperature is high
[00:00:25.250,000] <inf> communication_manager: Communication cycle 26
[00:00:26.260,000] <inf> sensor_manager: Temperature value : 51 degC
[00:00:26.260,000] <wrn> sensor_manager: Temperature is high
[00:00:26.260,000] <inf> communication_manager: Communication cycle 27
[00:00:27.270,000] <inf> sensor_manager: Temperature value : 52 degC
[00:00:27.270,000] <wrn> sensor_manager: Temperature is high
[00:00:27.270,000] <inf> communication_manager: Communication cycle 28
[00:00:28.280,000] <inf> sensor_manager: Temperature value : 53 degC
[00:00:28.280,000] <wrn> sensor_manager: Temperature is high
[00:00:28.280,000] <inf> communication_manager: Communication cycle 29
[00:00:29.290,000] <inf> sensor_manager: Temperature value : 54 degC
[00:00:29.290,000] <wrn> sensor_manager: Temperature is high
[00:00:29.290,000] <inf> communication_manager: Communication cycle 30
[00:00:29.290,000] <err> communication_manager: Communication timeout detected
[00:00:30.300,000] <inf> sensor_manager: Temperature value : 55 degC
[00:00:30.300,000] <wrn> sensor_manager: Temperature is high
[00:00:30.300,000] <inf> communication_manager: Communication cycle 31
[00:00:31.310,000] <inf> sensor_manager: Temperature value : 56 degC
[00:00:31.310,000] <wrn> sensor_manager: Temperature is high
[00:00:31.310,000] <inf> communication_manager: Communication cycle 32
[00:00:32.320,000] <inf> sensor_manager: Temperature value : 57 degC
[00:00:32.320,000] <wrn> sensor_manager: Temperature is high
[00:00:32.320,000] <inf> communication_manager: Communication cycle 33
[00:00:33.330,000] <inf> sensor_manager: Temperature value : 58 degC
[00:00:33.330,000] <wrn> sensor_manager: Temperature is high
[00:00:33.330,000] <inf> communication_manager: Communication cycle 34
[00:00:34.340,000] <inf> sensor_manager: Temperature value : 59 degC
[00:00:34.340,000] <wrn> sensor_manager: Temperature is high
[00:00:34.340,000] <inf> communication_manager: Communication cycle 35
[00:00:34.340,000] <err> communication_manager: Communication timeout detected
[00:00:35.350,000] <inf> sensor_manager: Temperature value : 60 degC
[00:00:35.350,000] <wrn> sensor_manager: Temperature is high
[00:00:35.350,000] <inf> communication_manager: Communication cycle 36
[00:00:36.360,000] <inf> sensor_manager: Temperature value : 61 degC
[00:00:36.360,000] <wrn> sensor_manager: Temperature is high
[00:00:36.360,000] <inf> communication_manager: Communication cycle 37
[00:00:37.370,000] <inf> sensor_manager: Temperature value : 62 degC
[00:00:37.370,000] <wrn> sensor_manager: Temperature is high
[00:00:37.370,000] <inf> communication_manager: Communication cycle 38
[00:00:38.380,000] <inf> sensor_manager: Temperature value : 63 degC
[00:00:38.380,000] <wrn> sensor_manager: Temperature is high
[00:00:38.380,000] <inf> communication_manager: Communication cycle 39
[00:00:39.390,000] <inf> sensor_manager: Temperature value : 64 degC
[00:00:39.390,000] <wrn> sensor_manager: Temperature is high
[00:00:39.390,000] <inf> communication_manager: Communication cycle 40
[00:00:39.390,000] <err> communication_manager: Communication timeout detected
[00:00:40.400,000] <inf> sensor_manager: Temperature value : 65 degC
[00:00:40.400,000] <wrn> sensor_manager: Temperature is high
[00:00:40.400,000] <inf> communication_manager: Communication cycle 41
[00:00:41.410,000] <inf> sensor_manager: Temperature value : 66 degC
[00:00:41.410,000] <wrn> sensor_manager: Temperature is high
[00:00:41.410,000] <inf> communication_manager: Communication cycle 42
[00:00:42.420,000] <inf> sensor_manager: Temperature value : 67 degC
[00:00:42.420,000] <wrn> sensor_manager: Temperature is high
[00:00:42.420,000] <inf> communication_manager: Communication cycle 43
[00:00:43.430,000] <inf> sensor_manager: Temperature value : 68 degC
[00:00:43.430,000] <wrn> sensor_manager: Temperature is high
[00:00:43.430,000] <inf> communication_manager: Communication cycle 44
[00:00:44.440,000] <inf> sensor_manager: Temperature value : 69 degC
[00:00:44.440,000] <wrn> sensor_manager: Temperature is high
[00:00:44.440,000] <inf> communication_manager: Communication cycle 45
[00:00:44.440,000] <err> communication_manager: Communication timeout detected
[00:00:45.450,000] <inf> sensor_manager: Temperature value : 70 degC
[00:00:45.450,000] <wrn> sensor_manager: Temperature is high
[00:00:45.450,000] <inf> communication_manager: Communication cycle 46
[00:00:46.460,000] <inf> sensor_manager: Temperature value : 71 degC
[00:00:46.460,000] <wrn> sensor_manager: Temperature is high
[00:00:46.460,000] <inf> communication_manager: Communication cycle 47
[00:00:47.470,000] <inf> sensor_manager: Temperature value : 72 degC
[00:00:47.470,000] <wrn> sensor_manager: Temperature is high
[00:00:47.470,000] <inf> communication_manager: Communication cycle 48
[00:00:48.480,000] <inf> sensor_manager: Temperature value : 73 degC
[00:00:48.480,000] <wrn> sensor_manager: Temperature is high
[00:00:48.480,000] <inf> communication_manager: Communication cycle 49
[00:00:49.490,000] <inf> sensor_manager: Temperature value : 74 degC
[00:00:49.490,000] <wrn> sensor_manager: Temperature is high
[00:00:49.490,000] <inf> communication_manager: Communication cycle 50
[00:00:49.490,000] <err> communication_manager: Communication timeout detected
[00:00:50.500,000] <inf> sensor_manager: Temperature value : 75 degC
[00:00:50.500,000] <wrn> sensor_manager: Temperature is high
[00:00:50.500,000] <inf> communication_manager: Communication cycle 51
[00:00:51.510,000] <inf> sensor_manager: Temperature value : 76 degC
[00:00:51.510,000] <wrn> sensor_manager: Temperature is high
[00:00:51.510,000] <inf> communication_manager: Communication cycle 52
[00:00:52.520,000] <inf> sensor_manager: Temperature value : 77 degC
[00:00:52.520,000] <wrn> sensor_manager: Temperature is high
[00:00:52.520,000] <inf> communication_manager: Communication cycle 53
[00:00:53.530,000] <inf> sensor_manager: Temperature value : 78 degC
[00:00:53.530,000] <wrn> sensor_manager: Temperature is high
[00:00:53.530,000] <inf> communication_manager: Communication cycle 54
[00:00:54.540,000] <inf> sensor_manager: Temperature value : 79 degC
[00:00:54.540,000] <wrn> sensor_manager: Temperature is high
[00:00:54.540,000] <inf> communication_manager: Communication cycle 55
[00:00:54.540,000] <err> communication_manager: Communication timeout detected
[00:00:55.550,000] <inf> sensor_manager: Temperature value : 80 degC
[00:00:55.550,000] <wrn> sensor_manager: Temperature is high
[00:00:55.550,000] <inf> communication_manager: Communication cycle 56
[00:00:56.560,000] <inf> sensor_manager: Temperature value : 81 degC
[00:00:56.560,000] <wrn> sensor_manager: Temperature is high
[00:00:56.560,000] <inf> communication_manager: Communication cycle 57
[00:00:57.570,000] <inf> sensor_manager: Temperature value : 82 degC
[00:00:57.570,000] <wrn> sensor_manager: Temperature is high
[00:00:57.570,000] <inf> communication_manager: Communication cycle 58
[00:00:58.580,000] <inf> sensor_manager: Temperature value : 83 degC
[00:00:58.580,000] <wrn> sensor_manager: Temperature is high
[00:00:58.580,000] <inf> communication_manager: Communication cycle 59
[00:00:59.590,000] <inf> sensor_manager: Temperature value : 84 degC
[00:00:59.590,000] <wrn> sensor_manager: Temperature is high
[00:00:59.590,000] <inf> communication_manager: Communication cycle 60
[00:00:59.590,000] <err> communication_manager: Communication timeout detected
[00:01:00.600,000] <inf> sensor_manager: Temperature value : 85 degC
[00:01:00.600,000] <wrn> sensor_manager: Temperature is high
[00:01:00.600,000] <inf> communication_manager: Communication cycle 61
[00:01:01.610,000] <inf> sensor_manager: Temperature value : 86 degC
[00:01:01.610,000] <wrn> sensor_manager: Temperature is high
[00:01:01.610,000] <inf> communication_manager: Communication cycle 62
[00:01:02.620,000] <inf> sensor_manager: Temperature value : 87 degC
[00:01:02.620,000] <wrn> sensor_manager: Temperature is high
[00:01:02.620,000] <inf> communication_manager: Communication cycle 63
[00:01:03.630,000] <inf> sensor_manager: Temperature value : 88 degC
[00:01:03.630,000] <wrn> sensor_manager: Temperature is high
[00:01:03.630,000] <inf> communication_manager: Communication cycle 64
[00:01:04.640,000] <inf> sensor_manager: Temperature value : 89 degC
[00:01:04.640,000] <wrn> sensor_manager: Temperature is high
[00:01:04.640,000] <inf> communication_manager: Communication cycle 65
[00:01:04.640,000] <err> communication_manager: Communication timeout detected
[00:01:05.650,000] <inf> sensor_manager: Temperature value : 90 degC
[00:01:05.650,000] <wrn> sensor_manager: Temperature is high
[00:01:05.650,000] <inf> communication_manager: Communication cycle 66
[00:01:06.660,000] <inf> sensor_manager: Temperature value : 91 degC
[00:01:06.660,000] <wrn> sensor_manager: Temperature is high
[00:01:06.660,000] <inf> communication_manager: Communication cycle 67
[00:01:07.670,000] <inf> sensor_manager: Temperature value : 92 degC
[00:01:07.670,000] <wrn> sensor_manager: Temperature is high
[00:01:07.670,000] <inf> communication_manager: Communication cycle 68
[00:01:08.680,000] <inf> sensor_manager: Temperature value : 93 degC
[00:01:08.680,000] <wrn> sensor_manager: Temperature is high
[00:01:08.680,000] <inf> communication_manager: Communication cycle 69
[00:01:09.690,000] <inf> sensor_manager: Temperature value : 94 degC
[00:01:09.690,000] <wrn> sensor_manager: Temperature is high
[00:01:09.690,000] <inf> communication_manager: Communication cycle 70
[00:01:09.690,000] <err> communication_manager: Communication timeout detected
[00:01:10.700,000] <inf> sensor_manager: Temperature value : 95 degC
[00:01:10.700,000] <wrn> sensor_manager: Temperature is high
[00:01:10.700,000] <inf> communication_manager: Communication cycle 71
[00:01:11.710,000] <inf> sensor_manager: Temperature value : 96 degC
[00:01:11.710,000] <wrn> sensor_manager: Temperature is high
[00:01:11.710,000] <inf> communication_manager: Communication cycle 72
[00:01:12.720,000] <inf> sensor_manager: Temperature value : 97 degC
[00:01:12.720,000] <wrn> sensor_manager: Temperature is high
[00:01:12.720,000] <inf> communication_manager: Communication cycle 73
[00:01:13.730,000] <inf> sensor_manager: Temperature value : 98 degC
[00:01:13.730,000] <wrn> sensor_manager: Temperature is high
[00:01:13.730,000] <inf> communication_manager: Communication cycle 74
[00:01:14.740,000] <inf> sensor_manager: Temperature value : 99 degC
[00:01:14.740,000] <wrn> sensor_manager: Temperature is high
[00:01:14.740,000] <inf> communication_manager: Communication cycle 75
[00:01:14.740,000] <err> communication_manager: Communication timeout detected
[00:01:15.750,000] <inf> sensor_manager: Temperature value : 100 degC
[00:01:15.750,000] <wrn> sensor_manager: Temperature is high
[00:01:15.750,000] <inf> communication_manager: Communication cycle 76
[00:01:16.760,000] <inf> sensor_manager: Temperature value : 101 degC
[00:01:16.760,000] <wrn> sensor_manager: Temperature is high
[00:01:16.760,000] <inf> communication_manager: Communication cycle 77
[00:01:17.770,000] <inf> sensor_manager: Temperature value : 102 degC
[00:01:17.770,000] <wrn> sensor_manager: Temperature is high
[00:01:17.770,000] <inf> communication_manager: Communication cycle 78
[00:01:18.780,000] <inf> sensor_manager: Temperature value : 103 degC
[00:01:18.780,000] <wrn> sensor_manager: Temperature is high
[00:01:18.780,000] <inf> communication_manager: Communication cycle 79
[00:01:19.790,000] <inf> sensor_manager: Temperature value : 104 degC
[00:01:19.790,000] <wrn> sensor_manager: Temperature is high
[00:01:19.790,000] <inf> communication_manager: Communication cycle 80
[00:01:19.790,000] <err> communication_manager: Communication timeout detected
[00:01:20.800,000] <inf> sensor_manager: Temperature value : 105 degC
[00:01:20.800,000] <wrn> sensor_manager: Temperature is high
[00:01:20.800,000] <inf> communication_manager: Communication cycle 81
[00:01:21.810,000] <inf> sensor_manager: Temperature value : 106 degC
[00:01:21.810,000] <wrn> sensor_manager: Temperature is high
[00:01:21.810,000] <inf> communication_manager: Communication cycle 82
[00:01:22.820,000] <inf> sensor_manager: Temperature value : 107 degC
[00:01:22.820,000] <wrn> sensor_manager: Temperature is high
[00:01:22.820,000] <inf> communication_manager: Communication cycle 83
[00:01:23.830,000] <inf> sensor_manager: Temperature value : 108 degC
[00:01:23.830,000] <wrn> sensor_manager: Temperature is high
[00:01:23.830,000] <inf> communication_manager: Communication cycle 84
[00:01:24.840,000] <inf> sensor_manager: Temperature value : 109 degC
[00:01:24.840,000] <wrn> sensor_manager: Temperature is high
[00:01:24.840,000] <inf> communication_manager: Communication cycle 85
[00:01:24.840,000] <err> communication_manager: Communication timeout detected
[00:01:25.850,000] <inf> sensor_manager: Temperature value : 110 degC
[00:01:25.850,000] <wrn> sensor_manager: Temperature is high
[00:01:25.850,000] <inf> communication_manager: Communication cycle 86
[00:01:26.860,000] <inf> sensor_manager: Temperature value : 111 degC
[00:01:26.860,000] <wrn> sensor_manager: Temperature is high
[00:01:26.860,000] <inf> communication_manager: Communication cycle 87
[00:01:27.870,000] <inf> sensor_manager: Temperature value : 112 degC
[00:01:27.870,000] <wrn> sensor_manager: Temperature is high
[00:01:27.870,000] <inf> communication_manager: Communication cycle 88
[00:01:28.880,000] <inf> sensor_manager: Temperature value : 113 degC
[00:01:28.880,000] <wrn> sensor_manager: Temperature is high
[00:01:28.880,000] <inf> communication_manager: Communication cycle 89
[00:01:29.890,000] <inf> sensor_manager: Temperature value : 114 degC
[00:01:29.890,000] <wrn> sensor_manager: Temperature is high
[00:01:29.890,000] <inf> communication_manager: Communication cycle 90
[00:01:29.890,000] <err> communication_manager: Communication timeout detected
[00:01:30.900,000] <inf> sensor_manager: Temperature value : 115 degC
[00:01:30.900,000] <wrn> sensor_manager: Temperature is high
[00:01:30.900,000] <inf> communication_manager: Communication cycle 91
[00:01:31.910,000] <inf> sensor_manager: Temperature value : 116 degC
[00:01:31.910,000] <wrn> sensor_manager: Temperature is high
[00:01:31.910,000] <inf> communication_manager: Communication cycle 92
[00:01:32.920,000] <inf> sensor_manager: Temperature value : 117 degC
[00:01:32.920,000] <wrn> sensor_manager: Temperature is high
[00:01:32.920,000] <inf> communication_manager: Communication cycle 93
[00:01:33.930,000] <inf> sensor_manager: Temperature value : 118 degC
[00:01:33.930,000] <wrn> sensor_manager: Temperature is high
[00:01:33.930,000] <inf> communication_manager: Communication cycle 94
[00:01:34.940,000] <inf> sensor_manager: Temperature value : 119 degC
[00:01:34.940,000] <wrn> sensor_manager: Temperature is high
[00:01:34.940,000] <inf> communication_manager: Communication cycle 95
[00:01:34.940,000] <err> communication_manager: Communication timeout detected
[00:01:35.950,000] <inf> sensor_manager: Temperature value : 120 degC
[00:01:35.950,000] <wrn> sensor_manager: Temperature is high
[00:01:35.950,000] <inf> communication_manager: Communication cycle 96
[00:01:36.960,000] <inf> sensor_manager: Temperature value : 121 degC
[00:01:36.960,000] <wrn> sensor_manager: Temperature is high
[00:01:36.960,000] <inf> communication_manager: Communication cycle 97
[00:01:37.970,000] <inf> sensor_manager: Temperature value : 122 degC
[00:01:37.970,000] <wrn> sensor_manager: Temperature is high
[00:01:37.970,000] <inf> communication_manager: Communication cycle 98
[00:01:38.980,000] <inf> sensor_manager: Temperature value : 123 degC
[00:01:38.980,000] <wrn> sensor_manager: Temperature is high
[00:01:38.980,000] <inf> communication_manager: Communication cycle 99
[00:01:39.990,000] <inf> sensor_manager: Temperature value : 124 degC
[00:01:39.990,000] <wrn> sensor_manager: Temperature is high
[00:01:39.990,000] <inf> communication_manager: Communication cycle 100
[00:01:39.990,000] <err> communication_manager: Communication timeout detected
[00:01:41.000,000] <inf> sensor_manager: Temperature value : 125 degC
[00:01:41.000,000] <wrn> sensor_manager: Temperature is high
[00:01:41.000,000] <inf> communication_manager: Communication cycle 101
[00:01:42.010,000] <inf> sensor_manager: Temperature value : 126 degC
[00:01:42.010,000] <wrn> sensor_manager: Temperature is high
[00:01:42.010,000] <inf> communication_manager: Communication cycle 102
[00:01:43.020,000] <inf> sensor_manager: Temperature value : 127 degC
[00:01:43.020,000] <wrn> sensor_manager: Temperature is high
[00:01:43.020,000] <inf> communication_manager: Communication cycle 103
[00:01:44.030,000] <inf> sensor_manager: Temperature value : 128 degC
[00:01:44.030,000] <wrn> sensor_manager: Temperature is high
[00:01:44.030,000] <inf> communication_manager: Communication cycle 104
[00:01:45.040,000] <inf> sensor_manager: Temperature value : 129 degC
[00:01:45.040,000] <wrn> sensor_manager: Temperature is high
[00:01:45.040,000] <inf> communication_manager: Communication cycle 105
[00:01:45.040,000] <err> communication_manager: Communication timeout detected
[00:01:46.050,000] <inf> sensor_manager: Temperature value : 130 degC
[00:01:46.050,000] <wrn> sensor_manager: Temperature is high
[00:01:46.050,000] <inf> communication_manager: Communication cycle 106
[00:01:47.060,000] <inf> sensor_manager: Temperature value : 131 degC
[00:01:47.060,000] <wrn> sensor_manager: Temperature is high
[00:01:47.060,000] <inf> communication_manager: Communication cycle 107
[00:01:48.070,000] <inf> sensor_manager: Temperature value : 132 degC
[00:01:48.070,000] <wrn> sensor_manager: Temperature is high
[00:01:48.070,000] <inf> communication_manager: Communication cycle 108
[00:01:49.080,000] <inf> sensor_manager: Temperature value : 133 degC
[00:01:49.080,000] <wrn> sensor_manager: Temperature is high
[00:01:49.080,000] <inf> communication_manager: Communication cycle 109
[00:01:50.090,000] <inf> sensor_manager: Temperature value : 134 degC
[00:01:50.090,000] <wrn> sensor_manager: Temperature is high
[00:01:50.090,000] <inf> communication_manager: Communication cycle 110
[00:01:50.090,000] <err> communication_manager: Communication timeout detected
[00:01:51.100,000] <inf> sensor_manager: Temperature value : 135 degC
[00:01:51.100,000] <wrn> sensor_manager: Temperature is high
[00:01:51.100,000] <inf> communication_manager: Communication cycle 111
[00:01:52.110,000] <inf> sensor_manager: Temperature value : 136 degC
[00:01:52.110,000] <wrn> sensor_manager: Temperature is high
[00:01:52.110,000] <inf> communication_manager: Communication cycle 112
[00:01:53.120,000] <inf> sensor_manager: Temperature value : 137 degC
[00:01:53.120,000] <wrn> sensor_manager: Temperature is high
[00:01:53.120,000] <inf> communication_manager: Communication cycle 113
[00:01:54.130,000] <inf> sensor_manager: Temperature value : 138 degC
[00:01:54.130,000] <wrn> sensor_manager: Temperature is high
[00:01:54.130,000] <inf> communication_manager: Communication cycle 114
[00:01:55.140,000] <inf> sensor_manager: Temperature value : 139 degC
[00:01:55.140,000] <wrn> sensor_manager: Temperature is high
[00:01:55.140,000] <inf> communication_manager: Communication cycle 115
[00:01:55.140,000] <err> communication_manager: Communication timeout detected
[00:01:56.150,000] <inf> sensor_manager: Temperature value : 140 degC
[00:01:56.150,000] <wrn> sensor_manager: Temperature is high
[00:01:56.150,000] <inf> communication_manager: Communication cycle 116
[00:01:57.160,000] <inf> sensor_manager: Temperature value : 141 degC
[00:01:57.160,000] <wrn> sensor_manager: Temperature is high
[00:01:57.160,000] <inf> communication_manager: Communication cycle 117
[00:01:58.170,000] <inf> sensor_manager: Temperature value : 142 degC
[00:01:58.170,000] <wrn> sensor_manager: Temperature is high
[00:01:58.170,000] <inf> communication_manager: Communication cycle 118
[00:01:59.180,000] <inf> sensor_manager: Temperature value : 143 degC
[00:01:59.180,000] <wrn> sensor_manager: Temperature is high
[00:01:59.180,000] <inf> communication_manager: Communication cycle 119
[00:02:00.190,000] <inf> sensor_manager: Temperature value : 144 degC
[00:02:00.190,000] <wrn> sensor_manager: Temperature is high
[00:02:00.190,000] <inf> communication_manager: Communication cycle 120
[00:02:00.190,000] <err> communication_manager: Communication timeout detected
[00:02:01.200,000] <inf> sensor_manager: Temperature value : 145 degC
[00:02:01.200,000] <wrn> sensor_manager: Temperature is high
[00:02:01.200,000] <inf> communication_manager: Communication cycle 121
[00:02:02.210,000] <inf> sensor_manager: Temperature value : 146 degC
[00:02:02.210,000] <wrn> sensor_manager: Temperature is high
[00:02:02.210,000] <inf> communication_manager: Communication cycle 122
[00:02:03.220,000] <inf> sensor_manager: Temperature value : 147 degC
[00:02:03.220,000] <wrn> sensor_manager: Temperature is high
[00:02:03.220,000] <inf> communication_manager: Communication cycle 123
[00:02:04.230,000] <inf> sensor_manager: Temperature value : 148 degC
[00:02:04.230,000] <wrn> sensor_manager: Temperature is high
[00:02:04.230,000] <inf> communication_manager: Communication cycle 124
[00:02:05.240,000] <inf> sensor_manager: Temperature value : 149 degC
[00:02:05.240,000] <wrn> sensor_manager: Temperature is high
[00:02:05.240,000] <inf> communication_manager: Communication cycle 125
[00:02:05.240,000] <err> communication_manager: Communication timeout detected
[00:02:06.250,000] <inf> sensor_manager: Temperature value : 150 degC
[00:02:06.250,000] <wrn> sensor_manager: Temperature is high
[00:02:06.250,000] <inf> communication_manager: Communication cycle 126
[00:02:07.260,000] <inf> sensor_manager: Temperature value : 151 degC
[00:02:07.260,000] <wrn> sensor_manager: Temperature is high
[00:02:07.260,000] <inf> communication_manager: Communication cycle 127
[00:02:08.270,000] <inf> sensor_manager: Temperature value : 152 degC
[00:02:08.270,000] <wrn> sensor_manager: Temperature is high
[00:02:08.270,000] <inf> communication_manager: Communication cycle 128
[00:02:09.280,000] <inf> sensor_manager: Temperature value : 153 degC
[00:02:09.280,000] <wrn> sensor_manager: Temperature is high
[00:02:09.280,000] <inf> communication_manager: Communication cycle 129
[00:02:10.290,000] <inf> sensor_manager: Temperature value : 154 degC
[00:02:10.290,000] <wrn> sensor_manager: Temperature is high
[00:02:10.290,000] <inf> communication_manager: Communication cycle 130
[00:02:10.290,000] <err> communication_manager: Communication timeout detected
[00:02:11.300,000] <inf> sensor_manager: Temperature value : 155 degC
[00:02:11.300,000] <wrn> sensor_manager: Temperature is high
[00:02:11.300,000] <inf> communication_manager: Communication cycle 131
[00:02:12.310,000] <inf> sensor_manager: Temperature value : 156 degC
[00:02:12.310,000] <wrn> sensor_manager: Temperature is high
[00:02:12.310,000] <inf> communication_manager: Communication cycle 132
[00:02:13.320,000] <inf> sensor_manager: Temperature value : 157 degC
[00:02:13.320,000] <wrn> sensor_manager: Temperature is high
[00:02:13.320,000] <inf> communication_manager: Communication cycle 133
[00:02:14.330,000] <inf> sensor_manager: Temperature value : 158 degC
[00:02:14.330,000] <wrn> sensor_manager: Temperature is high
[00:02:14.330,000] <inf> communication_manager: Communication cycle 134
[00:02:15.340,000] <inf> sensor_manager: Temperature value : 159 degC
[00:02:15.340,000] <wrn> sensor_manager: Temperature is high
[00:02:15.340,000] <inf> communication_manager: Communication cycle 135
[00:02:15.340,000] <err> communication_manager: Communication timeout detected
[00:02:16.350,000] <inf> sensor_manager: Temperature value : 160 degC
[00:02:16.350,000] <wrn> sensor_manager: Temperature is high
[00:02:16.350,000] <inf> communication_manager: Communication cycle 136
[00:02:17.360,000] <inf> sensor_manager: Temperature value : 161 degC
[00:02:17.360,000] <wrn> sensor_manager: Temperature is high
[00:02:17.360,000] <inf> communication_manager: Communication cycle 137
[00:02:18.370,000] <inf> sensor_manager: Temperature value : 162 degC
[00:02:18.370,000] <wrn> sensor_manager: Temperature is high
[00:02:18.370,000] <inf> communication_manager: Communication cycle 138
[00:02:19.380,000] <inf> sensor_manager: Temperature value : 163 degC
[00:02:19.380,000] <wrn> sensor_manager: Temperature is high
[00:02:19.380,000] <inf> communication_manager: Communication cycle 139
[00:02:20.390,000] <inf> sensor_manager: Temperature value : 164 degC
[00:02:20.390,000] <wrn> sensor_manager: Temperature is high
[00:02:20.390,000] <inf> communication_manager: Communication cycle 140
[00:02:20.390,000] <err> communication_manager: Communication timeout detected
[00:02:21.400,000] <inf> sensor_manager: Temperature value : 165 degC
[00:02:21.400,000] <wrn> sensor_manager: Temperature is high
[00:02:21.400,000] <inf> communication_manager: Communication cycle 141
[00:02:22.410,000] <inf> sensor_manager: Temperature value : 166 degC
[00:02:22.410,000] <wrn> sensor_manager: Temperature is high
[00:02:22.410,000] <inf> communication_manager: Communication cycle 142
[00:02:23.420,000] <inf> sensor_manager: Temperature value : 167 degC
[00:02:23.420,000] <wrn> sensor_manager: Temperature is high
[00:02:23.420,000] <inf> communication_manager: Communication cycle 143
[00:02:24.430,000] <inf> sensor_manager: Temperature value : 168 degC
[00:02:24.430,000] <wrn> sensor_manager: Temperature is high
[00:02:24.430,000] <inf> communication_manager: Communication cycle 144
[00:02:25.440,000] <inf> sensor_manager: Temperature value : 169 degC
[00:02:25.440,000] <wrn> sensor_manager: Temperature is high
[00:02:25.440,000] <inf> communication_manager: Communication cycle 145
[00:02:25.440,000] <err> communication_manager: Communication timeout detected
[00:02:26.450,000] <inf> sensor_manager: Temperature value : 170 degC
[00:02:26.450,000] <wrn> sensor_manager: Temperature is high
[00:02:26.450,000] <inf> communication_manager: Communication cycle 146
[00:02:27.460,000] <inf> sensor_manager: Temperature value : 171 degC
[00:02:27.460,000] <wrn> sensor_manager: Temperature is high
[00:02:27.460,000] <inf> communication_manager: Communication cycle 147
[00:02:28.470,000] <inf> sensor_manager: Temperature value : 172 degC
[00:02:28.470,000] <wrn> sensor_manager: Temperature is high
[00:02:28.470,000] <inf> communication_manager: Communication cycle 148
[00:02:29.480,000] <inf> sensor_manager: Temperature value : 173 degC
[00:02:29.480,000] <wrn> sensor_manager: Temperature is high
[00:02:29.480,000] <inf> communication_manager: Communication cycle 149
[00:02:30.490,000] <inf> sensor_manager: Temperature value : 174 degC
[00:02:30.490,000] <wrn> sensor_manager: Temperature is high
[00:02:30.490,000] <inf> communication_manager: Communication cycle 150
[00:02:30.490,000] <err> communication_manager: Communication timeout detected
[00:02:31.500,000] <inf> sensor_manager: Temperature value : 175 degC
[00:02:31.500,000] <wrn> sensor_manager: Temperature is high
[00:02:31.500,000] <inf> communication_manager: Communication cycle 151
[00:02:32.510,000] <inf> sensor_manager: Temperature value : 176 degC
[00:02:32.510,000] <wrn> sensor_manager: Temperature is high
[00:02:32.510,000] <inf> communication_manager: Communication cycle 152
[00:02:33.520,000] <inf> sensor_manager: Temperature value : 177 degC
[00:02:33.520,000] <wrn> sensor_manager: Temperature is high
[00:02:33.520,000] <inf> communication_manager: Communication cycle 153
[00:02:34.530,000] <inf> sensor_manager: Temperature value : 178 degC
[00:02:34.530,000] <wrn> sensor_manager: Temperature is high
[00:02:34.530,000] <inf> communication_manager: Communication cycle 154
[00:02:35.540,000] <inf> sensor_manager: Temperature value : 179 degC
[00:02:35.540,000] <wrn> sensor_manager: Temperature is high
[00:02:35.540,000] <inf> communication_manager: Communication cycle 155
[00:02:35.540,000] <err> communication_manager: Communication timeout detected
[00:02:36.550,000] <inf> sensor_manager: Temperature value : 180 degC
[00:02:36.550,000] <wrn> sensor_manager: Temperature is high
[00:02:36.550,000] <inf> communication_manager: Communication cycle 156
[00:02:37.560,000] <inf> sensor_manager: Temperature value : 181 degC
[00:02:37.560,000] <wrn> sensor_manager: Temperature is high
[00:02:37.560,000] <inf> communication_manager: Communication cycle 157
[00:02:38.570,000] <inf> sensor_manager: Temperature value : 182 degC
[00:02:38.570,000] <wrn> sensor_manager: Temperature is high
[00:02:38.570,000] <inf> communication_manager: Communication cycle 158
[00:02:39.580,000] <inf> sensor_manager: Temperature value : 183 degC
[00:02:39.580,000] <wrn> sensor_manager: Temperature is high
[00:02:39.580,000] <inf> communication_manager: Communication cycle 159
[00:02:40.590,000] <inf> sensor_manager: Temperature value : 184 degC
[00:02:40.590,000] <wrn> sensor_manager: Temperature is high
[00:02:40.590,000] <inf> communication_manager: Communication cycle 160
[00:02:40.590,000] <err> communication_manager: Communication timeout detected
[00:02:41.600,000] <inf> sensor_manager: Temperature value : 185 degC
[00:02:41.600,000] <wrn> sensor_manager: Temperature is high
[00:02:41.600,000] <inf> communication_manager: Communication cycle 161
[00:02:42.610,000] <inf> sensor_manager: Temperature value : 186 degC
[00:02:42.610,000] <wrn> sensor_manager: Temperature is high
[00:02:42.610,000] <inf> communication_manager: Communication cycle 162
[00:02:43.620,000] <inf> sensor_manager: Temperature value : 187 degC
[00:02:43.620,000] <wrn> sensor_manager: Temperature is high
[00:02:43.620,000] <inf> communication_manager: Communication cycle 163
[00:02:44.630,000] <inf> sensor_manager: Temperature value : 188 degC
[00:02:44.630,000] <wrn> sensor_manager: Temperature is high
[00:02:44.630,000] <inf> communication_manager: Communication cycle 164
[00:02:45.640,000] <inf> sensor_manager: Temperature value : 189 degC
[00:02:45.640,000] <wrn> sensor_manager: Temperature is high
[00:02:45.640,000] <inf> communication_manager: Communication cycle 165
[00:02:45.640,000] <err> communication_manager: Communication timeout detected
[00:02:46.650,000] <inf> sensor_manager: Temperature value : 190 degC
[00:02:46.650,000] <wrn> sensor_manager: Temperature is high
[00:02:46.650,000] <inf> communication_manager: Communication cycle 166
[00:02:47.660,000] <inf> sensor_manager: Temperature value : 191 degC
[00:02:47.660,000] <wrn> sensor_manager: Temperature is high
[00:02:47.660,000] <inf> communication_manager: Communication cycle 167
[00:02:48.670,000] <inf> sensor_manager: Temperature value : 192 degC
[00:02:48.670,000] <wrn> sensor_manager: Temperature is high
[00:02:48.670,000] <inf> communication_manager: Communication cycle 168
[00:02:49.680,000] <inf> sensor_manager: Temperature value : 193 degC
[00:02:49.680,000] <wrn> sensor_manager: Temperature is high
[00:02:49.680,000] <inf> communication_manager: Communication cycle 169
[00:02:50.690,000] <inf> sensor_manager: Temperature value : 194 degC
[00:02:50.690,000] <wrn> sensor_manager: Temperature is high
[00:02:50.690,000] <inf> communication_manager: Communication cycle 170
[00:02:50.690,000] <err> communication_manager: Communication timeout detected
[00:02:51.700,000] <inf> sensor_manager: Temperature value : 195 degC
[00:02:51.700,000] <wrn> sensor_manager: Temperature is high
[00:02:51.700,000] <inf> communication_manager: Communication cycle 171
[00:02:52.710,000] <inf> sensor_manager: Temperature value : 196 degC
[00:02:52.710,000] <wrn> sensor_manager: Temperature is high
[00:02:52.710,000] <inf> communication_manager: Communication cycle 172
[00:02:53.720,000] <inf> sensor_manager: Temperature value : 197 degC
[00:02:53.720,000] <wrn> sensor_manager: Temperature is high
[00:02:53.720,000] <inf> communication_manager: Communication cycle 173
[00:02:54.730,000] <inf> sensor_manager: Temperature value : 198 degC
[00:02:54.730,000] <wrn> sensor_manager: Temperature is high
[00:02:54.730,000] <inf> communication_manager: Communication cycle 174
[00:02:55.740,000] <inf> sensor_manager: Temperature value : 199 degC
[00:02:55.740,000] <wrn> sensor_manager: Temperature is high
[00:02:55.740,000] <inf> communication_manager: Communication cycle 175
[00:02:55.740,000] <err> communication_manager: Communication timeout detected
[00:02:56.750,000] <inf> sensor_manager: Temperature value : 200 degC
[00:02:56.750,000] <wrn> sensor_manager: Temperature is high
[00:02:56.750,000] <inf> communication_manager: Communication cycle 176
[00:02:57.760,000] <inf> sensor_manager: Temperature value : 201 degC
[00:02:57.760,000] <wrn> sensor_manager: Temperature is high
[00:02:57.760,000] <inf> communication_manager: Communication cycle 177
[00:02:58.770,000] <inf> sensor_manager: Temperature value : 202 degC
[00:02:58.770,000] <wrn> sensor_manager: Temperature is high
[00:02:58.770,000] <inf> communication_manager: Communication cycle 178
[00:02:59.780,000] <inf> sensor_manager: Temperature value : 203 degC
[00:02:59.780,000] <wrn> sensor_manager: Temperature is high
[00:02:59.780,000] <inf> communication_manager: Communication cycle 179
[00:03:00.790,000] <inf> sensor_manager: Temperature value : 204 degC
[00:03:00.790,000] <wrn> sensor_manager: Temperature is high
[00:03:00.790,000] <inf> communication_manager: Communication cycle 180
[00:03:00.790,000] <err> communication_manager: Communication timeout detected
[00:03:01.800,000] <inf> sensor_manager: Temperature value : 205 degC
[00:03:01.800,000] <wrn> sensor_manager: Temperature is high
[00:03:01.800,000] <inf> communication_manager: Communication cycle 181
[00:03:02.810,000] <inf> sensor_manager: Temperature value : 206 degC
[00:03:02.810,000] <wrn> sensor_manager: Temperature is high
[00:03:02.810,000] <inf> communication_manager: Communication cycle 182
[00:03:03.820,000] <inf> sensor_manager: Temperature value : 207 degC
[00:03:03.820,000] <wrn> sensor_manager: Temperature is high
[00:03:03.820,000] <inf> communication_manager: Communication cycle 183
[00:03:04.830,000] <inf> sensor_manager: Temperature value : 208 degC
[00:03:04.830,000] <wrn> sensor_manager: Temperature is high
[00:03:04.830,000] <inf> communication_manager: Communication cycle 184
[00:03:05.840,000] <inf> sensor_manager: Temperature value : 209 degC
[00:03:05.840,000] <wrn> sensor_manager: Temperature is high
[00:03:05.840,000] <inf> communication_manager: Communication cycle 185
[00:03:05.840,000] <err> communication_manager: Communication timeout detected
[00:03:06.850,000] <inf> sensor_manager: Temperature value : 210 degC
[00:03:06.850,000] <wrn> sensor_manager: Temperature is high
[00:03:06.850,000] <inf> communication_manager: Communication cycle 186
[00:03:07.860,000] <inf> sensor_manager: Temperature value : 211 degC
[00:03:07.860,000] <wrn> sensor_manager: Temperature is high
[00:03:07.860,000] <inf> communication_manager: Communication cycle 187
[00:03:08.870,000] <inf> sensor_manager: Temperature value : 212 degC
[00:03:08.870,000] <wrn> sensor_manager: Temperature is high
[00:03:08.870,000] <inf> communication_manager: Communication cycle 188
[00:03:09.880,000] <inf> sensor_manager: Temperature value : 213 degC
[00:03:09.880,000] <wrn> sensor_manager: Temperature is high
[00:03:09.880,000] <inf> communication_manager: Communication cycle 189
[00:03:10.890,000] <inf> sensor_manager: Temperature value : 214 degC
[00:03:10.890,000] <wrn> sensor_manager: Temperature is high
[00:03:10.890,000] <inf> communication_manager: Communication cycle 190
[00:03:10.890,000] <err> communication_manager: Communication timeout detected
[00:03:11.900,000] <inf> sensor_manager: Temperature value : 215 degC
[00:03:11.900,000] <wrn> sensor_manager: Temperature is high
[00:03:11.900,000] <inf> communication_manager: Communication cycle 191
[00:03:12.910,000] <inf> sensor_manager: Temperature value : 216 degC
[00:03:12.910,000] <wrn> sensor_manager: Temperature is high
[00:03:12.910,000] <inf> communication_manager: Communication cycle 192
[00:03:13.920,000] <inf> sensor_manager: Temperature value : 217 degC
[00:03:13.920,000] <wrn> sensor_manager: Temperature is high
[00:03:13.920,000] <inf> communication_manager: Communication cycle 193
[00:03:14.930,000] <inf> sensor_manager: Temperature value : 218 degC
[00:03:14.930,000] <wrn> sensor_manager: Temperature is high
[00:03:14.930,000] <inf> communication_manager: Communication cycle 194
[00:03:15.940,000] <inf> sensor_manager: Temperature value : 219 degC
[00:03:15.940,000] <wrn> sensor_manager: Temperature is high
[00:03:15.940,000] <inf> communication_manager: Communication cycle 195
[00:03:15.940,000] <err> communication_manager: Communication timeout detected
[00:03:16.950,000] <inf> sensor_manager: Temperature value : 220 degC
[00:03:16.950,000] <wrn> sensor_manager: Temperature is high
[00:03:16.950,000] <inf> communication_manager: Communication cycle 196
[00:03:17.960,000] <inf> sensor_manager: Temperature value : 221 degC
[00:03:17.960,000] <wrn> sensor_manager: Temperature is high
[00:03:17.960,000] <inf> communication_manager: Communication cycle 197
[00:03:18.970,000] <inf> sensor_manager: Temperature value : 222 degC
[00:03:18.970,000] <wrn> sensor_manager: Temperature is high
[00:03:18.970,000] <inf> communication_manager: Communication cycle 198
[00:03:19.980,000] <inf> sensor_manager: Temperature value : 223 degC
[00:03:19.980,000] <wrn> sensor_manager: Temperature is high
[00:03:19.980,000] <inf> communication_manager: Communication cycle 199
[00:03:20.990,000] <inf> sensor_manager: Temperature value : 224 degC
[00:03:20.990,000] <wrn> sensor_manager: Temperature is high
[00:03:20.990,000] <inf> communication_manager: Communication cycle 200
[00:03:20.990,000] <err> communication_manager: Communication timeout detected
[00:03:22.000,000] <inf> sensor_manager: Temperature value : 225 degC
[00:03:22.000,000] <wrn> sensor_manager: Temperature is high
[00:03:22.000,000] <inf> communication_manager: Communication cycle 201
[00:03:23.010,000] <inf> sensor_manager: Temperature value : 226 degC
[00:03:23.010,000] <wrn> sensor_manager: Temperature is high
[00:03:23.010,000] <inf> communication_manager: Communication cycle 202
[00:03:24.020,000] <inf> sensor_manager: Temperature value : 227 degC
[00:03:24.020,000] <wrn> sensor_manager: Temperature is high
[00:03:24.020,000] <inf> communication_manager: Communication cycle 203
[00:03:25.030,000] <inf> sensor_manager: Temperature value : 228 degC
[00:03:25.030,000] <wrn> sensor_manager: Temperature is high
[00:03:25.030,000] <inf> communication_manager: Communication cycle 204
[00:03:26.040,000] <inf> sensor_manager: Temperature value : 229 degC
[00:03:26.040,000] <wrn> sensor_manager: Temperature is high
[00:03:26.040,000] <inf> communication_manager: Communication cycle 205
[00:03:26.040,000] <err> communication_manager: Communication timeout detected
[00:03:27.050,000] <inf> sensor_manager: Temperature value : 230 degC
[00:03:27.050,000] <wrn> sensor_manager: Temperature is high
[00:03:27.050,000] <inf> communication_manager: Communication cycle 206
[00:03:28.060,000] <inf> sensor_manager: Temperature value : 231 degC
[00:03:28.060,000] <wrn> sensor_manager: Temperature is high
[00:03:28.060,000] <inf> communication_manager: Communication cycle 207
[00:03:29.070,000] <inf> sensor_manager: Temperature value : 232 degC
[00:03:29.070,000] <wrn> sensor_manager: Temperature is high
[00:03:29.070,000] <inf> communication_manager: Communication cycle 208
[00:03:30.080,000] <inf> sensor_manager: Temperature value : 233 degC
[00:03:30.080,000] <wrn> sensor_manager: Temperature is high
[00:03:30.080,000] <inf> communication_manager: Communication cycle 209
[00:03:31.090,000] <inf> sensor_manager: Temperature value : 234 degC
[00:03:31.090,000] <wrn> sensor_manager: Temperature is high
[00:03:31.090,000] <inf> communication_manager: Communication cycle 210
[00:03:31.090,000] <err> communication_manager: Communication timeout detected
[00:03:32.100,000] <inf> sensor_manager: Temperature value : 235 degC
[00:03:32.100,000] <wrn> sensor_manager: Temperature is high
[00:03:32.100,000] <inf> communication_manager: Communication cycle 211
[00:03:33.110,000] <inf> sensor_manager: Temperature value : 236 degC
[00:03:33.110,000] <wrn> sensor_manager: Temperature is high
[00:03:33.110,000] <inf> communication_manager: Communication cycle 212
[00:03:34.120,000] <inf> sensor_manager: Temperature value : 237 degC
[00:03:34.120,000] <wrn> sensor_manager: Temperature is high
[00:03:34.120,000] <inf> communication_manager: Communication cycle 213
[00:03:35.130,000] <inf> sensor_manager: Temperature value : 238 degC
[00:03:35.130,000] <wrn> sensor_manager: Temperature is high
[00:03:35.130,000] <inf> communication_manager: Communication cycle 214
[00:03:36.140,000] <inf> sensor_manager: Temperature value : 239 degC
[00:03:36.140,000] <wrn> sensor_manager: Temperature is high
[00:03:36.140,000] <inf> communication_manager: Communication cycle 215
[00:03:36.140,000] <err> communication_manager: Communication timeout detected
[00:03:37.150,000] <inf> sensor_manager: Temperature value : 240 degC
[00:03:37.150,000] <wrn> sensor_manager: Temperature is high
[00:03:37.150,000] <inf> communication_manager: Communication cycle 216
[00:03:38.160,000] <inf> sensor_manager: Temperature value : 241 degC
[00:03:38.160,000] <wrn> sensor_manager: Temperature is high
[00:03:38.160,000] <inf> communication_manager: Communication cycle 217
[00:03:39.170,000] <inf> sensor_manager: Temperature value : 242 degC
[00:03:39.170,000] <wrn> sensor_manager: Temperature is high
[00:03:39.170,000] <inf> communication_manager: Communication cycle 218
[00:03:40.180,000] <inf> sensor_manager: Temperature value : 243 degC
[00:03:40.180,000] <wrn> sensor_manager: Temperature is high
[00:03:40.180,000] <inf> communication_manager: Communication cycle 219
[00:03:41.190,000] <inf> sensor_manager: Temperature value : 244 degC
[00:03:41.190,000] <wrn> sensor_manager: Temperature is high
[00:03:41.190,000] <inf> communication_manager: Communication cycle 220
[00:03:41.190,000] <err> communication_manager: Communication timeout detected
[00:03:42.200,000] <inf> sensor_manager: Temperature value : 245 degC
[00:03:42.200,000] <wrn> sensor_manager: Temperature is high
[00:03:42.200,000] <inf> communication_manager: Communication cycle 221
[00:03:43.210,000] <inf> sensor_manager: Temperature value : 246 degC
[00:03:43.210,000] <wrn> sensor_manager: Temperature is high
[00:03:43.210,000] <inf> communication_manager: Communication cycle 222
[00:03:44.220,000] <inf> sensor_manager: Temperature value : 247 degC
[00:03:44.220,000] <wrn> sensor_manager: Temperature is high
[00:03:44.220,000] <inf> communication_manager: Communication cycle 223
[00:03:45.230,000] <inf> sensor_manager: Temperature value : 248 degC
[00:03:45.230,000] <wrn> sensor_manager: Temperature is high
[00:03:45.230,000] <inf> communication_manager: Communication cycle 224
[00:03:46.240,000] <inf> sensor_manager: Temperature value : 249 degC
[00:03:46.240,000] <wrn> sensor_manager: Temperature is high
[00:03:46.240,000] <inf> communication_manager: Communication cycle 225
[00:03:46.240,000] <err> communication_manager: Communication timeout detected
[00:03:47.250,000] <inf> sensor_manager: Temperature value : 250 degC
[00:03:47.250,000] <wrn> sensor_manager: Temperature is high
[00:03:47.250,000] <inf> communication_manager: Communication cycle 226
[00:03:48.260,000] <inf> sensor_manager: Temperature value : 251 degC
[00:03:48.260,000] <wrn> sensor_manager: Temperature is high
[00:03:48.260,000] <inf> communication_manager: Communication cycle 227
[00:03:49.270,000] <inf> sensor_manager: Temperature value : 252 degC
[00:03:49.270,000] <wrn> sensor_manager: Temperature is high
[00:03:49.270,000] <inf> communication_manager: Communication cycle 228
[00:03:50.280,000] <inf> sensor_manager: Temperature value : 253 degC
[00:03:50.280,000] <wrn> sensor_manager: Temperature is high
[00:03:50.280,000] <inf> communication_manager: Communication cycle 229
[00:03:51.290,000] <inf> sensor_manager: Temperature value : 254 degC
[00:03:51.290,000] <wrn> sensor_manager: Temperature is high
[00:03:51.290,000] <inf> communication_manager: Communication cycle 230
[00:03:51.290,000] <err> communication_manager: Communication timeout detected
[00:03:52.300,000] <inf> sensor_manager: Temperature value : 255 degC
[00:03:52.300,000] <wrn> sensor_manager: Temperature is high
[00:03:52.300,000] <inf> communication_manager: Communication cycle 231
[00:03:53.310,000] <inf> sensor_manager: Temperature value : 256 degC
[00:03:53.310,000] <wrn> sensor_manager: Temperature is high
[00:03:53.310,000] <inf> communication_manager: Communication cycle 232
[00:03:54.320,000] <inf> sensor_manager: Temperature value : 257 degC
[00:03:54.320,000] <wrn> sensor_manager: Temperature is high
[00:03:54.320,000] <inf> communication_manager: Communication cycle 233
[00:03:55.330,000] <inf> sensor_manager: Temperature value : 258 degC
[00:03:55.330,000] <wrn> sensor_manager: Temperature is high
[00:03:55.330,000] <inf> communication_manager: Communication cycle 234
[00:03:56.340,000] <inf> sensor_manager: Temperature value : 259 degC
[00:03:56.340,000] <wrn> sensor_manager: Temperature is high
[00:03:56.340,000] <inf> communication_manager: Communication cycle 235
[00:03:56.340,000] <err> communication_manager: Communication timeout detected
[00:03:57.350,000] <inf> sensor_manager: Temperature value : 260 degC
[00:03:57.350,000] <wrn> sensor_manager: Temperature is high
[00:03:57.350,000] <inf> communication_manager: Communication cycle 236
[00:03:58.360,000] <inf> sensor_manager: Temperature value : 261 degC
[00:03:58.360,000] <wrn> sensor_manager: Temperature is high
[00:03:58.360,000] <inf> communication_manager: Communication cycle 237
[00:03:59.370,000] <inf> sensor_manager: Temperature value : 262 degC
[00:03:59.370,000] <wrn> sensor_manager: Temperature is high
[00:03:59.370,000] <inf> communication_manager: Communication cycle 238
[00:04:00.380,000] <inf> sensor_manager: Temperature value : 263 degC
[00:04:00.380,000] <wrn> sensor_manager: Temperature is high
[00:04:00.380,000] <inf> communication_manager: Communication cycle 239
[00:04:01.390,000] <inf> sensor_manager: Temperature value : 264 degC
[00:04:01.390,000] <wrn> sensor_manager: Temperature is high
[00:04:01.390,000] <inf> communication_manager: Communication cycle 240
[00:04:01.390,000] <err> communication_manager: Communication timeout detected
[00:04:02.400,000] <inf> sensor_manager: Temperature value : 265 degC
[00:04:02.400,000] <wrn> sensor_manager: Temperature is high
[00:04:02.400,000] <inf> communication_manager: Communication cycle 241
[00:04:03.410,000] <inf> sensor_manager: Temperature value : 266 degC
[00:04:03.410,000] <wrn> sensor_manager: Temperature is high
[00:04:03.410,000] <inf> communication_manager: Communication cycle 242
[00:04:04.420,000] <inf> sensor_manager: Temperature value : 267 degC
[00:04:04.420,000] <wrn> sensor_manager: Temperature is high
[00:04:04.420,000] <inf> communication_manager: Communication cycle 243
[00:04:05.430,000] <inf> sensor_manager: Temperature value : 268 degC
[00:04:05.430,000] <wrn> sensor_manager: Temperature is high
[00:04:05.430,000] <inf> communication_manager: Communication cycle 244
[00:04:06.440,000] <inf> sensor_manager: Temperature value : 269 degC
[00:04:06.440,000] <wrn> sensor_manager: Temperature is high
[00:04:06.440,000] <inf> communication_manager: Communication cycle 245
[00:04:06.440,000] <err> communication_manager: Communication timeout detected
```