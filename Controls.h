//The controls namespace is used for taking in key presses
//from the user.

#pragma once
#include <allegro5\allegro.h>
#include "Enums.h"
using namespace std;

int getKeyboardInput(ALLEGRO_EVENT *ev , bool *keys);   //Return the key represented as an int.
void resetKeys(bool *keys);                             //Reset keys to false.

