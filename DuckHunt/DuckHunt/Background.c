#include "Background.h"


void init_background()
{
	background = sfSprite_create();
	background_t = sfTexture_createFromFile( TEXTURE_PATH"fondtree.png", NULL);
	sfSprite_setTexture(background, background_t, sfTrue);
	sfSprite_setScale(background, vector2f(2.5,2.5));
	sfSprite_setPosition(background, vector2f(0.f,0.f));

	grass_wall = sfSprite_create();
	grass_wall_t = sfTexture_createFromFile(TEXTURE_PATH"fond.png", NULL);
	sfSprite_setTexture(grass_wall, grass_wall_t, sfTrue);
	sfSprite_setScale(grass_wall, vector2f(2.5, 2.5));
	sfSprite_setPosition(grass_wall, vector2f(0.f, 760.f));
}

void draw_background(sfRenderWindow* _window)
{
	
	sfRenderWindow_drawSprite(_window, background, NULL);
	if (Dog_is_behind)
	{
		display_dog(_window);
		//displayDuck(_window, newducks);
		sfRenderWindow_drawSprite(_window, grass_wall, NULL);
	}
	else
	{
		//displayDuck(_window, newducks);
		sfRenderWindow_drawSprite(_window, grass_wall, NULL);
		display_dog(_window);
	}
	

}