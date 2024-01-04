cmake_minimum_required(VERSION 3.15)

project(socket)

include_directories(
	${PROJECT_ROOT}
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
)

add_library(socket SHARED
	ClientSocket.cpp
	EventPoller.cpp
	ServerSocket.cpp
	Socket.cpp
	SocketHandler.cpp
)

target_link_libraries(socket PUBLIC utility
	PRIVATE task)
