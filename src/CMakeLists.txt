# Always build Math Module first because Rendering and Game Modules use it.
add_subdirectory(Math)

if(BUILD_RENDERING_MODULE)
	add_subdirectory(Rendering)
endif()

if(BUILD_GAME_MODULE)
	add_subdirectory(Game)
endif()