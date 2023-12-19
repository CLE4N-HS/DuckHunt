#include "Dog.h"

sfSprite* Dog;
sfTexture* Dog_t;
sfIntRect Dog_rect;

sfVector2f Dog_pos;

sfBool Dog_is_walking;
int FrameX = 0;
int FrameY = 0;
int Dog_smell;
int Dog_jump;


float timer_beginning_dog;

void init_dog()
{
	Dog_init = sfTrue;
	Dog_is_walking = sfTrue;
	Dog_is_behind = sfFalse;
	Dog_smell = 0;
	Dog_jump = 0;
	Dog_pos.x = -150.0f ;
	Dog_pos.y = 800.0f ;
	Dog = sfSprite_create();
	Dog_t = sfTexture_createFromFile(TEXTURE_PATH "Dog.png", NULL);
	sfSprite_setTexture(Dog, Dog_t,sfTrue);
	sfSprite_setPosition(Dog, Dog_pos);
	sfSprite_setScale(Dog, vector2f(5.,5.));

	Dog_rect.top = 0;
	Dog_rect.left = 0;
	Dog_rect.height = 44;
	Dog_rect.width = 55;

	sfSprite_setTextureRect(Dog, Dog_rect);

	
}

int beginning_dog()
{
	if(Dog_init) Dog_init = sfFalse;
	timer_beginning_dog += GetDeltaTime();
	if (Dog_is_walking)
	{
		Dog_pos.x += 150.f * GetDeltaTime();
		if (timer_beginning_dog > 0.5f)
		{
			Dog_rect.left += 55;
			if (Dog_rect.left >= 220) Dog_rect.left = 55;
			timer_beginning_dog = 0;
		}
	}
	sfSprite_setPosition(Dog, Dog_pos);
	sfSprite_setTextureRect(Dog, Dog_rect);
	if (Dog_pos.x > 710.f)
	{	
		Dog_is_walking = sfFalse;
		if (Dog_smell < 5)
		{
			if (timer_beginning_dog > 0.5f)
			{
				Dog_rect.left += 55;
				if (Dog_rect.left >= 275) Dog_rect.left = 165;
				timer_beginning_dog = 0;
				Dog_smell++;
			}
		}
		else
		{
			if (Dog_jump == 0)
			{
				Dog_rect.top = 59;
				Dog_rect.height = 48;
				Dog_rect.left = 0;
				Dog_pos.y = 795.f;
				Dog_jump = 1;
			}
			if (timer_beginning_dog > 1.f && Dog_jump ==1)
			{
				Dog_pos.y -= 350.f * GetDeltaTime();
				Dog_rect.left = 55;
				if (Dog_pos.y < 500.f)
				{
					Dog_jump = 2;
					timer_beginning_dog = 0;
				}
			}
			else if(timer_beginning_dog > 0.005f && Dog_jump == 2)
			{
				Dog_is_behind = sfTrue;
				Dog_rect.left = 110;
				Dog_pos.y += 200.f * GetDeltaTime();
				if (Dog_pos.y > 950)
					Dog_jump = 3;
			}
		}
	}

}

void display_dog(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, Dog, NULL);
}