project(queue)

# Flags
set(CMAKE_CXX_STANDARD 17)
set(${CMAKE_CXX_FLAGS} "${CMAKE_CXX_FLAGS} -Wall -g -std=c++17 -fprofile-arcs -ftest-coverage")

# Target
add_executable(tests queue.hpp queue_impl.hpp tests.cpp)
