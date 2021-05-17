cmake_minimum_required(VERSION 3.20.2)

project(game)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/grid)
add_executable(game ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(game PUBLIC grid)
target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/grid/include)

enable_testing()
add_executable(checkWinnerTester tests/checkWinnerTest.cpp)
target_link_libraries(checkWinnerTester PUBLIC grid)
target_include_directories(checkWinnerTester PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/grid/include)
add_test(checkWinner checkWinnerTester)