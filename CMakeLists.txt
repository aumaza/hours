cmake_minimum_required(VERSION 3.0)

project(hours LANGUAGES C)

add_executable(hour main.c lib_hour.h lib_hour.c ArrayList.c ArrayList.h)

install(TARGETS hour RUNTIME DESTINATION bin)
