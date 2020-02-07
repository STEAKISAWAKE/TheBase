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
