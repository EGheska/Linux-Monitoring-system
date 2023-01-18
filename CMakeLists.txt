cmake_minimum_required(VERSION 3.22)
project(monitoring)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(monitoring ${SOURCES})

set_property(TARGET monitoring PROPERTY CXX_STANDARD 20)
target_link_libraries(monitoring ${CURSES_LIBRARIES})
target_compile_options(monitoring PRIVATE -Wall -Wextra -Werror -fsanitize=address)
target_link_options(monitoring PRIVATE -fsanitize=address)