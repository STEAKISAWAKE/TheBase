add_subdirectory(MathTest) # The math test does not render to a window only prints out to a terminal

if(BUILD_GAME_MODULE)
	add_subdirectory(GameTest) # The Game Test creates a game but does not have the ability to render to a window
endif()

if(BUILD_RENDERING_MODULE)
	add_subdirectory(RenderingTest) # The Rendering Test renders to a window and creates a spinning cube
endif()

if(BUILD_GAME_MODULE AND BUILD_RENDERING_MODULE)
	add_subdirectory(CubeGame) # The CubeGame Test creates a window and and allows for basic controlling
endif()
