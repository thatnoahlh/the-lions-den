cmake_minimum_required(VERSION 3.10)

# Project Name
project(MentalHealthFlower)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the source files
set(SOURCES
    src/main.cpp
    src/notebook.cpp
    src/flower.cpp
    src/minigames.cpp
)

# Include directories
include_directories(include)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Find OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})

# Add dependencies for GLFW and GLEW
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)

# Link libraries
target_link_libraries(${PROJECT_NAME} glfw GLEW::GLEW)
