#include <stdio.h>

#include "Audio.h"



int main()
{

	Audio_Init();

	Sound data;
	Audio_LoadFile("..//..//..//examples//AudioTest//StarWars3.wav", &data);

	Audio_Play(&data);
	

	/* Run until EOF is reached */

	while (Pa_IsStreamActive(data.stream))
	{


		Pa_Sleep(100);
	}

	Audio_Stop(&data);

	Audio_Shutdown();

}
