#ifndef VULKANRENDER_H_INCLUDED
#define VULKANRENDER_H_INCLUDED

#ifdef USING_VULKAN

#include <stdbool.h>

#include <vulkan/vulkan.h>

#include "../Math/Mat4.h"

struct _Render;

bool Render_Vulkan_Init(struct _Render*);
void Render_Vulkan_Shutdown(struct _Render*);

void Render_Vulkan_DrawMesh(struct _Render* curRender, struct _Mesh* mesh, fMatrix4 transform);

#endif

#endif // VULKANRENDER_H_INCLUDED
