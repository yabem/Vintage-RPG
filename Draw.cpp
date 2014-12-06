//The purpose of the Draw namespace is to draw a character and
//an area map in one function.

#pragma once
#include "Draw.h"

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