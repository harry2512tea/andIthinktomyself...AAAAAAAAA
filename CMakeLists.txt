cmake_minimum_required(VERSION 3.0)
project(MYENGINE)

include_directories(
	src
)

add_executable(game
  src/game/main.cpp
)

add_library(ThomasTheTank
src/ThomasTheTank/ThomasTheTank.h
src/ThomasTheTank/core.cpp
src/ThomasTheTank/core.h
)

target_link_libraries(game ThomasTheTank)