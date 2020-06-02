project(Convex_Hull)

find_package (Threads)
set(CMAKE_CXX_STANDARD 17)

add_library(Jarvis Jarvis.cpp Jarvis.h Create_line.cpp Jarvis_March.cpp Future1.h Future2.h Create_Line2.cpp Compare.cpp Orientation.cpp TestingFunctions.cpp RunJarvis.cpp)

add_executable(Jarvis_test Test.cpp)

target_link_libraries (Jarvis ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Jarvis Point)
target_link_libraries(Jarvis Quick)


target_link_libraries(Jarvis_test Jarvis)
target_link_libraries(Jarvis_test Point)
target_link_libraries(Jarvis_test Helpers)

