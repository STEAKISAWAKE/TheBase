#ifndef AUDIO_THEBASE_H_
#define AUDIO_THEBASE_H_

#include <stdbool.h>

#include <sndfile.h>
#include <portaudio.h>

#define FRAMES_PER_BUFFER   (512)

typedef struct
{
    SNDFILE*    file;
    SF_INFO     info;
    PaStream*   stream;

    bool paused;
} Sound;

bool Audio_Init();

void Audio_LoadFile(const char*, Sound*);

void Audio_Play(Sound*);

void Audio_Pause(Sound*);

void Audio_Remuse(Sound*);

void Audio_Stop(Sound*);

void Audio_Shutdown();

static int callback(const void* input, void* output,
    unsigned long frameCount,
    const PaStreamCallbackTimeInfo* timeInfo,
    PaStreamCallbackFlags statusFlags,
    void* userData);

#endif
