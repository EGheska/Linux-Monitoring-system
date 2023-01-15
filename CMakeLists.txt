cmake_minimum_required(VERSION 3.22)
project(Linux-Monitoring-system)

set(CMAKE_CXX_STANDARD 20)

add_executable(Linux-Monitoring-system main.cpp)
add_subdirectory(src)
target_include_directories(Linux-Monitoring-system PRIVATE inc)

target_compile_features(Linux-Monitoring-system PRIVATE cxx_std_20)
#target_compile_options(Linux-Monitoring-system PRIVATE -Wall -Wextra -Werror -fsanitize=address)
#target_link_options(Linux-Monitoring-system PRIVATE -fsanitize=address)