#include "tools.h"

void main()
{
	sfVideoMode mode = { 1920, 1080, 32 };
	sfRenderWindow* window;
	window = sfRenderWindow_create(mode, "Window", sfDefaultStyle, NULL);

	initTools();
	initMenu();
	init_dog();

	init_background();





	sfEvent event;

	while (sfRenderWindow_isOpen(window))
	{
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
			{
				sfRenderWindow_close(window);
			}
		}
		
		if (gameState == MENUMOD)
		{
			updateMenu(window);
		}
		else if (gameState == EASYMOD || gameState == HARDMOD)
		{
			//update bg (non pas toi, je parlais du background)
		}



		sfRenderWindow_clear(window, sfBlack);

		if (gameState == MENUMOD)
		{
			displayMenu(window);
		}
		else if (gameState == EASYMOD || gameState == HARDMOD)
		{
			draw_background(window); //c'est display pd (oui l� je parle de toi)
			display_dog(window);
		}

		sfRenderWindow_display(window);

		if (sfKeyboard_isKeyPressed(sfKeyEscape) && gameState != MENUMOD)
		{
			gameState = MENUMOD;
		}
	}
}