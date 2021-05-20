cmake_minimum_required(VERSION 3.20.2)

project(tictactoe)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/game)
add_executable(tictactoe ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(tictactoe PUBLIC game)
target_include_directories(tictactoe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/game/include)

enable_testing()
add_executable(checkWinnerTester tests/checkWinnerTest.cpp)
target_link_libraries(checkWinnerTester PUBLIC game)
target_include_directories(checkWinnerTester PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/game/include)
add_test(checkWinner checkWinnerTester)