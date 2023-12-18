#include "menu.h"

sfSprite* easySprite;
sfSprite* hardSprite;
sfSprite* quitSprite;
sfSprite* title;
sfSprite* arrowSprite;

sfTexture* easyTexture;
sfTexture* hardTexture;
sfTexture* quitTexture;
sfTexture* titleTexture;
sfTexture* arrowTexture;

void initMenu()
{
	title = sfSprite_create();
	titleTexture = sfTexture_createFromFile(TEXTURE_PATH"title.png", NULL);
	sfSprite_setTexture(title, titleTexture, sfTrue);
	sfSprite_setScale(title, vector2f(4.f, 4.f));
	sfSprite_setPosition(title, vector2f(340.f, 40.f));

	easySprite = sfSprite_create();
	easyTexture = sfTexture_createFromFile(TEXTURE_PATH"easyText.png", NULL);
	sfSprite_setTexture(easySprite, easyTexture, sfTrue);
	sfSprite_setPosition(easySprite, vector2f(412.f, 720.f));

	hardSprite = sfSprite_create();
	hardTexture = sfTexture_createFromFile(TEXTURE_PATH"hardText.png", NULL);
	sfSprite_setTexture(hardSprite, hardTexture, sfTrue);
	sfSprite_setPosition(hardSprite, vector2f(1233.f, 720.f));

	quitSprite = sfSprite_create();
	quitTexture = sfTexture_createFromFile(TEXTURE_PATH"quitText.png", NULL);
	sfSprite_setTexture(quitSprite, quitTexture, sfTrue);
	sfSprite_setPosition(quitSprite, vector2f(829.f, 900.f));

	arrowSprite = sfSprite_create();
	arrowTexture = sfTexture_createFromFile(TEXTURE_PATH"arrowText.png", NULL);
	sfSprite_setTexture(arrowSprite, arrowTexture, sfTrue);
	sfSprite_setPosition(arrowSprite, vector2f(829.f, 900.f));
}

void updateMenu()
{
}

void displayMenu(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, title, NULL);
	sfRenderWindow_drawSprite(_window, easySprite, NULL);
	sfRenderWindow_drawSprite(_window, hardSprite, NULL);
	sfRenderWindow_drawSprite(_window, quitSprite, NULL);
}
