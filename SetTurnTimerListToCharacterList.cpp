#include "SetTurnTimerListToCharacterList.h"

//Adds a connection for each Character from the 
//Characterlist to the TurnTimerList.
//Pre:  The TurnTimerList and the CharacterList are not empty.
//Post: Cycles through the CharacterList and adds a TurnTimer
//      for each Character.
void SetTurnTimerListToCharacterList::setTurnTimerListToCharacterList
    (CharacterList *characterList , TurnTimerList *turnTimerList){

    //Cycles through CharacterList and adds a connection for each Character.
    while(!characterList->lastCharOfList()){

        turnTimerList->addConnection(characterList->getCurrSelection());
        characterList->moveSelectionDown();
    }

    //Add the final connections.
    turnTimerList->addConnection(characterList->getCurrSelection());

    characterList->resetSelection();
}