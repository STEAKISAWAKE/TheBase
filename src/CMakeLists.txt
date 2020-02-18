# Always build Math Module first because Rendering and Game Modules use it.
add_subdirectory(Math)


if(BUILD_RENDERING_MODULE)
	add_subdirectory(Render)
	target_compile_definitions(Render PUBLIC "BUILD_RENDER_MODULE")
endif()

if(BUILD_GAME_MODULE)
	add_subdirectory(Game)
	target_compile_definitions(Game PUBLIC "BUILD_GAME_MODULE")
endif()

if(BUILD_AUDIO_MODULE)
	add_subdirectory(Audio)
	target_compile_definitions(Audio PUBLIC "BUILD_AUDIO_MODULE")
endif()