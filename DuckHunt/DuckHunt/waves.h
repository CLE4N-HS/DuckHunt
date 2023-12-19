#pragma once
#include "tools.h"

sfBool allowedToInitWaves;
int nb_waves;

void initWaves();
void updateWaves();
void displayWaves(sfRenderWindow* _window);