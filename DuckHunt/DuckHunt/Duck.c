#include "Duck.h"

int nb_duck = 1;

typedef enum DucksState
{
	WAIT = 1,
	FLY,
	FLYLOW,
	FLYMID,
	FLYHIGH,
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
		ducks[i].duckRect.left = ducks[i].duckType * ducks[i].duckRect.width * ducks[i].size;
		ducks[i].duckRect.top = 112 + 80;
		sfSprite_setTextureRect(ducks[i].duckSprite, ducks[i].duckRect);
		ducks[i].FrameX = 0;
		ducks[i].FrameY = 0;
		ducks[i].duckPos = vector2f(940.f, 540.f);
		ducks[i].newDuckPos = vector2f((float)iRand(0, 1) * 1920 - ducks[i].duckRect.width * ducks[i].size, (float)iRand(-200, 500));
		ducks[i].saveDuckPos = ducks[i].duckPos;
		sfSprite_setPosition(ducks[i].duckSprite, ducks[i].duckPos);
		ducks[i].animTimer = 0.f;
		ducks[i].flightTimer = 0.f;
		ducks[i].duckVelocity = vector2f(0.7f, -0.1f);
		ducks[i].isFlipped = sfFalse;
		ducks[i].speed = vector2f(50.f, 30.f);
	
	}

	return ducks;
}

