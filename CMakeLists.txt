cmake_minimum_required(VERSION 3.10.3)

set(PROJECT_NAME "scheme")
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#---------------------------------------------------------

# sources & headers
set(SOURCES main.cpp scheme.cpp)
set(HEADERS scheme.h)

#---------------------------------------------------------

set(ALL_FILES ${SOURCES}
              ${HEADERS})

add_executable(${PROJECT_NAME} ${ALL_FILES})

# Filters
source_group("" FILES ${ALL_FILES})