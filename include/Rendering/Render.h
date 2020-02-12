#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#ifdef PLATFORM_WINDOWS
    #include <Windows.h>

    #ifdef USING_VULKAN
        #include <VulkanIncludes>
    #else
        #include <OpenGLRender.h>
    #endif
#endif // PLATFORM_WINDOWS


#ifdef PLATFORM_UNIX
    #ifdef USING_VULKAN
        #include <VulkanIncludes>
    #else
        #include <OpenGLRender.h>
    #endif
#endif // PLATFORM_UNIX

#include <Window.h>



// The rendering API determines which kind of window is being created
typedef enum _RenderAPI
{
    OpenGL = 0,
    Vulkan = 1
} RenderAPI;

struct _Render
{
    RenderAPI CurrentAPI;
    void* Context;

    Window window;
};

typedef struct _Render Render;

bool Render_Init(Render*);
void Render_UpdateWindow(Render*);
void Render_Shutdown(Render*);

#endif // RENDER_H_INCLUDED
