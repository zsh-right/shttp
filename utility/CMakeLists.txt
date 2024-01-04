cmake_minimum_required(VERSION 3.15)

project(utility)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
)

add_library(utility SHARED
	IniFile.cpp
	Logger.cpp
	System.cpp
	Str.cpp
)
