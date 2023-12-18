#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "SFML/Graphics.h"
#include "menu.h"
#include "Background.h"

#define WINDOW_LENGTH 1920
#define WINDOW_HEIGHT 1080
#define EPSILON (float)1e-6

#define TEXTURE_PATH "../Ressources/Textures/"

typedef enum State
{
	MENUMOD = 0,
	EASYMOD,
	HARDMOD,
	QUITMOD
};

int gameState;


sfTime sftime;
sfClock* sfclock;

sfVector2f vector2f(float _x, float _y);
int iRand(int _min, int _max);
void initTools();
void restartClock();
float GetDeltaTime();
sfVector2f CreateVector(sfVector2f _pos1, sfVector2f _pos2);
sfVector2f AddVectors(sfVector2f _v1, sfVector2f _v2);
sfVector2f SubstractVectors(sfVector2f _v1, sfVector2f _v2);
float DotProduct(sfVector2f _v1, sfVector2f _v2);
float GetMagnitude(sfVector2f _vector);
sfVector2f Normalize(sfVector2f _vector);
float GetSqrMagnitude(sfVector2f _vector);
sfVector2f MultiplyVector(sfVector2f _vector, float _multiply);
sfBool Equals(sfVector2f _v1, sfVector2f _v2);
