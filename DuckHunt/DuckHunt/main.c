#include "tools.h"

void main()
{
	sfVideoMode mode = { 1920, 1080, 32 };
	sfRenderWindow* window;
	window = sfRenderWindow_create(mode, "Window", sfDefaultStyle, NULL);

	initTools();
	initMenu();

	Ducks* ducks = initDuck(1);


	init_dog();
	init_shader();


	init_background();
	initWaves();

	initMusic();

	updateMusic();





	sfEvent event;

	while (sfRenderWindow_isOpen(window))
	{
		restartClock();

		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
			{
				sfRenderWindow_close(window);
			}
		}
		if (sfMouse_isButtonPressed(sfMouseLeft))
		{

			makeSound(GUNSHOT);
		}

		
		if (gameState == MENUMOD)
		{
			if (Dog_init)
			{
				init_dog();
				Dog_init = sfFalse;
			}
			if (allowedToInitDucks)
			{
				ducks = initDuck(1);
				allowedToInitDucks = sfFalse;
			}
			if (allowedToInitWaves)
			{
				initWaves();
				allowedToInitWaves = sfFalse;
			}
			updateMenu(window);
		}
		else if (gameState == EASYMOD || gameState == HARDMOD)
		{

			beginning_dog();
			update_shader(window);
			updateDuck(window, ducks);

		}



		sfRenderWindow_clear(window, sfBlack);

		if (gameState == MENUMOD)
		{
			displayMenu(window);
		}
		else if (gameState == EASYMOD || gameState == HARDMOD)
		{
			sfRenderWindow_drawSprite(window, background, NULL);
			if (Dog_is_behind)
			{
				display_dog(window);
				displayDuck(window, ducks);
				sfRenderWindow_drawSprite(window, grass_wall, NULL);
			}
			else
			{
				displayDuck(window, ducks);
				sfRenderWindow_drawSprite(window, grass_wall, NULL);
				display_dog(window);
			}
			display_shader(window);
		}

		if (wavesState == NEXTWAVE)
		{
			ducks = initDuck(nb_waves+1);
		}
		updateWaves();



		sfRenderWindow_display(window);

		if (sfKeyboard_isKeyPressed(sfKeyEscape) && gameState != MENUMOD)
		{
			gameState = MENUMOD;
		}
	}
}