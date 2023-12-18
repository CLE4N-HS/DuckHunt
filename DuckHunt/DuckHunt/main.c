#include "tools.h"

void main()
{
	sfVideoMode mode = { 800, 600, 32 };
	sfRenderWindow* window;
	window = sfRenderWindow_create(mode, "Window", sfDefaultStyle, NULL);




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

		sfRenderWindow_clear(window, sfBlue);



		sfRenderWindow_display(window);
	}
}