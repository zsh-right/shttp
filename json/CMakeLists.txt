cmake_minimum_required(VERSION 3.15)

project(json)

add_library(json SHARED
	Json.cpp
	Parser.cpp
)

target_link_libraries(json PUBLIC utility)
