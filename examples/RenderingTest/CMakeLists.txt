add_executable( RenderModuleTest
	main.c
)


include_directories(${PROJECT_SOURCE_DIR}/include/Render)

target_link_libraries(RenderModuleTest
    PRIVATE 
        Render
)
