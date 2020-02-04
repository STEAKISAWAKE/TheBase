cmake_minimum_required(VERSION 3.9)

# define a macro that helps defining an option (taken from sfml)
macro(thebase_set_option var default type docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

# Usage
# thebase_set_option(THEBASE_BUILD_RENDERING TRUE BOOL "TRUE to build the Rendering module.")

# When adding Networking and other features that are big enough for modules, add different options
# Most modules are coded from scratch with minimal libraries, if they are needed

thebase_set_option(BUILD_GAME_MODULE TRUE BOOL "TRUE to build the Game Module.")
thebase_set_option(BUILD_RENDERING_MODULE TRUE BOOL "TRUE to build the Rendering Module.")

project( TheBase VERSION 0.0.2 DESCRIPTION "The Base is a library for games and applications.")

# Set variables
include(${CMAKE_SOURCE_DIR}/cmake/SetEnv.cmake)

# Add source directorys
add_subdirectory(src)

# Install targets
include(${CMAKE_SOURCE_DIR}/cmake/InstallConfig.cmake)
