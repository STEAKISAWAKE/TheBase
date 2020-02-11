add_library(Math STATIC
	Mat4.c
	Vec2.c
	Vec3.c
	Vec4.c
)

target_include_directories(Math
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include/Math
)

if(UNIX)
	target_link_libraries(Math m)
endif()
