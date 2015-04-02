//The purpose of the Draw namespace is to draw a character and
//an area map in one function.

#pragma once
#include "Draw.h"

//Draws the AreaMap to the buffer.
void Draw::drawArea(const AreaMap &areaMap){

    //Draw layers.
    for(int i = 0 ; i < areaMap.getNumLayers() ; i++)
        areaMap.getLayer(i).draw();

    //Draw obstacles.
    for(int i = 0 ; i < areaMap.getNumTangibles() ; i++)
        areaMap.getTangible(i);

    //Draw clouds.
    for(int i = 0 ; i < areaMap.getNumSceneries() ; i++)
        areaMap.getScenery(i).draw();
}

//Draw the Character and the AreaMap to the buffer.
void Draw::drawArea(const AreaMap &areaMap , const Character &character){

    //Draw layers.
    for(int i = 0 ; i < areaMap.getNumLayers() ; i++){    

        //Draw character after the background but before the foreground.
        if(i == CENTERGROUND)
            character.draw();

        areaMap.getLayer(i).draw();
    }

    //Draw obstacles.
    for(int i = 0 ; i < areaMap.getNumTangibles() ; i++)
        areaMap.getTangible(i);//.draw();

    //Draw clouds.
    for(int i = 0 ; i < areaMap.getNumSceneries() ; i++)
        areaMap.getScenery(i).draw();
}

//Draw the battle with the map and the characters and enemies.
void Draw::drawBattle(Map &map , I_List *thePlayers , 
    I_List *theEnemies){

    //Draw layers.
    for(int i = 0 ; i < map.getNumLayers() ; i++) 
        map.getLayer(i).draw();

    //Draw characters.
    for(int i = 0 ; i < thePlayers->getSize() ; i++)
        thePlayers->getCharacterSelection(i)->draw();

    //Draw enemies.
    for(int i = 0 ; i < theEnemies->getSize() ; i++) 
        theEnemies->getCharacterSelection(i)->draw();

    //Draw sceneries.
    for(int i = 0 ; i < map.getNumSceneries() ; i++)
        map.getScenery(i).draw();
}

//Draw the battle with the map and the characters and enemies.
void Draw::drawBattle(Map &map){

    //Draw layers.
    for(int i = 0 ; i < map.getNumLayers() ; i++) 
        map.getLayer(i).draw();

    //Draw sceneries.
    for(int i = 0 ; i < map.getNumSceneries() ; i++)
        map.getScenery(i).draw();
}

//Draws all the characters in the CharacterList.
//Pre:  None.
//Pro:  Draws all the characters to the screen.
void Draw::drawCharListForBattle(CharacterList *characterList){

    characterList->resetSelection();

    for(int i = 0 ; i < characterList->getSize() && i <
        MAX_PLAYERS_PER_BATTLE ; i++){

        characterList->getCurrSelection()->draw();
        characterList->moveSelectionDown();
    }
}

//Draws all menus in the vector in FIFO order.
//Pre:  None.
//Post: Draws all the Menu objects on the vector by calling
//      the draw method on each Menu until the end of the list
//      is reached.
void Draw::drawMenus(vector<Menu*> menus){

    if(menus.size() == 1)
        int i = 0;

    if(menus.empty())
        return;

    vector<Menu*>::iterator menuIter = menus.begin();
   
    //Draw all Menus in the vector.
    while(menuIter != menus.end()){

        (*menuIter)->draw();
        menuIter++;
    }
}

//Draws IList.
void Draw::drawList(I_List *i_List){

    //Draw characters.
    for(int i = 0 ; i < i_List->getSize() ; i++)
        i_List->getCharacterSelection(i)->draw();
}

//Removes all of the subMenus from the vector leaving only the base Menu.
//Pre:  None.
//Post: Removes each Menu from the list in LIFO order until the Menu
//      at the beginning of the list is reached.
void Draw::removeAllSubMenus(std::vector<Menu*> &menus){

   //Do nothing if the vector is empty.
    if(menus.empty())
        return;

    //Remove all subMenus until at the base subMenu.
    else{

        while (menus.size() > 1){
            //Resets the menu selection to the beginning of the list
            //then removes it from the vector.
            Draw::moveMenuSelectionToBegin(menus);
            menus.pop_back();
        } 

        //Reset the menu selection for the base menu.
       Draw::moveMenuSelectionToBegin(menus);
    }
}

//Removes all Menus from the vector.
//Pre:  None.
//Post: All the Menu objects are popped off the vector.
void Draw::removeAllMenus(std::vector<Menu*> &menus){

   //Do nothing if the vector is empty.
    if(menus.empty())
        return;

    //Remove all subMenus until at the base subMenu.
    else{

        while (!menus.empty()){
            //Resets the menu selection to the beginning of the list
            //then removes it from the vector.
            Draw::moveMenuSelectionToBegin(menus);
            menus.pop_back();
        } 
    }
}

//Moves the menu selection to the beginning.
//Pre:  None.
//Post: Moves the menu's current selection to the beginning
//      of the list.
void Draw::moveMenuSelectionToBegin(vector<Menu*> menus){

    if(menus.empty())
        return;

    else{
        //Resets the menu selection to the beginning of the list
        //then removes it from the vector.
        vector<Menu*>::iterator menuIter = menus.end() - 1;
        (*menuIter)->moveCurrSelectionToBegin();
    }
}