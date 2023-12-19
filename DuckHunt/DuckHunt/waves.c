#include "waves.h"

void initWaves()
{
	wavesState = WAITWAVES;
	nb_waves = 1;
}

void updateWaves()
{
	if (wavesState == NEXTWAVE)
	{
		nb_waves += 1;
		wavesState = SHOWWAVES;
	}

	if (wavesState == SHOWWAVES)
	{
		printf("%d\n", nb_waves);
	}
}
