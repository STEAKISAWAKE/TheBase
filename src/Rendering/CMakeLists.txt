add_library(Rendering STATIC
	Window.c
	Render.c
	OpenGLRender.c
)

target_include_directories(Rendering
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include/Rendering
)

target_link_libraries(Rendering Math)