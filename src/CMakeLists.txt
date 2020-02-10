# Always build Math Module first because Rendering and Game Modules use it.
add_subdirectory(Math)

if(BUILD_RENDERING_MODULE)
	add_subdirectory(Rendering)
	add_compile_definitions(BUILD_RENDERING_MODULE)
endif()

if(BUILD_GAME_MODULE)
	add_subdirectory(Game)
	add_compile_definitions(BUILD_RENDERING_MODULE)
endif()