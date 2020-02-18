
#include <stdio.h>
#include <stdlib.h>

#include "Window.h"

#ifdef USING_VULKAN
	#define GLFW_INCLUDE_VULKAN
#endif

#include <GLFW/glfw3.h>

void Window_Create(Window* curWindow,int width, int height, const char* name, bool fullscreen)
{

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	curWindow->win = glfwCreateWindow(width, height, name, NULL, NULL);


	glfwMakeContextCurrent(curWindow->win);

	if (curWindow->win == NULL)
	{
		printf("Failed to create GLFW window\n");
		glfwTerminate();
		return -1;
	}


}

void Window_Destroy(Window* destroyWin)
{
	glfwDestroyWindow(destroyWin->win);
}
