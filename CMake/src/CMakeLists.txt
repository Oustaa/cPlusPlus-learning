cmake_minimum_required(VERSION 3.31.4) 

project(Tutorial VERSION 1.0)
# target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")
configure_file(TutorialConfig.h.in TutorialConfig.h)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ousta index.cpp)
