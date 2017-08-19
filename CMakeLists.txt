cmake_minimum_required(VERSION 3.8)
project(problem2_Kalmanfilter)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp KalmanFilter.cpp KalmanFilter.h matrix.cpp matrix.h vector.cpp vector.h paramters.h)
add_executable(problem2_Kalmanfilter ${SOURCE_FILES})