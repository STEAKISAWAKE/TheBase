#include "OpenGLRender.h"

#include <stdio.h>

#include <glad/glad.h>

#include "Render.h"

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