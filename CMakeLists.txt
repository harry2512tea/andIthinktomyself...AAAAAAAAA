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
src/ThomasTheTank/Core.cpp
src/ThomasTheTank/Core.h
src/ThomasTheTank/Entity.h
src/ThomasTheTank/Entity.cpp
src/ThomasTheTank/Component.h
src/ThomasTheTank/Component.cpp
src/ThomasTheTank/Components/Transform.h
src/ThomasTheTank/Components/Transform.cpp
src/ThomasTheTank/Components/MeshRenderer.h
src/ThomasTheTank/Components/MeshRenderer.cpp
)

target_link_libraries(game ThomasTheTank)