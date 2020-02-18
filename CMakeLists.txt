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
thebase_set_option(BUILD_RENDER_MODULE TRUE BOOL "Do you want to build the Render Module?")
thebase_set_option(BUILD_AUDIO_MODULE TRUE BOOL "Do you want to build the Audio Module?")

thebase_set_option(BUILD_EXAMPLE_EXECUTABLES TRUE BOOL "Do you want to build the Example Executables?")

thebase_set_option(USING_VULKAN TRUE BOOL "Do you wan to use Vulkan for rendering?")

set(VULKAN_HEADERS_INSTALL_DIR "HEADERS-NOTFOUND" CACHE PATH "Absolute path to a Vulkan-Headers install directory")
set(VULKAN_LOADER_INSTALL_DIR "LOADER-NOTFOUND" CACHE PATH "Absolute path to a Vulkan-Loader install directory")
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};${VULKAN_HEADERS_INSTALL_DIR};${VULKAN_LOADER_INSTALL_DIR};
                       $ENV{VULKAN_HEADERS_INSTALL_DIR};$ENV{VULKAN_LOADER_INSTALL_DIR})

add_subdirectory(src)

if(BUILD_EXAMPLE_EXECUTABLES)
	add_subdirectory(examples)
endif()
