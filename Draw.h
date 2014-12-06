//The purpose of the Draw namespace is to draw a character and
//an area map in one function.

#pragma once
#include "Map.h"
#include "AreaMap.h"
#include "Character.h"
#include <vector>

namespace Draw{

    //Draw the Character and the AreaMap to the buffer.
    void drawArea(const AreaMap &areaMap , const Character &character);
    void drawBattle(Map &map , vector<Character*> characters , vector<Character*> enemies);
    void drawBattle(Map &map);
}