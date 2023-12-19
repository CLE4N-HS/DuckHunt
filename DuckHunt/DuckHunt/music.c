#include "music.h"

sfMusic* mainMusic;

void initMusic()
{
	mainMusic = sfMusic_createFromFile(MUSIC_PATH"Su_Turno.ogg");
	gunShot = sfSound_create();
	gunShotBuffer = sfSoundBuffer_createFromFile(SOUND_PATH"gunShot.ogg");
	sfSound_setBuffer(gunShot, gunShotBuffer);
}

void updateMusic()
{
	sfMusic_play(mainMusic);
	sfMusic_setLoop(mainMusic, sfTrue);
}

void makeSound(SoundsList* sound)
{
	if (sound == GUNSHOT && gameState >= EASYMOD && gameState <=HARDMOD)
	{
		sfSound_play(gunShot);
	}
}

