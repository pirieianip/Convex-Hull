project(Convex_Hull)

set(CMAKE_CXX_STANDARD 17)

add_library(Triangle Triangle.h Triangle.cpp isInside.cpp LawOfCosineAngle.cpp LawOfSine.cpp GetHeight.cpp Create_Centroid.cpp Helpers.cpp)
target_link_libraries(Triangle Point)

add_executable(Triangle_Test Test.cpp)
target_link_libraries(Triangle_Test Triangle)
