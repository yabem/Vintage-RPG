#include "MenuList.h"

//Constructor.
MenuList::MenuList(){

}

//Destructor.
MenuList::~MenuList(){

    deleteList();
}

//Inserts a Menu connected to a Character.
//Pre:  None.
//Post: Creates a CharacterTimer with a Menu and the input Character.
//      The CharacterTimer is pushed to the end of the vector.
void MenuList::addMenuConnection(I_Creature *i_Creature , ALLEGRO_FONT *font){

    Menu *menu = new Menu(i_Creature->getAbilities() , font);
    menu->formatText();
    menu->setMenuToLeftOfCharacter(i_Creature);
    listOfMenus.push_back(menu);
}

//Gets the specified Menu.
//Pre: The selection is within the bounds of the vector.
//Post: Returns a pointer to the menu. If the position is outside of the
//      vector returns NULL.
Menu* MenuList::getSelection(int selection){

    if(listOfMenus.empty())
        return NULL;

    else{
        vector<Menu*>::iterator menusIter = listOfMenus.begin();

        //Sets the iterator to the correct delete selection.
        int i = 0;
        while(i < selection && menusIter != listOfMenus.end()){

            i++;
            menusIter++;
        }

        return listOfMenus[selection];
    }
}

//Deletes the specified Menu.
//Pre:  The position is within the bounds of the vector.
//Post: Deletes the Menu in the position.
//      Returns true if the delete was successful, otherwise
//      returns false.
bool MenuList::deleteSelection(int position){

    if(listOfMenus.empty())
        return false;

    else{
        vector<Menu*>::iterator menusIter = listOfMenus.begin();

        //Sets the iterator to the correct delete position.
        int i = 0;
        while(i < position && menusIter != listOfMenus.end()){

            i++;
            menusIter++;
        }

        delete listOfMenus[position];
        listOfMenus.erase(menusIter);

        return true;
    }
}

//Delete all the CharacterTimers.
//Pre:  None.
//Post: Cycles through the entire list and deletes all
//      Menus.
void MenuList::deleteList(){

    std::vector<Menu*>::iterator menusIter
        = (listOfMenus.begin());

    while(menusIter != listOfMenus.end()){

        delete (*menusIter);
        listOfMenus.erase(menusIter);
        menusIter = listOfMenus.begin();
    }
}