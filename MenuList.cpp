#include "MenuList.h"

//Constructor.
MenuList::MenuList(){

}

//Destructor.
MenuList::~MenuList(){

    deleteList();
}

/*
//Sets the variables of the Menu.
//Pre:  The Character is not NULL.
//Post: The Menu is set to align with the center of the
//      Character.
void MenuList::initializeMenuToCharacter(
    CharacterTimer *characterTimer){

        /*
    int finalMenuDrawX = 0;
    int finalMenuDrawY = 0;

    int charX = characterTimer->i_Creature->getX();
    int charY = characterTimer->i_Creature->getY();
    int charHeight = characterTimer->i_Creature->getH();

    finalMenuDrawX = charX;
    finalMenuDrawY = charY + charHeight;

    characterTimer->Menu->setDrawX(finalMenuDrawX);
    characterTimer->Menu->setDrawY(finalMenuDrawY);

    
 }
 */

//Inserts a Menu connected to a Character.
//Pre:  None.
//Post: Creates a CharacterTimer with a Menu and the input Character.
//      The CharacterTimer is pushed to the end of the vector.
void MenuList::addMenuConnection(I_Creature *i_Creature){

    Menu *menu = new Menu(i_Creature->getAbilities());
    menu->formatText();
    menu->setMenuToLeftOfCharacter(i_Creature);
    listOfMenus.push_back(menu);
    /*
    characterTimer->i_Creature = i_Creature;
    characterTimer->Menu = Menu;

    initializeMenuToCharacter(characterTimer); 

    Menu->calculateDrawPoints();

    listOfCharTimers.push_back(characterTimer);
    */
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

    int testing = 0;

    while(menusIter != listOfMenus.end()){

        delete (*menusIter);
        listOfMenus.erase(menusIter);
        menusIter = listOfMenus.begin();
        testing++;
    }
}

//Update Menus.
//Pre:  None.
//Post: Updates all the Menus. If the Menus are full then
//      the Menus are reset.
void MenuList::updateMenus(){

    /*
    for(int i = 0 ; i < listOfMenus.size() ; i++){
        listOfMenus[i]->Menu->updateCurrentFill();
        //listOfCharTimers[i]->Menu->draw();
                
        if(listOfMenus[i]->Menu->innerBarIsFull()){
         
            //
            //loadMenu(listOfCharTimers[i]->i_creature->getmenus());
            //battleManager->loadMenu(listOfCharTimers[i]->i_Creature->getMenu();
            //Resets the timer.
            listOfCharTimers[i]->Menu->resetCurrentFill();
            //listOfCharTimers[i]->i_Creature->
            
            //listOfCharTimers[i]->character->executeTurn();
        }
    }
    */
}