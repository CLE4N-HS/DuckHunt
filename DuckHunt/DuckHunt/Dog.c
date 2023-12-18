#include "Dog.h"

sfSprite* Dog;
sfTexture* Dog_t;
sfIntRect Dog_rect;

void init_dog()
{
	Dog = sfSprite_create();
	Dog_t = sfTexture_createFromFile(TEXTURE_PATH "all.png", NULL);
	sfSprite_setTexture(Dog, Dog_t,sfTrue);
	sfSprite_setPosition(Dog, vector2f(20.0f, 800.0f));
	sfSprite_setScale(Dog, vector2f(5.,5.));

	Dog_rect.top = 5;
	Dog_rect.left = 3;
	Dog_rect.height = 41;
	Dog_rect.width = 54;

	sfSprite_setTextureRect(Dog, Dog_rect);

}

void display_dog(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, Dog, NULL);
}