
#include <stdio.h>
#include <stdlib.h>

#include "Render.h"


int main()
{

	Render main;

	Render_Init(&main);
	
	while (!glfwWindowShouldClose(main.window->win))
	{

		Render_UpdateWindow(&main);
	}

	Render_Shutdown(&main);
	
	glfwTerminate();
}
