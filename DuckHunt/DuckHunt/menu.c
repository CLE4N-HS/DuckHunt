#include "menu.h"

int ButtonMod = 0;

typedef enum Buttons
{
	NOBUTTON = 0,
	EASYBUTTON,
	HARDBUTTON,
	QUITBUTTON
};

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

sfVector2f easyPos;
sfVector2f hardPos;
sfVector2f quitPos;
sfVector2f titlePos;
sfVector2f arrowPos;

void initMenu()
{
	gameState = MENUMOD;

	title = sfSprite_create();
	titleTexture = sfTexture_createFromFile(TEXTURE_PATH"title.png", NULL);
	sfSprite_setTexture(title, titleTexture, sfTrue);
	sfSprite_setScale(title, vector2f(4.f, 4.f));
	titlePos = vector2f(340.f, 40.f);
	sfSprite_setPosition(title, titlePos);

	easySprite = sfSprite_create();
	easyTexture = sfTexture_createFromFile(TEXTURE_PATH"easyText.png", NULL);
	sfSprite_setTexture(easySprite, easyTexture, sfTrue);
	easyPos = vector2f(412.f, 720.f);
	sfSprite_setPosition(easySprite, easyPos);

	hardSprite = sfSprite_create();
	hardTexture = sfTexture_createFromFile(TEXTURE_PATH"hardText.png", NULL);
	sfSprite_setTexture(hardSprite, hardTexture, sfTrue);
	hardPos = vector2f(1233.f, 720.f);
	sfSprite_setPosition(hardSprite, hardPos);

	quitSprite = sfSprite_create();
	quitTexture = sfTexture_createFromFile(TEXTURE_PATH"quitText.png", NULL);
	sfSprite_setTexture(quitSprite, quitTexture, sfTrue);
	quitPos = vector2f(829.f, 900.f);
	sfSprite_setPosition(quitSprite, quitPos);

	arrowSprite = sfSprite_create();
	arrowTexture = sfTexture_createFromFile(TEXTURE_PATH"arrowText.png", NULL);
	sfSprite_setTexture(arrowSprite, arrowTexture, sfTrue);
	arrowPos = vector2f(0.f, 0.f);
	sfSprite_setPosition(arrowSprite, arrowPos);
}

void updateMenu(sfRenderWindow* _window)
{
	sfVector2i mousePos = sfMouse_getPositionRenderWindow(_window);

	sfFloatRect easyRect = sfSprite_getGlobalBounds(easySprite);
	sfFloatRect hardRect = sfSprite_getGlobalBounds(hardSprite);
	sfFloatRect quitRect = sfSprite_getGlobalBounds(quitSprite);


	if (sfFloatRect_contains(&easyRect, mousePos.x, mousePos.y))
	{
		ButtonMod = EASYBUTTON;
		sfSprite_setPosition(arrowSprite, vector2f(easyPos.x - 80.f, easyPos.y));
		if (sfMouse_isButtonPressed(sfMouseLeft))
		{
			gameState = EASYMOD;
		}
	}

	else if (sfFloatRect_contains(&hardRect, mousePos.x, mousePos.y))
	{
		ButtonMod = HARDBUTTON;
		sfSprite_setPosition(arrowSprite, vector2f(hardPos.x - 80.f, hardPos.y));
		if (sfMouse_isButtonPressed(sfMouseLeft))
		{
			gameState = HARDMOD;
		}
	}

	else if (sfFloatRect_contains(&quitRect, mousePos.x, mousePos.y))
	{
		ButtonMod = QUITBUTTON;
		sfSprite_setPosition(arrowSprite, vector2f(quitPos.x - 80.f, quitPos.y));
		if (sfMouse_isButtonPressed(sfMouseLeft))
		{
			gameState = QUITBUTTON;
		}
	}

	else ButtonMod = NOBUTTON;

}

void displayMenu(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, title, NULL);
	sfRenderWindow_drawSprite(_window, easySprite, NULL);
	sfRenderWindow_drawSprite(_window, hardSprite, NULL);
	sfRenderWindow_drawSprite(_window, quitSprite, NULL);

	if (ButtonMod != NOBUTTON) sfRenderWindow_drawSprite(_window, arrowSprite, NULL);
}
