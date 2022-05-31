cmake_minimum_required(VERSION 3.0.0)
project(CKKS_test VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(CKKS_test CKKS_test.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
