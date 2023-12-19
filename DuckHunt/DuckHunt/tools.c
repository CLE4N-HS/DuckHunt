#include "tools.h"

sfVector2f vector2f(float _x, float _y)
{
    sfVector2f v = { _x, _y };
    return v;
}

int iRand(int _min, int _max)
{
    return rand() % (_max - _min + 1) + _min;
}

void initTools()
{
    sfclock = sfClock_create();
    srand(time(NULL));
}

void restartClock()
{
    sftime = sfClock_restart(sfclock);
}

float GetDeltaTime()
{
    if (sfTime_asSeconds(sftime) > 1.0f) return 1.0f;
    return sfTime_asSeconds(sftime);
}

/// <summary>
/// Create a vector using 2 points
/// </summary>
/// <param name="_pos1">Start point</param>
/// <param name="_pos2">End point</param>
/// <returns>The new vector</returns>
sfVector2f CreateVector(sfVector2f _pos1, sfVector2f _pos2)
{
    sfVector2f v = { (_pos2.x - _pos1.x) , (_pos2.y - _pos1.y) };
    return v;
}

sfVector2f AddVectors(sfVector2f _v1, sfVector2f _v2)
{
    sfVector2f v = { _v1.x + _v2.x, _v1.y + _v2.y };
    return v;
}

sfVector2f SubstractVectors(sfVector2f _v1, sfVector2f _v2)
{
    sfVector2f v = { _v2.x - _v1.x, _v2.y - _v1.y };
    return v;
}

float DotProduct(sfVector2f _v1, sfVector2f _v2)
{
    float d = (_v1.x * _v2.x + _v1.y * _v2.y);
    return d;
}

float GetMagnitude(sfVector2f _vector)
{
    float m = sqrtf(_vector.x * _vector.x + _vector.y * _vector.y);
    return m;
}

sfVector2f Normalize(sfVector2f _vector)
{
    float magnitude = GetMagnitude(_vector);
    sfVector2f v = { _vector.x / magnitude, _vector.y / magnitude };
    return v;
}

float GetSqrMagnitude(sfVector2f _vector)
{
    float m = (_vector.x * _vector.x + _vector.y * _vector.y);
    return m;
}

sfVector2f MultiplyVector(sfVector2f _vector, float _multiply)
{
    sfVector2f v = { _vector.x * _multiply, _vector.y * _multiply };
    return v;
}

sfBool Equals(sfVector2f _v1, sfVector2f _v2)
{
    float xOffset = _v2.x - _v1.x;
    float yOffset = _v2.y - _v1.y;

    if (abs(xOffset) < EPSILON && abs(yOffset) <EPSILON)
    {
        return sfTrue;
    }
    return sfFalse;
}

float Lerp(float a, float b, float t)
{
    return (b - a) * t + a;
}