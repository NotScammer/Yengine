cmake_minimum_required(VERSION 3.21)
project(Yengine VERSION 1.0)

# Enforce C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Tell the compiler where to find your .hpp header files
include_directories(include)

# Automatically download and configure SDL3
include(FetchContent)
FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG preview-3.1.6 
)
FetchContent_MakeAvailable(SDL3)

add_executable(Yengine src/main.cpp src/PhysicalObject.cpp src/Game.cpp src/Renderer.cpp)

# Link SDL3 to your game engine
target_link_libraries(Yengine PRIVATE SDL3::SDL3)

# AUTOMATICALLY COPY THE DLL TO THE EXE FOLDER
add_custom_command(TARGET Yengine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_RUNTIME_DLLS:Yengine>
    $<TARGET_FILE_DIR:Yengine>
    COMMAND_EXPAND_LISTS
)