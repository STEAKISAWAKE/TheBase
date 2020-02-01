#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#include <Mesh.h>

#define USING_DIRECTX

#ifdef PLATFORM_WINDOWS
    #ifdef USING_DIRECTX
        #include <DirectXIncludes>
    #elifdef USING_VULKAN
        #include <VulkanIncludes>
    #else
        #include <OpenGLRender.h>
    #endif
#endif // PLATFORM_WINDOWS


#ifdef PLATFORM_LINUX
    #ifdef USING_VULKAN
        #include <VulkanIncludes>
    #else
        #include <OpenGLRender.h>
    #endif
#endif // PLATFORM_LINUX



// To add different Rendering API's to the engine
// add a new enum element and then make a new file which includes the file
// The rendering API also determines which kind of window is being created
enum RenderAPI
{
    OpenGL = 0,
    DirectX = 1,
    Vulkan = 2
}

typedef struct _Render
{
    RenderAPI CurrentAPI;
    void* Context;
} Render;

void Init(Render&, RenderAPI);
void RenderMesh(Mesh*);

#endif // RENDER_H_INCLUDED
