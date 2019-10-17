cmake_minimum_required(VERSION 3.5)

project(leetcode)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

include_directories(${CMAKE_CURRENT_LIST_DIR}/Utilities)

file(GLOB USER_LIBS_PATH "./src/*.cpp")

add_library(base STATIC ${USER_LIBS_PATH})

add_executable(main main.cpp )
target_link_libraries(main base)