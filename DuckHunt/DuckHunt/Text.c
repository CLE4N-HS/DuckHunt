#include "Text.h"

sfText* text;
sfFont* font;

sfText* bullets;
char* bullets_char = "bullets";
sfVector2f text_pos;
char nombre[4] = "3";
int tmp;

void init_text()
{

	text_pos.x = 10.f;
	text_pos.y = 1000.f;

	text = sfText_create();
	bullets = sfText_create();

	font = sfFont_createFromFile("..//Ressources//Fonts//Arcadeclassic.ttf");


	sfText_setFont(text, font);
	sfText_setFont(bullets, font);

	//sprintf(nombre, "%d", tmp);
	sfText_setString(text, nombre);
	sfText_setString(bullets, bullets_char);

	sfText_setFillColor(text, sfBlack);
	sfText_setFillColor(bullets, sfBlack);

	sfText_setPosition(text, vector2f(text_pos.x+180.f, text_pos.y));
	sfText_setPosition(bullets, text_pos);

}

void update_text()
{
	int result = nb_duck+3 - misses;
	if (result < 0)result += 1;
	sprintf(nombre, "%d", result);
	sfText_setString(text, nombre);
}

void display_text(sfRenderWindow* _window)
{
	if (Dog_jump == 3)
	{
		sfRenderWindow_drawText(_window, text, NULL);
		sfRenderWindow_drawText(_window, bullets, NULL);
	}
}