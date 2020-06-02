project(Convex_Hull)
find_package (Threads)
set(CMAKE_CXX_STANDARD 17)

add_library(Quick Quick_Hull.cpp Quick_Hull.h Quick_Single.cpp Quick.cpp mutexClass.h Quick_Full.cpp Quick_Single_Full.cpp)
target_link_libraries (Quick ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Quick Triangle)

add_executable(Quick_Test Test.cpp)
target_link_libraries(Quick_Test Quick)
target_link_libraries(Quick_Test Helpers)