cmake_minimum_required(VERSION 3.15)

project(web)

include_directories(
	${PROJECT_ROOT}
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
)

add_library(web SHARED
	Request.cpp
	Response.cpp
	Server.cpp
)

target_link_libraries(web PUBLIC utility
	PRIVATE reflect socket trd)
