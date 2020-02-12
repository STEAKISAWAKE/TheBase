
#include <stdio.h>
#include <stdlib.h>

#include "Window.h"

#include <GLFW/glfw3.h>

void Window_Create(Window* curWindow,int width, int height, const char* name, bool fullscreen)
{

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
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
