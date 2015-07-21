//The purpose of the Movement namespace is to control the movements
//between the Character and the AreaMap.

#pragma once
#include "Character.h"
#include "Layer.h"
#include "Tangible.h"
#include "AreaMap.h"
#include "I_Manager.h"

namespace Movement{

    //Move map based off of the key that was pressed and the keys already pressed.
    bool moveMap(Character &character , AreaMap &areaMap , int theKey , bool keys[] , 
        I_Manager *battleManager);

    //Set player and map to a specified x coordinate and y coordinate.
    bool setStartCoords(Character &character , AreaMap &areaMap , int x , int y);

    //Moves the map and player up.
    void moveUp(Character &character , AreaMap &areaMap , int theKey , bool keys[]);

    //Moves the map and player down.
    void moveDown(Character &character , AreaMap &areaMap , int theKey , bool keys[]);

    //Moves the map and player left.
    void moveLeft(Character &character , AreaMap &areaMap , int theKey , bool keys[]);

    //Moves the map and player right.
    void moveRight(Character &character , AreaMap &areaMap , int theKey , bool keys[]);
}