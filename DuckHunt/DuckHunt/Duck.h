#pragma once
#include "tools.h"

typedef struct Ducks
{
	int duckId;
	int duckType;
	int duckState;
	int FrameX;
	int FrameY;
	sfSprite* duckSprite;
	sfTexture* duckTexture;
	int size;
	sfIntRect duckRect;
	sfVector2f duckPos;
	sfVector2f newDuckPos;
	sfVector2f saveDuckPos;
	float animTimer;
	float flightTimer;
	sfVector2f duckVelocity;
	sfBool isFlipped;
	sfVector2f speed;

}Ducks;

//Ducks* ducks;

Ducks* initDuck(int _nb_duck);
void updateDuck(Ducks* _ducks);
void displayDuck(sfRenderWindow* _window, Ducks* _ducks);