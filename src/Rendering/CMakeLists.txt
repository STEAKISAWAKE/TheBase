
add_library(Rendering STATIC
	Window.c
	Render.c
	OpenGLRender.c
)

if(WIN32)				
	target_compile_definitions(Rendering PUBLIC PLATFORM_WINDOWS)
elseif(UNIX)
	target_compile_definitions(Rendering PUBLIC PLATFORM_UNIX)
endif()


if(USING_VULKAN)
	target_compile_definitions(Rendering PUBLIC "USING_VULKAN")
endif()

target_include_directories(Rendering
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include/Rendering
)

target_link_libraries(Rendering Math)

set(GLFW_DIR "${LIB_DIR}glfw")
set(FREETYPE_DIR "${LIB_DIR}freetype")


add_subdirectory(${GLFW_DIR} "${GLFW_DIR}/build")
add_subdirectory(${FREETYPE_DIR} "${FREETYPE_DIR}/build")

target_link_libraries(Rendering "freetype" "${FREETYPE_LIBRARIES}")

target_include_directories(Rendering PRIVATE "${GLFW_DIR}/include")
target_include_directories(Rendering PRIVATE "${FREETYPE_DIR}/include")

if(USING_VULKAN)
	find_package(Vulkan REQUIRED)
	
	message(STATUS "Vulkan FOUND = ${Vulkan_FOUND}")
	message(STATUS "Vulkan Include = ${Vulkan_INCLUDE_DIR}")
	message(STATUS "Vulkan Lib = ${Vulkan_LIBRARY}")

	if(NOT Vulkan_FOUND)
		message("Vulkan was not found and with USING_VULKAN enabled. Disable USING_VULKAN or install the Vulkan SDK. SDK at: https://vulkan.lunarg.com/")
	endif()

	target_link_libraries(Rendering ${Vulkan_LIBRARY})
	target_link_libraries(Rendering "glfw" ${GLFW_LIBRARIES} Vulkan::Vulkan)

	target_include_directories(Rendering PRIVATE "${Vulkan_INCLUDE_DIR}/include")
elseif()
	
	target_link_libraries(Rendering "glfw" "${GLFW_LIBRARIES}")

endif()

if(MSVC)
	target_link_libraries(Rendering opengl32)
elseif(UNIX)
	target_link_libraries(Rendering GL)
endif()

set(GLAD_DIR "${LIB_DIR}glad")
	
target_link_libraries(Rendering "glad" "${CMAKE_DL_LIBS}")

target_include_directories(Rendering PRIVATE "${GLAD_DIR}/include")

add_library("glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")




target_compile_definitions(Rendering PRIVATE "GLFW_INCLUDE_NONE")

# GLFW
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation" FORCE)
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")


