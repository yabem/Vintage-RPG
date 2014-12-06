//The collision namespace is responsible for identifying any collisions between
//characters, tangibles, layers, and exits. 

#pragma once
#include "Character.h"
#include "Layer.h"
#include "Tangible.h"
#include "AreaMap.h"
#include "Movement.h"

namespace Collision{

    //Check collisions with every possible collision of the character with the AreaMap.
    bool characterToAreaMap(Character &character , AreaMap *&areaMap);

    //Check collisions between a character and a layer.
    bool characterToLayer(Character &character , Layer &layer);

    //Check collisions between a character and a tangible.
    int characterToTangible(Character &character , Tangible &tangible);

    //Check collisions between a character and an exit.
    bool characterToExit(Character &character , AreaMap *&areaMap);

    int getCol(int xValue , const Layer &layer);    //Return the column value based off of the x coordinate.
    int getRow(int yValue , const Layer &layer);    //Return the row value based off of the y coordinate.
    
    //Return the layer value for that row and column combination.
    int getLayerVal(const Layer &layer , int row , int col);    
}