#include "OpenGLRender.h"

#include <stdio.h>

#include <glad/glad.h>

#include "Render.h"
#include "Mesh.h"

bool Render_OpenGL_Init(struct _Render* curRender)
{

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("Error could not initalize GLAD!");
		return false;
	}

	return true;
}

void Render_OpenGL_Shutdown(struct _Render* curRender)
{
	
}

void Render_OpenGL_DrawMesh(struct _Render* curRender, struct _Mesh* mesh, fMatrix4 transform)
{

}