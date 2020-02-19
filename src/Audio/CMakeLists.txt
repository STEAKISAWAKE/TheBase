# cmake_policy(SET CMP0079 NEW) 

add_library(Audio STATIC
	Audio.c
)

target_include_directories(Audio
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include/Audio
)

target_link_libraries(Audio Math)



set(PORTAUDIO_DIR "${LIB_DIR}portaudio")
set(LIBSNDFILE_DIR "${LIB_DIR}libsndfile")

add_subdirectory(${PORTAUDIO_DIR} ${PORTAUDIO_DIR}/build)
add_subdirectory(${LIBSNDFILE_DIR} ${LIBSNDFILE_DIR}/build)

SET(BUILD_TESTING OFF CACHE BOOL "")
SET(BUILD_EXAMPLES OFF CACHE BOOL "")
SET(BUILD_REGTEST OFF CACHE BOOL "")
SET(BUILD_PROGRAMS OFF CACHE BOOL "")
SET(ENABLE_CPACK OFF CACHE BOOL "")

if (APPLE)
    find_library(CORE_AUDIO_LIBRARY CoreAudio)
    find_library(AUDIO_TOOLBOX_LIBRARY AudioToolbox)
    find_library(AUDIO_UNIT_LIBRARY AudioUnit)
    find_library(CARBON_LIBRARY Carbon)
    set(
            EXTRA_LIBS
            ${CORE_AUDIO_LIBRARY}
            ${AUDIO_TOOLBOX_LIBRARY}
            ${AUDIO_UNIT_LIBRARY}
            ${CARBON_LIBRARY}
    )
endif (APPLE)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(
            EXTRA_LIBS
            rt
            asound
            pthread
    )
endif (CMAKE_SYSTEM_NAME STREQUAL "Linux")

get_target_property(
        LIBSNDFILE_INCLUDES
        sndfile
        PUBLIC_HEADER
)

include_directories(
        include
        ${LIBSNDFILE_INCLUDES}
        ${PA_PUBLIC_INCLUDES}
)

target_link_libraries(
        Audio
        ${EXTRA_LIBS}
        sndfile
        portaudio
)
