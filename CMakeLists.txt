cmake_minimum_required(VERSION 3.0)
project(MYENGINE)

include_directories(
	src
	contrib/include
	
)



link_directories(
	${PROJECT_SOURCE_DIR}/contrib/lib
	${PROJECT_SOURCE_DIR}/contrib/bin
)

add_library(Render
src/Render/Shader.h
src/Render/Shader.cpp
src/Render/Material.h
src/Render/Material.cpp
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
src/ThomasTheTank/Wrapping/ThomasMath.h
src/ThomasTheTank/Time.h
src/ThomasTheTank/Time.cpp
)

target_link_libraries(ThomasTheTank
glew32
SDL2
Render
)

add_executable(game
  src/game/main.cpp
)

target_link_libraries(game 
ThomasTheTank
)

