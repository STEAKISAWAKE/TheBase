#include "Render.h"

#include <stdio.h>


bool Render_Init(Render* curRender)
{
	glfwInit();

	Window_Create(&curRender->window, 700, 600, "Window", false);

	glfwMakeContextCurrent(curRender->window.win);

#ifdef USING_VULKAN

	if (Render_Vulkan_Init(curRender))
	{
		// Debug log that vulkan initalized 
	}
	else
	{
		// Debug log that vulkan failed

		if (Render_OpenGL_Init(curRender))
		{
			 // Debug log opengl initalized instead
		}
		else // This code should hopefully never execute
		{
			// Debug log that all renderers failed to initalize
			return false;
		}

	}


#else

	//Vulkan not being used here.

	if (Render_OpenGL_Init(curRender))
	{
		// Debug log opengl initalized renderer

	}
	else // This code should hopefully never execute
	{
		// Debug log could not initalize renderer
		return false;
	}

#endif

#ifndef USING_VULKAN

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("Error could not initalize GLAD!");
		glfwTerminate();
		return false;
	}
#endif

	

	printf("Initalized!");

	
	return true;
}

void Render_UpdateWindow(Render* curRender)
{
	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	
	//glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(curRender->window.win);
	glfwPollEvents();

}

void Render_Shutdown(Render* curRender)
{
	Window_Destroy(&curRender->window);


}
