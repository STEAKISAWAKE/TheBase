add_library(Game STATIC
	Game.c
	World.c
	Utils/Vector.c
)

target_include_directories(Game
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include/Game
	${PROJECT_SOURCE_DIR}/include/Game/Actors
	${PROJECT_SOURCE_DIR}/include/Game/Utils
)

target_link_libraries(Game Math)

if(BUILD_RENDERING_MODULE)
	target_link_libraries(Game Rendering)
endif()