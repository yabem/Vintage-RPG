//The collision namespace is responsible for identifying any collisions between
//characters, tangibles, layers, and exits. 

#include "Collision.h"

//Check collisions with every possible collision of the character with the AreaMap.
bool Collision::characterToAreaMap(Character &character , AreaMap *&areaMap ,
    GameManager *gameManager){

    bool result = false;

    //Check collisions with the collision layer.
    if(characterToLayer(character , areaMap->getLayer(CENTERGROUND)))
        result = true;

    //Check for collisions with exits.
    if(characterToExit(character , areaMap , gameManager))
        result = true;

    //Check collisions with all the tangibles in the tangible vector.
    for(int i = 0 ; i < areaMap->getNumTangibles() ; i ++){

        int index = characterToTangible(character , areaMap->getTangible(i) ,
            gameManager);

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
int Collision::characterToTangible(Character &character , Tangible &tangible ,
    GameManager *gameManager){

    if(character.getX() > tangible.getDX() + tangible.getCW()  ||   //Check if left A is greater than right B 
       character.getX() + character.getW() < tangible.getDX() ||   //Check if right A is less than left B 
       character.getY() > tangible.getDY() + tangible.getCH()  ||   //Check if top A is less than bottom B 
       character.getY() + character.getH() < tangible.getDY())     //Check if bottom A is greater than top B 
           return -1;

    else{
        
        switch(character.getFacing()){

            //Collision with tangible on the left.
            case LEFT:
            if((character.getX() < tangible.getDX() + tangible.getW() &&
                character.getX() > tangible.getDX())){

                if(gameManager->pressedKey == SPACE)
                    tangible.playCutscene(gameManager->pressedKey);
                    
                return LEFT;
            }
                break;
            

            //Collision with tangible on the right.
            case RIGHT:
            if((character.getX() + character.getW()) < tangible.getDX() +
                tangible.getW() && (character.getX() + character.getW()) >
                tangible.getDX()){
                
                    if(gameManager->pressedKey == SPACE)
                        tangible.playCutscene(gameManager->pressedKey);

                return RIGHT;
            }
                break;
            
            //Collision with tangible above.
            case UP:
            if((character.getY() < (tangible.getDY() + tangible.getH()) &&
                character.getY() > tangible.getDY())){

                if(gameManager->pressedKey == SPACE)
                    tangible.playCutscene(gameManager->pressedKey);
                    
                return UP;
            }
                break;
            
            
            //Collision with tangible below.
            case DOWN:
            if((character.getY() + character.getH() < tangible.getDY() +
                tangible.getH() && character.getY() + character.getH() >
                tangible.getDY())){
                
                if(gameManager->pressedKey == SPACE)
                    tangible.playCutscene(gameManager->pressedKey);                    
                
                return DOWN;
            }
                break;
            
            
        //Error.
            default:
                return -2;
                break;
        }
    }
}

//Check collisions between a character and an exit.
bool Collision::characterToExit(Character &character , AreaMap *&areaMap ,
    GameManager *gameManager){

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

            //Set battleMap.
            gameManager->battleMap = areaMap->getBattleMap();

            //Set the start point based off of the previous map's destination.
            Movement::setStartCoords(character , *areaMap ,
                PixelConversion::convertTilesToPixels(prevMap->getExitDestC(i)) ,
                PixelConversion::convertTilesToPixels(prevMap->getExitDestR(i)));

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