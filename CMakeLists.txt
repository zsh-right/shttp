cmake_minimum_required(VERSION 3.15)

project(yazi)

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(
	${PROJECT_ROOT}
)

message(${CMAKE_CURRENT_SOURCE_DIR})
SET (ENV{GIT_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/.git")
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(app)
add_subdirectory(json)
add_subdirectory(reflect)
add_subdirectory(socket)
add_subdirectory(utility)
add_subdirectory(thread)
add_subdirectory(task)
add_subdirectory(web)
add_executable(server server.cpp)
target_link_libraries(server 
	app
	json
	reflect
	socket
	utility
	trd
	task
	web
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config/server.ini
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/config/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/log/server.log
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/log/)
