cmake_minimum_required(VERSION 3.30)
project(SimpleGameEngine)

set(CMAKE_CXX_STANDARD 20)
set(INCLUDES_DIR ${CMAKE_SOURCE_DIR}/dependency/include/)
set(LIBS_DIR ${CMAKE_SOURCE_DIR}/dependency/lib/)

add_library(GLAD ${INCLUDES_DIR}glad/glad.c
        src/Game/GameObject/Model/Model.cpp
        src/Game/GameObject/Model/Model.h)
add_library(STB_IMAGE ${INCLUDES_DIR}stb/stb_image.cpp)

set(LIBS GLAD STB_IMAGE glfw3 assimp)

include_directories(${INCLUDES_DIR})
link_directories(${LIBS_DIR})

add_executable(SimpleGameEngine
        src/main.cpp
        src/utils/utils.h
        src/Application/Application.cpp
        src/Application/Application.h
        src/Error/Error.cpp
        src/Error/Error.h
        src/Game/Game.cpp
        src/Game/Game.h
        src/Game/GameObject/GameObject.cpp
        src/Game/GameObject/GameObject.h
        src/Game/GameObject/Camera/Camera.cpp
        src/Game/GameObject/Camera/Camera.h
        src/Game/Shader/Shader.cpp
        src/Game/Shader/Shader.h
        src/Game/Screen/Screen.cpp
        src/Game/Screen/Screen.h
        src/Game/Time/Time.cpp
        src/Game/Time/Time.h
        src/Game/Input/Input.cpp
        src/Game/Input/Input.h
        src/Game/Scene/Scene.cpp
        src/Game/Scene/Scene.h
        src/Managers/Managers.cpp
        src/Managers/Managers.h
        src/Managers/ShaderManager/ShaderManager.cpp
        src/Managers/ShaderManager/ShaderManager.h
        src/Managers/ResourceManager/ResourceManager.cpp
        src/Managers/ResourceManager/ResourceManager.h
        src/Game/Material/Material.cpp
        src/Game/Material/Material.h
        src/Game/Texture/Texture.cpp
        src/Game/Texture/Texture.h
        src/Game/Material/TextureMaterial/TextureMaterial.cpp
        src/Game/Material/TextureMaterial/TextureMaterial.h
        src/Game/Material/ColorMaterial/ColorMaterial.cpp
        src/Game/Material/ColorMaterial/ColorMaterial.h
        src/Game/GameObject/Model/Mesh/Mesh.cpp
        src/Game/GameObject/Model/Mesh/Mesh.h
        src/Game/GameObject/Model/Vertex/Vertex.cpp
        src/Game/GameObject/Model/Vertex/Vertex.h)

target_link_libraries(SimpleGameEngine ${LIBS})