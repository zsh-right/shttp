cmake_minimum_required(VERSION 3.15)

include_directories(
	${PROJECT_ROOT}
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
)

add_library(task  SHARED
	HttpTask.cpp
)
