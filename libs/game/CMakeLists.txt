add_library(game STATIC game.cpp AI.cpp)
target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)