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

        bool collision = characterToTangible(character , areaMap->getTangible(i) ,
            gameManager);

        //Collision with tangible found.
        if(collision){

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
        getCol(character.getUpperRightX() + PLAYER_MOVE_RATE , layer)) > 0){
        
        character.setColl(RIGHT);
        result = true;
    }
    
    //Check collision with upper right corner and square above.
    if(getLayerVal(layer, getRow(character.getUpperRightY() - PLAYER_MOVE_RATE , layer) , 
        getCol(character.getUpperRightX() , layer)) > 0){
        
        character.setColl(UP);
        result = true;
    }

    ///////////////////////////Upper left////////////////////////////
    //Check collision with upper left corner and square to the left.
    if(getLayerVal(layer, getRow(character.getUpperLeftY() , layer) , 
        getCol(character.getUpperLeftX() - PLAYER_MOVE_RATE , layer)) > 0){
        
        character.setColl(LEFT);
        result = true;
    }

    //Check collision with upper left corner and square above.
    if(getLayerVal(layer, getRow(character.getUpperLeftY() - PLAYER_MOVE_RATE , layer) ,
        getCol(character.getUpperLeftX() , layer)) > 0){
        
        character.setColl(UP);
        result = true;
    }

    ///////////////////////////Lower left////////////////////////////
    //Check collision with lower left corner and square to the left.
    if(getLayerVal(layer, getRow(character.getLowerLeftY() , layer) , 
        getCol(character.getLowerLeftX() - PLAYER_MOVE_RATE , layer)) > 0){
        
        character.setColl(LEFT);
        result = true;
    }

    //Check collision with lower left corner and square below.
    if(getLayerVal(layer, getRow(character.getLowerLeftY() + PLAYER_MOVE_RATE , layer) , 
        getCol(character.getLowerLeftX() , layer)) > 0){
        
        character.setColl(DOWN);
        result = true;
    }
    
    ///////////////////////////Lower right////////////////////////////
    //Check collision with lower right corner and square to the right.
    if(getLayerVal(layer, getRow(character.getLowerRightY() , layer) , 
        getCol(character.getLowerRightX() + PLAYER_MOVE_RATE , layer)) > 0){
        
        character.setColl(RIGHT);
        result = true;
    }

    //Check collision with lower right corner and square below.
    if(getLayerVal(layer, getRow(character.getLowerRightY() + PLAYER_MOVE_RATE , layer) ,
        getCol(character.getLowerRightX() , layer)) > 0){
        
        character.setColl(DOWN);
        result = true;
    }
    
    return result;
}

//Check collisions between a character and a tangible.
bool Collision::characterToTangible(Character &character , Tangible &tangible ,
    GameManager *gameManager){

    int characterLeft = character.getX();
    int characterRight = character.getX() + character.getW();
    int characterTop = character.getY();
    int characterBottom = character.getY() + character.getH();

    int tangibleLeft = tangible.getDX();
    int tangibleRight = tangible.getDX() + tangible.getCW();
    int tangibleTop =  tangible.getDY();
    int tangibleBottom = tangible.getDY() + tangible.getCH();

    if(characterLeft > tangibleRight ||   //Check if character left is greater than tangible right
       characterRight < tangibleLeft ||   //Check if character right is less than tangible left
       characterTop > tangibleBottom ||   //Check if character top is less than tangible bottom
       characterBottom < tangibleTop){     //Check if character bottom is greater than tangible top
           return false;
    }

    else{

        //Collision with tangible on the left.
        if(characterLeft < tangibleRight && characterLeft > tangibleLeft ){

            if(gameManager->pressedKey == SPACE && character.getFacing() == LEFT){
                    
                tangible.playCutscene(gameManager->pressedKey);
            }

            character.setColl(LEFT);
        }

        //Collision with tangible on the right.
        if(characterRight < tangibleRight && characterRight > tangibleLeft ){
                
            if(gameManager->pressedKey == SPACE && character.getFacing() == RIGHT){

                tangible.playCutscene(gameManager->pressedKey);
            }

            character.setColl(RIGHT);
        }
            
        //Collision with tangible above.
        if(characterTop < tangibleBottom && characterTop > tangibleTop){

            if(gameManager->pressedKey == SPACE && character.getFacing() == UP){

                tangible.playCutscene(gameManager->pressedKey);
            }
                    
            character.setColl(UP);

        }

        //Collison with tangible below.
        if((characterBottom < tangibleBottom && characterBottom > tangibleTop)){
                
            if(gameManager->pressedKey == SPACE && character.getFacing() == DOWN){

                tangible.playCutscene(gameManager->pressedKey);                    
            }
                
            character.setColl(DOWN);
        }
        return true;
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

            gameManager->getMusicBox()->playSong(areaMap->getMapMusic());

            //Set battleMap.
            gameManager->battleMap = areaMap->getBattleMap();

            //Set the start point based off of the previous map's destination.
            Movement::setStartCoords(character , *areaMap ,
                Conversion::convertTilesToPixels(prevMap->getExitDestC(i)) ,
                Conversion::convertTilesToPixels(prevMap->getExitDestR(i)));

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