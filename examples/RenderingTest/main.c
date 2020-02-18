
#include <stdio.h>
#include <stdlib.h>

#include "Render.h"


int main()
{

	Render main;

	if(!Render_Init(&main))
	{
		return 1;
	}
	
	while (!glfwWindowShouldClose(main.window.win))
	{

		Render_Update(&main);
	}

	Render_Shutdown(&main);
	
}
