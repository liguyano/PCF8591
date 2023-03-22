cmake_minimum_required(VERSION 3.24)
project(PCF8591 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
INCLUDE_DIRECTORIES(E:\\Keil_v5\\C51\\INC\\Atmel E:\\Keil_v5\\C51\\INC\\STC E:\\Keil_v5\\C51\\INC)
add_executable(PCF8591 main.c)
