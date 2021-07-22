cmake_minimum_required(VERSION 3.16)
project(opengl-stuff)

find_package(glfw3 REQUIRED)

add_executable(opengl-stuff main.cpp glad.c source\ files/EBO.cpp source\ files/VAO.cpp source\ files/VBO.cpp source\ files/shaderClass.cpp)
target_compile_features(opengl-stuff PRIVATE cxx_std_17)
target_link_libraries(opengl-stuff PRIVATE dl glfw)
