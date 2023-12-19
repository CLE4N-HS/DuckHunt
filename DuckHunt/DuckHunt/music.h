#pragma once
#include "tools.h"

sfSound* gunShot;
sfSoundBuffer* gunShotBuffer;

typedef enum SoundsList
{
	NOSOUND = 0,
	GUNSHOT
}SoundsList;

void initMusic();
void updateMusic();
void makeSound(SoundsList* sound);