#include "SetTurnTimerListToCharacterList.h"

//Adds a connection for each Character from the 
//Characterlist to the TurnTimerList.
//Pre:  The TurnTimerList and the CharacterList are not empty.
//Post: Cycles through the CharacterList and adds a TurnTimer
//      for each Character.
void SetTurnTimerListToCharacterList::setTurnTimerListToCharacterList
    (CharacterList *characterList , TurnTimerList *turnTimerList){

    //Cycles through CharacterList and adds a connection for each Character.
    for(int i = 0 ; i < characterList->getSize() ; i++){

        turnTimerList->addConnection(characterList->getCurrSelection());
        characterList->moveSelectionDown();
    }

    characterList->resetSelection();
}