#include "Duck.h"

int nb_duck = 1;

typedef enum DucksState
{
	WAIT = 1,
	FLY,
	DEAD
};

float newTimer = 0.f;

sfVector2f getRandomPos()
{
	return vector2f(iRand(0, 1) * 1920, iRand(20, 500));
}

Ducks* initDuck(int _nb_duck)
{
	nb_duck = _nb_duck;
	Ducks* ducks = malloc(_nb_duck * sizeof(Ducks));
	
	for (int i = 0; i < _nb_duck; i++)
	{
		ducks[i].duckId = i;
		ducks[i].duckState = WAIT;
		ducks[i].duckSprite = sfSprite_create();
		ducks[i].duckTexture = sfTexture_createFromFile(TEXTURE_PATH"all.png", NULL);
		sfSprite_setTexture(ducks[i].duckSprite, ducks[i].duckTexture, sfTrue);
		ducks[i].size = 3;
		sfSprite_setScale(ducks[i].duckSprite, vector2f(3.f, 3.f));
		ducks[i].duckType = i % 3;
		ducks[i].duckRect.height = 40;
		ducks[i].duckRect.width = 40;
		ducks[i].duckRect.left = ducks[i].duckType * ducks[i].duckRect.width * 3;
		ducks[i].duckRect.top = 112 + 80;
		sfSprite_setTextureRect(ducks[i].duckSprite, ducks[i].duckRect);
		ducks[i].FrameX = 0;
		ducks[i].FrameY = 0;
		ducks[i].duckPos = vector2f(100*i,200.f+i*30);
		ducks[i].newDuckPos = vector2f((float)iRand(0, 1) * 1920 - ducks[i].duckRect.width * ducks[i].size, (float)iRand(-200, 500));
		sfSprite_setPosition(ducks[i].duckSprite, ducks[i].duckPos);
		ducks[i].animTimer = 0.f;
		ducks[i].speed = vector2f(50.f, 30.f);
	
	}

	return ducks;
}

void updateDuck(Ducks* ducks)
{
	
	for (int i = 0; i < nb_duck; i++)
	{
		ducks[i].duckState = WAIT;
		ducks[i].animTimer += GetDeltaTime();
		
		if (sfKeyboard_isKeyPressed(sfKeySpace))
		{
			ducks[i].duckState = FLY;
			//if (ducks[i].duckPos.x <= 0 || ducks[i].duckPos.x > 1920 - ducks[i].duckRect.width * ducks[i].size)
			//{
			//	ducks[i].speed.x = -ducks[i].speed.x;
			//}
			//sfVector2f newPos;
			//
			//newPos = AddVectors(ducks[i].duckPos, MultiplyVector(vector2f(ducks[i].speed.x/30, ducks[i].speed.y/100), GetDeltaTime() * ducks[i].speed.x));
			//
			//ducks[i].duckPos = AddVectors(ducks[i].duckPos, MultiplyVector(vector2f((float)(i - 5)/4, (float)-1), GetDeltaTime() * 100));
			newTimer += GetDeltaTime();
			if (newTimer > 1)
			{
				newTimer = 0.f;
			}
			sfVector2f newPos;
			//newPos = AddVectors(ducks[i].duckPos, LerpVector(ducks[i].duckPos, ducks[i].newDuckPos, newTimer));
			newPos = LerpVector(ducks[i].duckPos, ducks[i].newDuckPos, newTimer);

			ducks[i].duckPos = newPos;
			sfSprite_setPosition(ducks[i].duckSprite, ducks[i].duckPos);
		}

		
		if (ducks[i].duckState == FLY)
		{


			if (ducks[i].animTimer > 0.5f)
			{
				ducks[i].FrameY += 1;
				if (ducks[i].FrameY > 2) ducks[i].FrameY = 0;

				ducks[i].duckRect.left += ducks[i].duckRect.width;
				if (ducks[i].FrameY == 0)
				{
					ducks[i].duckRect.left = ducks[i].duckType * ducks[i].duckRect.width * 3;
				}
				sfSprite_setTextureRect(ducks[i].duckSprite, ducks[i].duckRect);

				ducks[i].animTimer = 0.f;
			}

		}
	}

	

	

}

void displayDuck(sfRenderWindow* _window, Ducks* ducks)
{
	for (int i = 0; i < nb_duck; i++)
	{
		sfRenderWindow_drawSprite(_window, ducks[i].duckSprite, NULL);
	}
}
