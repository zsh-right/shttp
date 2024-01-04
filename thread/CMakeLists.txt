cmake_minimum_required(VERSION 3.15)

project(trd)
find_package(Threads REQUIRED)

include_directories(
	${PROJECT_ROOT}
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
)

message(${CMAKE_CURRENT_BINARY_DIR})

add_library(trd SHARED
	AutoLock.cpp
	Condition.cpp
	Mutex.cpp
	Task.cpp
	TaskDispatcher.cpp
	Thread.cpp
	ThreadPool.cpp
	WorkerThread.cpp
)

target_link_libraries(trd PUBLIC utility Threads::Threads)
