cmake_minimum_required(VERSION 3.10)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(bulk
	main.cpp
	Context.h
	Context.cpp)

target_compile_features(bulk PUBLIC cxx_std_17)