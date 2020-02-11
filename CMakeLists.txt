cmake_minimum_required(VERSION 3.9)


# this thebase_set_option was stolen from the SFML CMakeLists.txt
# define a macro that helps defining an option
macro(thebase_set_option var default type docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

project(TheBase C) # This project is a C project

#if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	#target_link_libraries(TheBase m)
#endif()

set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libraries/")

thebase_set_option(BUILD_GAME_MODULE TRUE BOOL "Do you want to build the Game Module?")
thebase_set_option(BUILD_RENDERING_MODULE TRUE BOOL "Do you want to build the Rendering Module?")
thebase_set_option(BUILD_EXAMPLE_EXECUTABLES TRUE BOOL "Do you want to build the Example Executables?")

add_subdirectory(src)

if(BUILD_EXAMPLE_EXECUTABLES)
	add_subdirectory(examples)
endif()
