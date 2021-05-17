cmake_minimum_required(VERSION 3.20.2)

project(game)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/grid)
add_executable(game ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(game PUBLIC grid)
target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/grid/include)
