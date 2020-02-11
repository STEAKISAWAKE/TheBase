

#include <stdlib.h>

#include "Window.h"

#include <GLFW/glfw3.h>

Window* CreateRenderWindow(int width, int height, const char* name, bool fullscreen)
{
	Window* ret;

	ret = (Window*)malloc(sizeof(Window));


	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	ret->win = glfwCreateWindow(width, height, name, NULL, NULL);


	return ret;
}

void DestroyRenderWindow(Window* destroyWin)
{
	glfwDestroyWindow(destroyWin->win);
	free(destroyWin);
}