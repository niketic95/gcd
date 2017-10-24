cmake_minimum_required(VERSION 2.8)

project(gcd)
add_library(${PROJECT_NAME} SHARED gcd.c gcd.h)
