cmake_minimum_required(VERSION 3.14)

project(Linetor LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libs/Catch2)

add_executable(Linetor
	linetor.h
	main.cpp
)

target_link_libraries(Linetor PRIVATE Catch2::Catch2WithMain)

