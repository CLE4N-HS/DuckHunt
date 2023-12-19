#include "tools.h"

void main()
{
	sfVideoMode mode = { 1920, 1080, 32 };
	sfRenderWindow* window;
	window = sfRenderWindow_create(mode, "Window", sfFullscreen, NULL);

	initTools();
	initMenu();
	init_dog();
	init_shader();

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
			//update bg (non pas toi, je parlais du background)// Ptn tu m'as eu
			beginning_dog();
			update_shader(window);
		}



		sfRenderWindow_clear(window, sfBlack);

		if (gameState == MENUMOD)
		{
			displayMenu(window);
		}
		else if (gameState == EASYMOD || gameState == HARDMOD)
		{
			draw_background(window); //c'est display pd (oui là je parle de toi)
			display_shader(window);
		}

		sfRenderWindow_display(window);

		if (sfKeyboard_isKeyPressed(sfKeyEscape) && gameState != MENUMOD)
		{
			gameState = MENUMOD;
		}
	}
}