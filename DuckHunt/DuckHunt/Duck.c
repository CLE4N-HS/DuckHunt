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

sfVector2f getRandomPos()
{
	return vector2f(iRand(0, 1) * 1920, iRand(20, 500));
}

Ducks* initDuck(int _nb_duck)
{
	nb_duck = _nb_duck;
	Ducks* ducks = malloc(_nb_duck * sizeof(Ducks));
	mouseCooldown = 0.f;
	misses = 0;
	allowedToMiss = sfTrue;
	startTimer = 0.f;

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
		ducks[i].duckRect.top = 192;
		sfSprite_setTextureRect(ducks[i].duckSprite, ducks[i].duckRect);
		ducks[i].FrameX = 0;
		ducks[i].FrameY = 0;
		ducks[i].duckPos = vector2f((float)iRand(0, 1920 - ducks[i].duckRect.width * ducks[i].size), 800.f);
		ducks[i].newDuckPos = vector2f((float)iRand(0, 1) * 1920 - ducks[i].duckRect.width * ducks[i].size, (float)iRand(-200, 500));
		ducks[i].saveDuckPos = ducks[i].duckPos;
		ducks[i].deadDuckPos = vector2f(-1.f, -1.f);
		sfSprite_setPosition(ducks[i].duckSprite, ducks[i].duckPos);
		ducks[i].animTimer = 0.f;
		ducks[i].flightTimer = 0.f;
		ducks[i].deadTimer = -1.f;
		ducks[i].duckVelocity = vector2f((float)(iRand(4, 12)) / 10, (float)(iRand(0, 10) - 5) / 10 + 0.075f);
		ducks[i].isFlipped = sfFalse;

		if (gameState == EASYMOD)
		{
			ducks[i].speed = vector2f(50.f, 30.f);
		}
		else ducks[i].speed = vector2f(100.f, 60.f);
	
	}

	nb_duck_alive = _nb_duck;

	return ducks;
}

void updateDuck(sfRenderWindow* _window, Ducks* ducks)
{

	if (!allowedToInitDucks) allowedToInitDucks = sfTrue;

	nb_duck_alive = nb_duck;

	mouseCooldown += GetDeltaTime();
	startTimer += GetDeltaTime();

	for (int i = 0; i < nb_duck; i++)
	{
		if (Dog_jump >= 3 && ducks[i].duckState == WAIT)
		{
			ducks[i].duckState = FLY;
		}
		
		if (ducks[i].duckState >= FLY && ducks[i].duckState <DEAD)
		{
			ducks[i].animTimer += GetDeltaTime();


			ducks[i].flightTimer += GetDeltaTime() / 50.f * ducks[i].speed.x;


			if (ducks[i].duckPos.x <= 0.f)
			{
				ducks[i].duckVelocity.x = -0.1f;

				float rmd = (float)(iRand(-12, -4)) / 10;
				ducks[i].duckVelocity.x += rmd;



				if (ducks[i].duckPos.x <= 0.f)
				{
					ducks[i].duckPos.x = 10.f;
				}

			}
			if (ducks[i].duckPos.x >= 1920.f - ducks[i].duckRect.width * ducks[i].size)
			{
				ducks[i].duckVelocity.x = 0.1f;
				ducks[i].duckVelocity.x += (float)(iRand(4,12))/10;

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

			newPos = AddVectors(ducks[i].duckPos, CreateVector(MultiplyVector(ducks[i].duckVelocity, 50.f*ducks[i].speed.x * GetDeltaTime()), MultiplyVector(ducks[i].duckVelocity, 50.f * ducks[i].speed.y * GetDeltaTime())));

			ducks[i].duckPos = newPos;
			sfSprite_setPosition(ducks[i].duckSprite, ducks[i].duckPos);

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





			if (ducks[i].duckState >= FLY && ducks[i].duckState < DEAD)
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
					ducks[i].duckRect.top = 112 + 40 + 40;
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

		//printf("%f, %f\n", ducks[i].duckVelocity.x, ducks[i].duckVelocity.y);




		//Destroy
		sfVector2i mousePos = sfMouse_getPosition(_window);

		sfFloatRect rect = sfSprite_getGlobalBounds(ducks[i].duckSprite);

;

		shooting = 0;
		if (sfMouse_isButtonPressed(sfMouseLeft) && startTimer >1.f && Dog_jump >= 3)
		{
			if (mouseCooldown<0.001f)
			{
				makeSound(GUNSHOT);

			}
			//mouseCooldown = 0.f;
			if (mouseCooldown <0.1f)
			{

				shooting = 1;
				if (allowedToMiss == sfTrue)
				{
					misses += 1;
					allowedToMiss = sfFalse;
				}
	
			}
			else if (mouseCooldown > 1.f)
			{
				mouseCooldown = 0.f;
				allowedToMiss = sfTrue;

			}
			if (sfFloatRect_contains(&rect, (float)mousePos.x, (float)mousePos.y))
			{
	
				ducks[i].duckState = DEAD;
				ducks[i].deadDuckPos = ducks[i].duckPos;
			}

		}
		printf("%d\n", misses);

		if (misses >= nb_duck + 3)
		{
			gameState = MENUMOD;
		}


		if (ducks[i].duckState == DEAD)
		{
			ducks[i].deadTimer += GetDeltaTime();

			ducks[i].duckRect.top = 232;
			ducks[i].duckRect.height = 35;


			if (ducks[i].deadTimer >= 0.f)
			{
				if (ducks[i].duckPos.y < 840.f)
				{
					ducks[i].duckRect.left = 40.f + ducks[i].duckType * ducks[i].duckRect.width * 3;
					if (ducks[i].deadTimer >= 0.2f)
					{
						ducks[i].duckRect.left += 40.f;
						if (ducks[i].deadTimer >= 0.4f) ducks[i].deadTimer = 0.f;
					}
				}
			}
			else
			{
				ducks[i].duckRect.left = 0 + ducks[i].duckType * ducks[i].duckRect.width * 3;
			}


			sfSprite_setTextureRect(ducks[i].duckSprite, ducks[i].duckRect);

			if (ducks[i].deadTimer >= 0.f)
			{
				if (ducks[i].duckPos.y < 840.f)
				{
					ducks[i].duckPos = AddVectors(ducks[i].duckPos, MultiplyVector(vector2f(0.f, 1.f), 400.f * GetDeltaTime()));
				}
				else
				{
					nb_duck_alive--;
				}

				if (nb_duck_alive <= 0)
				{
					wavesState = NEXTWAVE;
				}
			}
			sfSprite_setPosition(ducks[i].duckSprite, ducks[i].duckPos);
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
