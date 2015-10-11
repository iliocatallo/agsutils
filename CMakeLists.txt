cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(agsutils)

file(GLOB AGSUTILS_LIB_SOURCES src/*.c)
file(GLOB AGSUTILS_MAIN_SOURCES main/*.c)
include_directories(include)

add_library(agsutils_lib ${AGSUTILS_LIB_SOURCES})

foreach(main_source_file ${AGSUTILS_MAIN_SOURCES})
	get_filename_component(tool_name ${main_source_file} NAME_WE)
	add_executable(${tool_name} ${main_source_file})
	target_link_libraries(${tool_name} agsutils_lib)
endforeach(main_source_file)
