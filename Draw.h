//The purpose of the Draw namespace is to draw a character and
//an area map in one function.

#pragma once
#include "Map.h"
#include "AreaMap.h"
#include "Character.h"
#include "I_List.h"
#include "CharacterList.h"
#include <vector>
#include "Menu.h"
#include "GameConfig.h"

namespace Draw{

    void drawArea(const AreaMap &areaMap);
    void drawArea(const AreaMap &areaMap , const Character &character);
    void drawBattle(Map &map , I_List *thePlayers , 
        I_List *theEnemies);
        //vector<Character*> characters ,
        //vector<Character*> enemies);
    void drawBattle(Map &map);
    void drawCharListForBattle(CharacterList *characterList);
    
    //Draws all of the Menus in the vector.
    void drawMenus(vector<Menu*> menus);
    
    //Removes all of the subMenus from the vector leaving only the base Menu.
    void removeAllSubMenus(std::vector<Menu*> &menus);

    //Removes all Menus from the vector.
    void removeAllMenus(std::vector<Menu*> &menus);

    //Moves the menu selection to the beginning.
    void moveMenuSelectionToBegin(vector<Menu*> menus);
}