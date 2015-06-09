#include "AddAbilityToCharacterInList.h"

//Adds the ability to the specified Character.
//Pre:  The CharacterList is not null.
//Post: Searches the CharacterList for the identifierName. If found,
//      the ability is added to the Character and returns true.
//      If not found, returns false.
bool AddAbilityToCharacterInList::AddAbilityToCharacterInList
    (std::string identifierName , CharacterList *characterList , std::string ability){

    characterList->resetSelection();
    
    for(int i = 0 ; i < characterList->getSize() ; i++){

        if(characterList->getCurrSelection()->getIdentifierName() == identifierName){

            characterList->getCurrSelection()->addAbility(ability);
            characterList->resetSelection();
            return true;
        }
        else{
            characterList->moveSelectionDown();
        }
    }

    characterList->resetSelection();
    return false;
}