project(Convex_Hull)

set(CMAKE_CXX_STANDARD 17)


add_library(Point Create_Slope.cpp Create_Y_Intercept.cpp GetMostPoint.cpp Hypotenuse.cpp Line.cpp Point.cpp Point.h Point2.cpp Sin.cpp setQuadrant.cpp setOriginCircle.cpp)
add_executable(Point_test Test.cpp)

target_link_libraries(Point_test Point)