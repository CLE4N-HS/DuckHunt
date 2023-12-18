#include "tools.h"

void main()
{
	sfVideoMode mode = { 1920, 1080, 32 };
	sfRenderWindow* window;
	window = sfRenderWindow_create(mode, "Window", sfFullscreen, NULL);

	initTools();
	initMenu();

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

		updateMenu(window);



		sfRenderWindow_clear(window, sfBlack);

		if(sfKeyboard_isKeyPressed(sfKeySpace)) displayMenu(window);
		else draw_background(window);
		sfRenderWindow_display(window);

		if (sfKeyboard_isKeyPressed(sfKeyEscape))
		{
			exit(0);
		}
	}
}