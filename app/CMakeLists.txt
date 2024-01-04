cmake_minimum_required(VERSION 3.15)

project(app)

include_directories(
	${PROJECT_ROOT}
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
)

add_library(app SHARED
	Index.cpp
	User.cpp
)

target_link_libraries(app PUBLIC utility
	PRIVATE web)
