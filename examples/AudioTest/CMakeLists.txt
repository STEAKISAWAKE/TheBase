add_executable( AudioTest
	main.c
)


include_directories(${PROJECT_SOURCE_DIR}/include/Audio)

target_link_libraries(AudioTest
    PRIVATE 
        Audio
)
