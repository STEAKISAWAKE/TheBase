add_executable( MathModuleTest
	main.c
)


include_directories(${PROJECT_SOURCE_DIR}/include/Math)

target_link_libraries(MathModuleTest
    PRIVATE 
        Math
)