# To add more modules (Eg. Networking)  you musst add an if statement and a proper BUILD_{MODUlENAME}_MODULE

# Math is used in every library controls things like position
add_subdirectory(Math)

if(BUILD_GAME_MODULE)
	# The game module is what controls all of the logic 
	add_subdirectory(Game)
endif()

if(BUILD_RENDERING_MODULE)
	# The Rendering module is what has the controls the windows and the visuals
	add_subdirectory(Rendering)
endif()

# FAQ

# Can you use the Rendering Module without the Game Module? Yes
# Can you use the Game Module without the Rendering Module? Yes
