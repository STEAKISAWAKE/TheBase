#include "Audio.h"

#include <stdio.h>

bool Audio_Init()
{

    PaError error;

    /* init portaudio */
    error = Pa_Initialize();
    if (error != paNoError)
    {
        fprintf(stderr, "Problem initializing Audio Module.\n");
        return false;
    }

    return true;
}

void Audio_InitSound(Sound* data)
{
    data->file = NULL;
    data->stream = NULL;
}

void Audio_LoadFile(const char* file, Sound* data)
{

    if (data->NotInitalized == true)
        Audio_InitSound(data);

    /* Open the soundfile */
    data->file = sf_open(file, SFM_READ, &data->info);
    if (sf_error(data->file) != SF_ERR_NO_ERROR)
    {
        fprintf(stderr, "%s\n", sf_strerror(data->file));
        fprintf(stderr, "File: %s\n", file);
        return; // Error could not load file
    }

    
    return;

}

void Audio_Play(Sound* data)
{
    
    PaError error;

    if (data->NotInitalized == true)
        Audio_InitSound(data);

    if (data->stream == NULL)
    {

        /* Open PaStream with values read from the file */
        error = Pa_OpenDefaultStream(&data->stream
            , 0                     /* no input */
            , data->info.channels         /* stereo out */
            , paFloat32             /* floating point */
            , data->info.samplerate
            , FRAMES_PER_BUFFER
            , callback
            , data);        /* our sndfile data struct */
        if (error != paNoError)
        {
            fprintf(stderr, "Problem opening Default Stream\n");
            return;
        }
    }

    /* Start the stream */
    error = Pa_StartStream(data->stream);
    if (error != paNoError)
    {
        fprintf(stderr, "Problem starting Stream\n");
        return;
    }

    return;
}

void Audio_Pause(Sound* data)
{
    PaError error;

   error = Pa_StopStream(data->stream);
   if(error != paNoError)
   {
        fprintf(stderr, "Problem pausing Stream\n");
        return;
   }

   return;
}

void Audio_Remuse(Sound* data)
{
   PaError error;

   error = Pa_StartStream(data->stream);
   if(error != paNoError)
   {
        fprintf(stderr, "Problem pausing Stream\n");
        return;
   }

   return;
}


void Audio_Stop(Sound* data)
{
    PaError error;

    /* Close the soundfile */
    sf_close(data->file);

    /*  Shut down portaudio */
    error = Pa_CloseStream(data->stream);
    if (error != paNoError)
    {
        fprintf(stderr, "Problem closing stream\n");
        return;
    }
}

void Audio_Shutdown()
{
    PaError error;

    error = Pa_Terminate();
    if (error != paNoError)
    {
        fprintf(stderr, "Problem terminating\n");
        return;
    }
}

bool Audio_IsPlaying(Sound* data)
{
    if (data->stream != NULL)
    {
        return Pa_IsStreamActive(data->stream);
    }
    else
    {
        return false;
    }
}

static
int
callback
(const void* input
    , void* output
    , unsigned long                   frameCount
    , const PaStreamCallbackTimeInfo* timeInfo
    , PaStreamCallbackFlags           statusFlags
    , void* userData
)
{
    float* out;
    Sound* p_data = (Sound*)userData;
    sf_count_t       num_read;

    out = (float*)output;
    p_data = (Sound*)userData;

    /* clear output buffer */
    memset(out, 0, sizeof(float) * frameCount * p_data->info.channels);

    /* read directly into output buffer */
    num_read = sf_read_float(p_data->file, out, (int)frameCount * (int)p_data->info.channels);


    /*  If we couldn't read a full frameCount of samples we've reached EOF */
    if (num_read < frameCount)
    {
        return paComplete;
    }

    return paContinue;
}
