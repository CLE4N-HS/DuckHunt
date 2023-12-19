#include "Shader.h"

sfShader* shader;
sfRenderStates renderState;

sfRectangleShape* rectangle;
sfVector2f mouse_pos;

float timer_shader;
int shooting = 0;
void init_shader()
{
	shader = NULL;

	rectangle = sfRectangleShape_create();
	sfRectangleShape_setFillColor(rectangle, sfWhite);
	sfRectangleShape_setSize(rectangle, vector2f(1920, 1080));
	sfCircleShape_setPosition(rectangle, vector2f(0.0f, 0.0f));
	sfCircleShape_setScale(rectangle, vector2f(1.f, 1.f));

	if (!sfShader_isAvailable())
	{
		printf("shader impossible !");
		return EXIT_FAILURE;
	}
	else
	{
		shader = sfShader_createFromFile(NULL, NULL, "Shader.frag");
		if (shader == NULL)
			return EXIT_FAILURE;
		renderState.shader = shader;
		renderState.blendMode = sfBlendAlpha;
		renderState.transform = sfTransform_Identity;
		renderState.texture = NULL;

	}
}

void update_shader(sfRenderWindow* _window)
{
	if (sfKeyboard_isKeyPressed(sfKeySpace))shooting = 1;
	else shooting = 0;

	timer_shader += GetDeltaTime();
	sfShader_setCurrentTextureUniform(shader, "u_Texture");
	sfShader_setIvec2Uniform(shader, "mouse_pos", sfMouse_getPosition(_window));
	sfShader_setFloatUniform(shader, "Timer", timer_shader);
	sfShader_setIntUniform(shader, "is_shooting", shooting);
	sfShader_setVec2Uniform(shader, "iResolution", vector2f(1920.f, 1080.f));

}

void display_shader(sfRenderWindow* _window)
{
	sfRenderWindow_drawRectangleShape(_window, rectangle, &renderState);
}