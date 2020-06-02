cmake_minimum_required(VERSION 3.05)
project(Convex_Hull)
find_package (Threads)
set(CMAKE_CXX_FLAGS "-O3 -march=native -pipe -pthread")
set(CMAKE_CXX_STANDARD 17)
add_executable(Convex_Hull main.cpp Convex_Hull.h Graham Jarvis Quick Helpers Point Triangle)

target_link_libraries (Convex_Hull ${CMAKE_THREAD_LIBS_INIT})

add_subdirectory(Graham)
add_subdirectory(Point)
add_subdirectory(Jarvis)
add_subdirectory(Helpers)
add_subdirectory(Quick)
add_subdirectory(Triangle)

target_link_libraries(Convex_Hull Graham)
target_link_libraries(Convex_Hull Jarvis)
target_link_libraries(Convex_Hull Helpers)
target_link_libraries(Convex_Hull Quick)


add_executable(Test Test.cpp)
target_link_libraries(Test Point)
target_link_libraries(Test  ${CMAKE_THREAD_LIBS_INIT})