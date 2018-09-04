cmake_minimum_required(VERSION 3.3)
project(Laplace)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES laplace.cpp)
find_package(OpenCV REQUIRED)
add_executable(Laplace ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
