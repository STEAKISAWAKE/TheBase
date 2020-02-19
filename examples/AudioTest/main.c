#include <stdio.h>

#include "Audio.h"



int main()
{

	Audio_Init();

	Sound data;
	Audio_LoadFile("C:\\Users\\caden\\Music\\Dayglow - Listerine.wav", &data);

	Audio_Play(&data);
	
	Pa_Sleep(5000);

	Pa_StopStream(data.stream);

	Pa_Sleep(2000);

	Pa_StartStream(data.stream);
	

	/* Run until EOF is reached */

	while (Pa_IsStreamActive(data.stream))
	{


		Pa_Sleep(100);
	}

	Audio_Stop(&data);

	Audio_Shutdown();

}