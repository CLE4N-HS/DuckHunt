#include "Dog.h"

sfSprite* Dog;
sfTexture* Dog_t;
sfIntRect* Dog_rect;

void init_dog()
{
	Dog = sfSprite_create();
	Dog_t = sfTexture_createFromFile(TEXTURE_PATH "all.png", NULL);
	sfSprite_setTexture(Dog, Dog_t,sfTrue);
	sfSprite_setPosition(Dog, vector2f(0.0f, 0.0f));
}