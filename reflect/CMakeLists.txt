cmake_minimum_required(VERSION 3.15)

project(reflect)

include_directories(
	${PROJECT_ROOT}
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
)

add_library(reflect SHARED
	ClassFactory.cpp
)

target_link_libraries(reflect PUBLIC utility)
