#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "SFML/Graphics.h"
#include "menu.h"
#include "Background.h"
#include "Duck.h"

#define WINDOW_LENGTH 1280
#define WINDOW_HEIGHT 720
#define EPSILON (float)1e-6
#define DEG2RAD 0.0174533
#define RAD2DEG 57.295779
#define PI 3.141593
#define LERP(a,b,t) (b-a)*t+a

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

sfVector2f LerpVector(sfVector2f _a, sfVector2f _b, float _t);
sfVector2f PolarCoords(sfVector2f v, float r, float theta);

sfVector2f CreateVector(sfVector2f _v1, sfVector2f _v2);
sfVector2f AddVectors(sfVector2f _v1, sfVector2f _v2);
sfVector2f SubstractVectors(sfVector2f _v1, sfVector2f _v2);
float DotProduct(sfVector2f _v1, sfVector2f _v2);
float GetMagnitude(sfVector2f _vector);
sfVector2f Normalize(sfVector2f _vector);
float GetSqrMagnitude(sfVector2f _vector);
sfVector2f MultiplyVector(sfVector2f _vector, float _multiply);
float GetAngleBetweenVectors(sfVector2f _v1, sfVector2f _v2);

sfBool Equals(sfVector2f _v1, sfVector2f _v2);

//sfBool PlayerCanSeeEnemy(sfVector2f _pPos, sfVector2f _ePos, sfVector2f _POVPos, float _FOV, float _pAngle);

sfBool IsInFOV(sfVector2f _lookingObject, sfVector2f _forwardVector, sfVector2f _targetObject, float _maxRadius, float _fieldOfView);

