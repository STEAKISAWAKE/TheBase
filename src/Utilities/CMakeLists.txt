add_library(Utilities STATIC
	vector.c
)

target_include_directories(Utilities
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include/Utilities
)
