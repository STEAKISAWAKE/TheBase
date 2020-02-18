add_library(Audio STATIC
	Audio.c
)

target_include_directories(Audio
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include/Audio
)

target_link_libraries(Audio Math)