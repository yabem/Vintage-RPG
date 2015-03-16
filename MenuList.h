#pragma once
#include "I_List.h"
#include "Menu.h"
#include "I_Creature.h"

class MenuList: public I_List{

private:

    //List of the enemies.
    std::vector<Menu*> listOfMenus;   

    //Sets the variables of the Menu.
    void initializeMenuToCharacter(Menu *menu);
    
public:

    //Constructor.
    MenuList();

    //Destructor.
    virtual ~MenuList();

    //Returns a pointer to the currently selected enemy.
    Menu* getCurrSelection();  

    //Inserts a Menu connected to a Character.
    void addMenuConnection(I_Creature *i_Creature);

    //Gets the specified Menu.
    virtual Menu* getSelection(int selection);

    //Deletes the specified Menu.
    virtual bool deleteSelection(int selection);

    //Delete all the CharacterTimers.
    virtual void deleteList();
};