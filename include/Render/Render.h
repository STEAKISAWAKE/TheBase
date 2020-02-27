#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED


#ifdef PLATFORM_WINDOWS

    #ifdef USING_VULKAN
        #include "VulkanRender.h"
        #include "OpenGLRender.h"
    #else
        #include "OpenGLRender.h"
    #endif

#endif // PLATFORM_WINDOWS


#ifdef PLATFORM_UNIX

    #ifdef USING_VULKAN
        #include "VulkanRender.h"
        #include "OpenGLRender.h"
    #else
        #include "OpenGLRender.h"
    #endif

#endif // PLATFORM_UNIX 

#include "../Math/Mat4.h"

#include <Window.h>

struct _Mesh;

// The rendering API determines which kind of window is being created
typedef enum _RenderAPI
{
    APIOpenGL = 0,
    APIVulkan = 1
} RenderAPI;

struct _Render
{
    RenderAPI CurrentAPI;
    void* Context;

    Window window;

#ifdef USING_VULKAN // Add new variables to the Render struct if vulkan is being used
    VkInstance   vk_instance;
    uint32_t     vk_enabled_extension_count;
    uint32_t     vk_enabled_layer_count;
    char*        vk_extension_names[64];
    char*        vk_enabled_layers[64];
#endif

};

typedef struct _Render Render;

// Initalization
bool Render_Init(Render*);
void Render_Update(Render*);
void Render_Shutdown(Render*);

// Changing
void Render_DrawMesh(Render* curRender, struct _Mesh* mesh, fMatrix4 transform);

#endif // RENDER_H_INCLUDED
