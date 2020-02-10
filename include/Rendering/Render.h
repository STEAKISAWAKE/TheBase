#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#ifdef PLATFORM_WINDOWS
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
#endif // PLATFORM_LINUX



// The rendering API determines which kind of window is being created
enum RenderAPI
{
    OpenGL = 0,
    Vulkan = 1
}

struct _Render
{
    RenderAPI CurrentAPI;
    void* Context;
};

void Init(Render&);
void RenderMesh(Mesh*);

#endif // RENDER_H_INCLUDED
