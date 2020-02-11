add_executable( RenderingModuleTest
	main.c
)


include_directories(${PROJECT_SOURCE_DIR}/include/Rendering)

target_link_libraries(RenderingModuleTest
    PRIVATE 
        Rendering
)
