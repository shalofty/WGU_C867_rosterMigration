cmake_minimum_required(VERSION 3.23)
project(schoolRoster)

set(CMAKE_CXX_STANDARD 23)

add_executable(schoolRoster main.cpp degree.h student.cpp student.h roster.cpp roster.h)
