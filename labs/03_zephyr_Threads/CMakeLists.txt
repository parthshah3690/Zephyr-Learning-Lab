cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(zephyr_logging)

target_sources(app PRIVATE 
                    src/main.c
                    src/system_manager.c
                    src/sensor_manager.c
                    src/comm_manager.c
                    src/power_manager.c
)

target_include_directories(app PRIVATE inc)