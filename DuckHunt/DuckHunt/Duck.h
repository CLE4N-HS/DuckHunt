#pragma once
#include "tools.h"

int nb_duck_alive;

sfBool allowedToInitDucks;

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
	sfVector2f deadDuckPos;
	float animTimer;
	float flightTimer;
	float deadTimer;
	sfVector2f duckVelocity;
	sfBool isFlipped;
	sfVector2f speed;

}Ducks;

//Ducks* ducks;

Ducks* initDuck(int _nb_duck);
void updateDuck(sfRenderWindow* _window, Ducks* _ducks);
void displayDuck(sfRenderWindow* _window, Ducks* _ducks);