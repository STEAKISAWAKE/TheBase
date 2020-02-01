#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#ifdef PLATFORM_WINDOWS
    #ifdef INCLUDE_DIRECTX
        #include <DirectXIncludes>
    #elifdef INCLUDE_VULKAN
        #include <VulkanIncludes>
    #else
        #include <OpenGLRender.h>
    #endif
#endif // PLATFORM_WINDOWS


#ifdef PLATFORM_LINUX
    #ifdef INCLUDE VULKAN
        #include <VulkanIncludes>
    #else
        #include <OpenGLRender.h>
    #endif
#endif // PLATFORM_LINUX



// To add different Rendering API's to the engine
// add a new enum element and then make a new file which includes the file
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
void RenderMesh(struct Mesh )

#endif // RENDER_H_INCLUDED
