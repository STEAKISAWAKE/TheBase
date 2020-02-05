add_library("{$PROJECT_NAME}" STATIC)

target_include_directories( {$PROJECT_NAME} PUBLIC

	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
	$<INSTALL_INTERFACE:include> # ${CMAKE_INSTALL_PREFIX}/include
	
)

if(NOT BUILD_SHARED_LIBS)
	set(STATIC_POSTFIX -s)
endif()

# Rename target TheBase
set_target_properties(${PROJECT_NAME} PROPERTIES
	DEBUG_POSTFIX ${STATIC_POSTFIX}-d
	RELEASE_POSTFIX "${STATIC_POSTFIX}"
	MINSIZEREL_POSTFIX ${STATIC_POSTFIX}-mr
	RELWITHDEBINFO_POSTFIX ${STATIC_POSTFIX}-rd
	
)

include("GenerateExportHeader")
generate_export_header(${PROJECT_NAME})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/game_export.h DESTINATION "include")



add_subdirectory("include")
add_subdirectory("src")