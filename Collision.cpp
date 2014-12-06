//The collision namespace is responsible for identifying any collisions between
//characters, tangibles, layers, and exits. 

#include "Collision.h"

//Check collisions with every possible collision of the character with the AreaMap.
bool Collision::characterToAreaMap(Character &character , AreaMap *&areaMap){

    bool result = false;

    //Check collisions with the collision layer.
    if(characterToLayer(character , areaMap->getLayer(CENTERGROUND)))
        result = true;

    //Check for collisions with exits.
    if(characterToExit(character , areaMap))
        result = true;

    //Check collisions with all the tangibles in the tangible vector.
    for(int i = 0 ; i < areaMap->getNumTangibles() ; i ++){

        int index = characterToTangible(character , areaMap->getTangible(i));;

        //Collision with tangible found.
        if(index != -1){
            character.setColl(index);
            result = true;
        }
    }

    return result;
}

//Check collisions between a character and a layer.
bool Collision::characterToLayer(Character &character , Layer &layer){

    bool result = false;

    ///////////////////////////Upper right////////////////////////////
    //Check collision with upper right corner and square to the right.
    if(getLayerVal(layer , getRow(character.getUpperRightY() , layer) , 
        getCol(character.getUpperRightX() + rate , layer)) > 0){
        
        character.setColl(RIGHT);
        result = true;
    }
    
    //Check collision with upper right corner and square above.
    if(getLayerVal(layer, getRow(character.getUpperRightY() - rate , layer) , 
        getCol(character.getUpperRightX() , layer)) > 0){
        
        character.setColl(UP);
        result = true;
    }

    ///////////////////////////Upper left////////////////////////////
    //Check collision with upper left corner and square to the left.
    if(getLayerVal(layer, getRow(character.getUpperLeftY() , layer) , 
        getCol(character.getUpperLeftX() - rate , layer)) > 0){
        
        character.setColl(LEFT);
        result = true;
    }

    //Check collision with upper left corner and square above.
    if(getLayerVal(layer, getRow(character.getUpperLeftY() - rate , layer) ,
        getCol(character.getUpperLeftX() , layer)) > 0){
        
        character.setColl(UP);
        result = true;
    }

    ///////////////////////////Lower left////////////////////////////
    //Check collision with lower left corner and square to the left.
    if(getLayerVal(layer, getRow(character.getLowerLeftY() , layer) , 
        getCol(character.getLowerLeftX() - rate , layer)) > 0){
        
        character.setColl(LEFT);
        result = true;
    }

    //Check collision with lower left corner and square below.
    if(getLayerVal(layer, getRow(character.getLowerLeftY() + rate , layer) , 
        getCol(character.getLowerLeftX() , layer)) > 0){
        
        character.setColl(DOWN);
        result = true;
    }
    
    ///////////////////////////Lower right////////////////////////////
    //Check collision with lower right corner and square to the right.
    if(getLayerVal(layer, getRow(character.getLowerRightY() , layer) , 
        getCol(character.getLowerRightX() + rate , layer)) > 0){
        
        character.setColl(RIGHT);
        result = true;
    }

    //Check collision with lower right corner and square below.
    if(getLayerVal(layer, getRow(character.getLowerRightY() + rate , layer) ,
        getCol(character.getLowerRightX() , layer)) > 0){
        
        character.setColl(DOWN);
        result = true;
    }
    
    return result;
}

//Check collisions between a character and a tangible.
int Collision::characterToTangible(Character &character , Tangible &tangible){

    if(character.getX() > tangible.getCX() + tangible.getCW() ||   //Check if left A is greater than right B 
       character.getX() + character.getW() < tangible.getCX() ||   //Check if right A is less than left B 
       character.getY() > tangible.getCY() + tangible.getCH() ||   //Check if top A is less than bottom B 
       character.getY() + character.getH() < tangible.getCY())     //Check if bottom A is greater than top B 
           return -1;
  
    else{
        
        //Left collision.
        if(character.getX() == (tangible.getCX() + tangible.getCW()))
            return LEFT;

        //Right collision.
        else if((character.getX() + character.getW()) == tangible.getCX())   
            return RIGHT;

        //Up collision.
        else if(character.getY() == (tangible.getCY() + tangible.getCH()))
            return UP;

        //Down collision.
        else if((character.getY() + character.getH()) == tangible.getCY())   
            return DOWN;

        //Error.
        else return -2;
    }
}

//Check collisions between a character and an exit.
bool Collision::characterToExit(Character &character , AreaMap *&areaMap){

    bool result = false;

    //Values to get to the center of the character.
    int collisionWOffset = character.getW() / 2;    
    int collisionHOffset = character.getH() / 2;

    //Values for collision test.
    int xValue = character.getUpperLeftX() + collisionWOffset;
    int yValue = character.getUpperLeftY() + collisionHOffset;

    //Loop through each possible exit.
    for(int i = 0 ; i < areaMap->getNumExits() ; i++){

        //Check each exit against the x and y value.
        if(getCol(xValue , *areaMap->getBackground()) == areaMap->getExitC(i) &&
           getRow(yValue , *areaMap->getBackground()) == areaMap->getExitR(i)){
            
            //Exit encounter.
            AreaMap *prevMap = areaMap;

            //Set map to the destination map.
            areaMap = areaMap->getToMap(i); 

            //Set the start point based off of the previous map's destination.
            Movement::setStart(character , *areaMap , prevMap->getExitDestC(i) , prevMap->getExitDestR(i));

            result = true;
        }
    }

    return true;
}

//Return the column value based off of the x coordinate.
int Collision::getCol(int xValue , const Layer &layer){

    if(xValue == 0)
        return 0;

    else if(xValue % layer.getTW() == 0)
        return xValue / layer.getTW() - 1; //Account for 0 index

    else return (xValue / layer.getTW());
}

//Return the row value based off of the y coordinate.
int Collision::getRow(int yValue , const Layer &layer){

    if(yValue == 0)
        return 0;

    else if(yValue % layer.getTH() == 0)
        return yValue / layer.getTH() - 1; //Account for 0 index

    else return (yValue / layer.getTH());
}

//Return the layer value for that row and column combination.
int Collision::getLayerVal(const Layer &layer , int row , int col){
    
    return layer.getLayoutVal(row * layer.getNumCols() + col);
}