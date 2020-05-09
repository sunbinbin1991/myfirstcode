cmake_minimum_required(VERSION 3.5)

project(leetcode)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

include_directories(${CMAKE_CURRENT_LIST_DIR}/Utilities)

file(GLOB USER_LIBS_PATH "./src/*.cpp")

file(GLOB USER_Utils_PATH "./Utilities/*.cpp")

add_library(base STATIC ${USER_LIBS_PATH} ${USER_Utils_PATH})

#add_executable(demo demo.cpp )
#target_link_libraries(demo base)

add_executable(LeetCode main.cpp )
target_link_libraries(LeetCode base)