void updateDuck(Ducks* ducks)
{
	
	for (int i = 0; i < nb_duck; i++)
	{
		ducks[i].duckState = WAIT;
		
		if (sfKeyboard_isKeyPressed(sfKeySpace))
		{
			ducks[i].animTimer += GetDeltaTime();
			ducks[i].duckState = FLY;

			//newTimer += GetDeltaTime()/500.f * ducks[i].speed.x;
			//if (newTimer > 1.1f)
			//{
			//	newTimer = 0.f;
			//}
			//printf("%f\n", newTimer);

			ducks[i].flightTimer += GetDeltaTime() / 50.f * ducks[i].speed.x;

			//if (ducks[i].flightTimer > 1.1f)
			//{
			//	ducks[i].flightTimer = 0.f;
			//}

			//if (ducks[i].duckPos.x <= 0  - (3 * ducks[i].size) || ducks[i].duckPos.x >= 1920 - ducks[i].duckRect.width - (3 * ducks[i].size) || ducks[i].duckPos.y <= 0)
			//{
			//	//ducks[i].saveDuckPos = ducks[i].duckPos;
			//	//ducks[i].newDuckPos = getRandomPos();
			//	//ducks[i].flightTimer = 0.01f;
			//	//printf("yeah");
			//	ducks[i].duckVelocity.y *= -1.f;
			//}

			if (ducks[i].duckPos.x <= 0.f)
			{
				//ducks[i].duckVelocity.x *= -1.f;
				ducks[i].duckVelocity.x = -0.1f;

				float rmd = (float)(iRand(-9, -1)) / 10;
				printf("%f\n", rmd);
				ducks[i].duckVelocity.x += rmd;
				printf("%f\n", ducks[i].duckVelocity.x);

				//if (ducks[i].duckVelocity.x < -1.f) { ducks[i].duckVelocity.x = -1.f; }
				//if (ducks[i].duckVelocity.x > 1.f) { ducks[i].duckVelocity.x = 1.f; }

				if (ducks[i].duckPos.x <= 0.f)
				{
					ducks[i].duckPos.x = 10.f;
				}

			}
			if (ducks[i].duckPos.x >= 1920.f - ducks[i].duckRect.width * ducks[i].size)
			{
				//ducks[i].duckVelocity.x *= -1.f;
				ducks[i].duckVelocity.x = 0.1f;
				ducks[i].duckVelocity.x += (float)(iRand(1,9))/10;

				//if (ducks[i].duckVelocity.x < -1.f) { ducks[i].duckVelocity.x = -1.f; }
				//if (ducks[i].duckVelocity.x > 1.f) { ducks[i].duckVelocity.x = 1.f; }

				if (ducks[i].duckPos.x >= 1920.f - ducks[i].duckRect.width * ducks[i].size)
				{
					ducks[i].duckPos.x = 1920.f - 10.f - ducks[i].duckRect.width * ducks[i].size;
				}

			}
			if (ducks[i].duckPos.y <= 0.f)
			{
				ducks[i].duckVelocity.y *= -1.f;
				ducks[i].duckVelocity.y = (float)(iRand(0, 10) - 5) / 10 + 0.075f;
				ducks[i].duckVelocity.y += 0.075f;

				if (ducks[i].duckVelocity.y < -1.f) { ducks[i].duckVelocity.y = -1.f; }
				if (ducks[i].duckVelocity.y > 1.f) { ducks[i].duckVelocity.y = 1.f; }

				if (ducks[i].duckPos.y <= 0.f)
				{
					ducks[i].duckPos.y = 10.f;
				}

			}
			if (ducks[i].duckPos.y >= 800.f - ducks[i].duckRect.height * ducks[i].size)
			{
				ducks[i].duckVelocity.y *= -1.f;
				ducks[i].duckVelocity.y = (float)(iRand(0, 10) - 5) / 10 + 0.075f;
				ducks[i].duckVelocity.y += 0.075f;

				if (ducks[i].duckVelocity.y < -1.f) { ducks[i].duckVelocity.y = -1.f; }
				if (ducks[i].duckVelocity.y > 1.f) { ducks[i].duckVelocity.y = 1.f; }

				if (ducks[i].duckPos.y >= 800.f - ducks[i].duckRect.height * ducks[i].size)
				{
					ducks[i].duckPos.y = 800.f - 10.f - ducks[i].duckRect.height * ducks[i].size;
				}

			}
			//printf("%f, %f\n", ducks[i].duckPos.x, ducks[i].duckPos.y);


			sfVector2f newPos;

			//newPos = LerpVector(ducks[i].saveDuckPos, ducks[i].newDuckPos, ducks[i].flightTimer);

			newPos = AddVectors(ducks[i].duckPos, CreateVector(MultiplyVector(ducks[i].duckVelocity, 50.f*ducks[i].speed.x * GetDeltaTime()), MultiplyVector(ducks[i].duckVelocity, 50.f * ducks[i].speed.y * GetDeltaTime())));

			ducks[i].duckPos = newPos;
			sfSprite_setPosition(ducks[i].duckSprite, ducks[i].duckPos);
		}

		//printf("%f, %f\n", ducks[i].duckVelocity.x, ducks[i].duckVelocity.y);


		if (ducks[i].duckVelocity.y > 0.5f || ducks[i].duckVelocity.y < -0.5f)
		{
			if (ducks[i].duckVelocity.x > 0)
			{
				ducks[i].isFlipped = sfTrue;
			}

			else
			{
				ducks[i].isFlipped = sfFalse;
			}
			ducks[i].duckState = FLYHIGH;

		}
		else if (ducks[i].duckVelocity.y > 0.1f || ducks[i].duckVelocity.y < -0.1f)
		{
			if (ducks[i].duckVelocity.x > 0)
			{
				ducks[i].isFlipped = sfTrue;
			}

			else
			{
				ducks[i].isFlipped = sfFalse;
			}
			ducks[i].duckState = FLYMID;

		}
		else
		{
			if (ducks[i].duckVelocity.x > 0)
			{
				ducks[i].isFlipped = sfTrue;
			}

			else
			{
				ducks[i].isFlipped = sfFalse;
			}
			ducks[i].duckState = FLYLOW;

		}

		



		if (ducks[i].duckState >= FLY && ducks[i].duckState <DEAD)
		{
			if (ducks[i].isFlipped == sfTrue)
			{
				sfSprite_setScale(ducks[i].duckSprite, vector2f(-1.f * ducks[i].size, 1.f * ducks[i].size));
				ducks[i].isFlipped == sfFalse;
			}
			else
			{
				sfSprite_setScale(ducks[i].duckSprite, vector2f(1.f * ducks[i].size, 1.f * ducks[i].size));

			}

			if (ducks[i].duckState == FLYLOW)
			{
				ducks[i].duckRect.top = 112;
			}
			else if (ducks[i].duckState == FLYMID)
			{
				ducks[i].duckRect.top = 112 + 40;
				
			}
			else if (ducks[i].duckState == FLYHIGH)
			{
				ducks[i].duckRect.top = 112 +40 +40;
			}




			if (ducks[i].animTimer > 0.5f)
			{
				ducks[i].FrameY += 1;
				if (ducks[i].FrameY > 2) ducks[i].FrameY = 0;

				ducks[i].duckRect.left += ducks[i].duckRect.width;
				if (ducks[i].FrameY == 0)
				{
					ducks[i].duckRect.left = ducks[i].duckType * ducks[i].duckRect.width * 3;
				}

				ducks[i].animTimer = 0.f;
			}

			sfSprite_setTextureRect(ducks[i].duckSprite, ducks[i].duckRect);


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
