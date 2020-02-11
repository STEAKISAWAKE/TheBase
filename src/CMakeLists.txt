# Always build Math Module first because Rendering and Game Modules use it.
add_subdirectory(Math)


if(BUILD_RENDERING_MODULE)
	add_subdirectory(Rendering)
	target_compile_definitions(Rendering PUBLIC "BUILD_RENDERING_MODULE")
endif()

if(BUILD_GAME_MODULE)
	add_subdirectory(Game)
	target_compile_definitions(Game PUBLIC "BUILD_GAME_MODULE")
endif()
