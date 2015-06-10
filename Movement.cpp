//The purpose of the Movement namespace is to control the movements
//between the Character and the AreaMap.

#include "Movement.h"

//Move map based off of the key that was pressed and the keys already pressed.
bool Movement::moveMap(Character &character , AreaMap &areaMap , int theKey , bool keys[]){
    
    switch(theKey){
    
        case UP:
            Movement::moveUp(character , areaMap , theKey , keys);
            break;

        case DOWN:
            Movement::moveDown(character , areaMap , theKey , keys);
            break;
        
        case LEFT:
            Movement::moveLeft(character , areaMap , theKey , keys);
            break;

        case RIGHT:        
            Movement::moveRight(character , areaMap , theKey , keys);
            break;
        
        default:
            return false;   //Invalid entry.
    }
    
    return true;
}

//Moves the map and player up.
void Movement::moveUp(Character &character , AreaMap &areaMap , int theKey , bool keys[]){

    //Boundary check.
    if(areaMap.getLayer(BACKGROUND).getDY() < 0 && character.getY() <= SCREEN_H /2 &&
        character.getCollision(UP) != true){

        //Move map.
        for(int i = 0 ; i < areaMap.getNumLayers() ; i++)
            areaMap.getLayer(i).addToDY(rate);

        character.setFacing(UP);
        character.addToAllCornerY(-rate);

        for(int i = 0 ; i < areaMap.getNumTangibles() ; i++)
            areaMap.getTangible(i).addToDY(rate);
    }
    else{
        //Move character.
        if(character.move(keys , theKey) != -1)
            character.addToAllCornerY(-rate); 
    }
}

//Moves the map and player down.
void Movement::moveDown(Character &character , AreaMap &areaMap , int theKey , bool keys[]){

    //Boundary check.
    if(areaMap.getLayer(BACKGROUND).getDY() + areaMap.getLayer(BACKGROUND).getH() > SCREEN_H &&
        character.getY() >= SCREEN_H /2 && character.getCollision(DOWN) != true){
                    
        //Move map.
        for(int i = 0 ; i < areaMap.getNumLayers() ; i++)
            areaMap.getLayer(i).addToDY(-rate);
            
        character.addToAllCornerY(rate);        
        character.setFacing(DOWN);
                    
        for(int i = 0 ; i < areaMap.getNumTangibles() ; i++)
            areaMap.getTangible(i).addToDY(-rate);
    }

    else{          
        //Move character.
        if(character.move(keys , theKey) != -1)
            character.addToAllCornerY(rate);
    }
}

//Moves the map and player left.
void Movement::moveLeft(Character &character , AreaMap &areaMap , int theKey , bool keys[]){

    //Boundary check.
    if(areaMap.getLayer(BACKGROUND).getDX() < 0 && character.getX() <= SCREEN_W /2 &&
        character.getCollision(LEFT) != true){

        //Move map.
        for(int i = 0 ; i < areaMap.getNumLayers() ; i++)
            areaMap.getLayer(i).addToDX(rate);

        character.setFacing(LEFT);
        character.addToAllCornerX(-rate);

        for(int i = 0 ; i < areaMap.getNumTangibles() ; i++)
            areaMap.getTangible(i).addToDX(rate);
    }
    else{
        //Move character.
        if(character.move(keys , theKey) != -1)
            character.addToAllCornerX(-rate);
    }
}

//Moves the map and player right.
void Movement::moveRight(Character &character , AreaMap &areaMap , int theKey , bool keys[]){

    //Boundary check
    if(areaMap.getLayer(BACKGROUND).getDX() + areaMap.getLayer(BACKGROUND).getW() > SCREEN_W &&
        character.getX() >= SCREEN_W / 2 && character.getCollision(RIGHT) != true){

        //Move map.
        for(int i = 0 ; i < areaMap.getNumLayers() ; i++)
            areaMap.getLayer(i).addToDX(-rate);
                    
        character.setFacing(RIGHT);
        character.addToAllCornerX(rate);

        for(int i = 0 ; i < areaMap.getNumTangibles() ; i++)
            areaMap.getTangible(i).addToDX(-rate);
    }

    else{
        //Move character.
        if(character.move(keys , theKey) != -1)
            character.addToAllCornerX(rate);
    }
}

//Set player and map to specified x and y coordinates.
bool Movement::setStartCoords(Character &character , AreaMap &areaMap , int x , int y){

    int playerX = 0;
    int playerY = 0;
    int screenX = 0;
    int screenY = 0;

    //Check if x is in the left most part of the map.
    if(x < SCREEN_W / 2){

        //Adjust only the player, not the screen.
        playerX = x;
        screenX = 0;
    }

    //Check if x is in the right most part of the map.
    else if(x > areaMap.getLayer(BACKGROUND).getW() - SCREEN_W / 2){

        //Adjust the player and the screen.
        playerX = SCREEN_W / 2 + (SCREEN_W / 2 - (areaMap.getLayer(BACKGROUND).getW() - (x)));
        screenX = areaMap.getLayer(BACKGROUND).getW() - SCREEN_W;
    }

    //X is in the middle part of the map.
    else{
        //Adjust the player and the screen.
        playerX = SCREEN_W / 2;
        screenX = x - playerX;
    }

    //Check if y is in the lower part of the map.
    if(y < SCREEN_H / 2){
        //Adjust the player, not the screen.
        playerY = y;
        screenY = 0;
    }

    //Check if y is in the upper part of the map.
    else if(y > areaMap.getLayer(BACKGROUND).getH() - SCREEN_H / 2){
        //Adjust the map and the player.
        playerY = SCREEN_H / 2 + (SCREEN_H / 2 - (areaMap.getLayer(BACKGROUND).getH() - (y)));
        screenY = areaMap.getLayer(BACKGROUND).getH() - SCREEN_H;
    }

    //Check if y is in the middle of the map.
    else{
        //Adjust the map and the player.
        playerY = SCREEN_H / 2;
        screenY = y - playerY;
    }

    //Check if layer width is smaller than the screen width and adjust.
    if(areaMap.getLayer(BACKGROUND).getW() < SCREEN_W){
        playerX += (SCREEN_W - areaMap.getLayer(BACKGROUND).getW()) / 2;
        screenX -= (SCREEN_W - areaMap.getLayer(BACKGROUND).getW()) / 2;
    }

    //Check if layer height is smaller than the screen height and adjust.
    if(areaMap.getLayer(BACKGROUND).getH() < SCREEN_H){
        playerY += (SCREEN_H - areaMap.getLayer(BACKGROUND).getH()) / 2;
        screenY -= (SCREEN_H - areaMap.getLayer(BACKGROUND).getH()) / 2;
    }

    character.setX(playerX);            //Set the player x value with recalculated values.
    character.setY(playerY);            //Set the player y value with recalculated values.
    character.refreshCorners();         //Adjust player collision corners.
    character.addToAllCornerX(screenX); //Adjust the x coordinates by the updates screen values.
    character.addToAllCornerY(screenY); //Adjust the y coordinates by the updates screen values.
            
    //Adjust each layer based off of updated values.
    areaMap.setLayersDX(-screenX);
    areaMap.setLayersDY(-screenY);

    //Set tangibles based off of updated screen x and y values.
    areaMap.resetTangiblesDXToSX(-screenX);
    areaMap.resetTangiblesDYToSY(-screenY);

    return true;
}
