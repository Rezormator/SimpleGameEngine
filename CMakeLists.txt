cmake_minimum_required(VERSION 3.30)
project(SimpleGameEngine)

set(CMAKE_CXX_STANDARD 20)
set(INCLUDES_DIR ${CMAKE_SOURCE_DIR}/dependency/include/)
set(LIBS_DIR ${CMAKE_SOURCE_DIR}/dependency/lib/)

add_library(GLAD ${INCLUDES_DIR}glad/glad.c)
add_library(STB_IMAGE ${INCLUDES_DIR}stb/stb_image.cpp)

set(LIBS GLAD STB_IMAGE glfw3 assimp)

include_directories(${INCLUDES_DIR})
link_directories(${LIBS_DIR})

add_executable(SimpleGameEngine
        src/main.cpp)
