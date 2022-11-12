cmake_minimum_required(VERSION 3.23)
project(supermarketQ_console C)

set(CMAKE_C_STANDARD 99)

add_executable(supermarketQ_console main.c supermarket_q.c supermarket_q.h)
