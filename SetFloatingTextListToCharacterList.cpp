#include "SetFloatingTextListToCharacterList.h"

//Adds a FloatingText based off of the Character in the CharacterList.
//Pre:  None.
//Post: A FloatingText is added to the CharacterList.
void SetFloatingTextListToCharacterList::SetFloatingTextListToCharacterList
    (CharacterList *characterList , FloatingTextList *floatingTextList){

    //Cycles through CharacterList and adds a connection for each Character.
    for(int i = 0 ; i < characterList->getSize() ; i++){

        floatingTextList->addFloatingTextConnection
            (characterList->getCurrSelection());

        characterList->moveSelectionDown();
    }

    characterList->resetSelection();
}