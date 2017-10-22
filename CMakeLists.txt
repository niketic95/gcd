cmake_minimum_required(VERSION 2.8)

project(PPuRV-PROJECT)
add_subdirectory(gcd)
add_executable(${PROJECT_NAME} "main.c")
target_link_libraries(${PROJECT_NAME} gcd)
