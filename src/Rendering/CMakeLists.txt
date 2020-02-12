add_library(Rendering STATIC
	Window.c
	Render.c
	OpenGLRender.c
)

if(WIN32)				
	target_compile_definitions(Rende1ring PUBLIC PLATFORM_WINDOWS)
elseif(UNIX)
	target_compile_definitions(Rendering PUBLIC PLATFORM_UNIX)
endif()


target_include_directories(Rendering
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include/Rendering
)

target_link_libraries(Rendering Math)

if(MSVC)
	target_link_libraries(Rendering opengl32)
elseif(UNIX)
	target_link_libraries(Rendering GL)
endif()

set(GLFW_DIR "${LIB_DIR}glfw")
set(GLAD_DIR "${LIB_DIR}glad")

add_subdirectory(${GLFW_DIR} "${GLFW_DIR}/build")

target_link_libraries(Rendering "glfw" "${GLFW_LIBRARIES}")
target_link_libraries(Rendering "glad" "${CMAKE_DL_LIBS}")


target_include_directories(Rendering PRIVATE "${GLFW_DIR}/include")
target_include_directories(Rendering PRIVATE "${GLAD_DIR}/include")
 

target_compile_definitions(Rendering PRIVATE "GLFW_INCLUDE_NONE")

# GLFW
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation" FORCE)
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

add_library("glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")


