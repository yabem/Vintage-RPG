//Loads a menu to the BattleManager.

#pragma once
#include "I_Event.h"
#include "I_Manager.h"
class Menu;

class LoadAMenu : public I_Event{

private:

    //Used to load Events.
    I_Manager *battleManager;

    //The position for the player that the menu is loaded for.
    int playerPosition;

    //The Menu to load.
    Menu *menu;

    bool isExecuted;

public:

    //Constructor
    LoadAMenu(I_Manager *battleManager , int playerPosition , Menu *menu);
    
    //Destructor
    ~LoadAMenu();
    
    //Executes the event.
    bool execute();
};