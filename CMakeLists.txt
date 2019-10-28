cmake_minimum_required(VERSION 3.14)
project(JSON_Exercise)

set(CMAKE_CXX_STANDARD 11)

add_executable(JSON_Exercise leptjson.h leptjson.c test.c)