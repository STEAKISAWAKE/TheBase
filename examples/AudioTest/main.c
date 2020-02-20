#include <stdio.h>

#include "Audio.h"



int main()
{

	Audio_Init();

	Sound data;

	Audio_InitSound(&data);

#ifdef PLATFORM_WINDOWS
	const char* directory = "..\\..\\..\\examples\\AudioTest\\StarWars3.wav";
#else
	const char* directory = "..//..//..//examples//AudioTest//StarWars3.wav";
#endif


	Audio_LoadFile(directory, &data);

	Audio_Play(&data);
	

	/* Run until EOF is reached */

	while (Pa_IsStreamActive(data.stream))
	{
		Pa_Sleep(100);
	}

	Audio_Stop(&data);

	//Now play two times

	Pa_Sleep(1000);



	Audio_Play(&data);

	while (Pa_IsStreamActive(data.stream))
	{
		Pa_Sleep(100);
	}


	Audio_Stop(&data);

	Audio_Shutdown();

}
