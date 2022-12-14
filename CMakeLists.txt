cmake_minimum_required(VERSION 3.0)
project(MYENGINE)

include_directories(
	src
	contrib/include
	
)

link_directories(
	${PROJECT_SOURCE_DIR}/contrib/lib
)

add_library(rend
 src/rend/Animation.cpp
 src/rend/Buffer.cpp
 src/rend/Mesh.cpp
 src/rend/Model.cpp
 src/rend/ModelRenderer.cpp
 src/rend/RenderTexture.cpp
 src/rend/Renderer.cpp
 src/rend/Shader.cpp
 src/rend/Texture.cpp
 src/rend/rendmath.cpp
 src/rend/Animation.h
 src/rend/Buffer.h
 src/rend/Mesh.h
 src/rend/Model.h
 src/rend/ModelRenderer.h
 src/rend/RenderTexture.h
 src/rend/Renderer.h
 src/rend/Shader.h
 src/rend/Texture.h
 src/rend/rendmath.h
)
target_link_libraries(rend glew32 opengl32)


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
src/ThomasTheTank/Components/AudioSource.h
src/ThomasTheTank/Components/AudioSource.cpp
src/ThomasTheTank/Components/Resource.h
src/ThomasTheTank/Components/Resource.cpp
src/ThomasTheTank/Wrapping/ThomasMath.h
src/ThomasTheTank/Time.h
src/ThomasTheTank/Time.cpp
src/ThomasTheTank/TriangleRenderer.h
src/ThomasTheTank/TriangleRenderer.cpp
src/ThomasTheTank/Components/Camera.h
src/ThomasTheTank/Components/Camera.cpp
src/ThomasTheTank/Input.h
src/ThomasTheTank/Input.cpp
src/ThomasTheTank/Cursor.h
src/ThomasTheTank/Cursor.cpp
)

target_link_libraries(ThomasTheTank
SDL2
rend
OpenAL32
)

add_executable(game
  src/game/main.cpp
)

target_link_libraries(game 
ThomasTheTank
)

