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
        areaMap.getTangible(i);//.draw();

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
void Draw::drawBattle(Map &map , vector<Character*> characters , vector<Character*> enemies){

    //Draw layers.
    for(int i = 0 ; i < map.getNumLayers() ; i++) 
        map.getLayer(i).draw();

    //Draw characters.
    for(unsigned int i = 0 ; i < characters.size() ; i++) 
        characters[i]->draw();

    //Draw enemies.
    for(unsigned int i = 0 ; i < enemies.size() ; i++) 
        enemies[i]->draw();

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
void Draw::drawCharList(CharacterList *characterList){


}

//Draws all menus in the vector in FIFO order.
//Pre:  None.
//Post: Draws all the Menu objects on the vector by calling
//      the draw method on each Menu until the end of the list
//      is reached.
void Draw::drawMenus(vector<Menu*> menus){

    if(menus.empty())
        return;

    vector<Menu*>::iterator menuIter = menus.begin();
   
    //Draw all Menus in the vector.
    while(menuIter != menus.end()){

        (*menuIter)->draw();
        menuIter++;
    }
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

//Moves the menu selection to the beginning.
//Pre:  None.
//Post: Moves the menu's current selection to the beginning
//      of the list.
void Draw::moveMenuSelectionToBegin(vector<Menu*> menus){

    //Resets the menu selection to the beginning of the list
    //then removes it from the vector.
    vector<Menu*>::iterator menuIter = menus.end() - 1;
    (*menuIter)->moveCurrSelectionToBegin();
}