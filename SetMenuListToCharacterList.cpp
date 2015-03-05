#include "SetMenuListToCharacterList.h"

//Adds a Menu based off of the Character in the CharacterList.
//Pre:  None.
//Post: A Menu is added to the MenuList.
void SetMenuListToCharacterList::setMenuListToCharacterList
    (CharacterList *characterList , MenuList *menuList){

    //Cycles through CharacterList and adds a connection for each Character.
    while(!characterList->lastCharOfList()){

        menuList->addMenuConnection(characterList->getCurrSelection());
        characterList->moveSelectionDown();
    }

    //Add the final connections.
    menuList->addMenuConnection(characterList->getCurrSelection());

    characterList->resetSelection();
}