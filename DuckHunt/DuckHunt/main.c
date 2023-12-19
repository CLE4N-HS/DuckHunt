#include "tools.h"

void main()
{
	sfVideoMode mode = { 1920, 1080, 32 };
	sfRenderWindow* window;
	window = sfRenderWindow_create(mode, "Window", sfDefaultStyle, NULL);

	initTools();
	initMenu();

	init_dog();
	init_shader();

	Ducks* ducks = initDuck(10);

	init_background();





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

		
		if (gameState == MENUMOD)
		{
			if (!Dog_init) init_dog();
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
			draw_background(window);
			display_shader(window);
			displayDuck(window, ducks);
		}

		sfRenderWindow_display(window);

		if (sfKeyboard_isKeyPressed(sfKeyEscape) && gameState != MENUMOD)
		{
			gameState = MENUMOD;
		}
	}
}