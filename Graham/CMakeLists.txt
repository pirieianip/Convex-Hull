project(Convex_Hull)

find_package (Threads)
set(CMAKE_CXX_STANDARD 17)

add_library(Graham Graham.cpp Graham.h Convex_Hull.cpp Sort.cpp Push_Pop.cpp Compare.cpp Pop.cpp)
add_executable(Graham_test Test.cpp)
target_link_libraries (Graham ${CMAKE_THREAD_LIBS_INIT})

target_link_libraries(Graham Point)

target_link_libraries(Graham_test Graham)
target_link_libraries(Graham_test Point)
target_link_libraries(Graham_test Helpers)