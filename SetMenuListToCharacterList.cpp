#include "SetMenuListToCharacterList.h"

//Adds a Menu based off of the Character in the CharacterList.
//Pre:  None.
//Post: A Menu is added to the MenuList.
void SetMenuListToCharacterList::setMenuListToCharacterList
    (CharacterList *characterList , MenuList *menuList){

    //Cycles through CharacterList and adds a connection for each Character.
    for(int i = 0 ; i < characterList->getSize() ; i++){

        menuList->addMenuConnection(characterList->getCurrSelection());
        characterList->moveSelectionDown();
    }

    characterList->resetSelection();
}