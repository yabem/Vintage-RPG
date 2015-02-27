#include "TurnTimerList.h"

//Constructor.
TurnTimerList::TurnTimerList(){

}

//Destructor.
TurnTimerList::~TurnTimerList(){

    deleteList();
}

//Sets the variables of the turnTimer.
//Pre:  The Character is not NULL.
//Post: The TurnTimer is set to align with the center of the
//      Character.
void TurnTimerList::initializeTurnTimerToCharacter(
    CharacterTimer *characterTimer){

    int finalTurnTimerDrawX = 0;
    int finalTurnTimerDrawY = 0;

    int charX = characterTimer->i_Creature->getX();
    int charY = characterTimer->i_Creature->getY();
    int charHeight = characterTimer->i_Creature->getH();

    finalTurnTimerDrawX = charX;
    finalTurnTimerDrawY = charY + charHeight;

    characterTimer->turnTimer->setDrawX(finalTurnTimerDrawX);
    characterTimer->turnTimer->setDrawY(finalTurnTimerDrawY);
 }

//Inserts a TurnTimer connected to a Character.
//Pre:  None.
//Post: Creates a CharacterTimer with a TurnTimer and the input Character.
//      The CharacterTimer is pushed to the end of the vector.
void TurnTimerList::addConnection(I_Creature *i_Creature){

    //Create and load the CharacterTimer.
    CharacterTimer *characterTimer = new CharacterTimer;
    TurnTimer *turnTimer = new TurnTimer;
    
    characterTimer->i_Creature = i_Creature;
    characterTimer->turnTimer = turnTimer;

    initializeTurnTimerToCharacter(characterTimer); 

    turnTimer->calculateDrawPoints();

    listOfTimers.push_back(characterTimer);
}

//Deletes the specified TurnTimer.
//Pre:  The positio is within the bounds of the vector.
//Post: Deletes the TurnTimer in the position.
//      Returns true if the delete was successful, otherwise
//      returns false.
bool TurnTimerList::deleteSelection(int position){

    if(listOfTimers.empty())
        return false;

    else{
        vector<CharacterTimer*>::iterator charTimerIter = listOfTimers.begin();

        //Sets the iterator to the correct delete position.
        int i = 0;
        while(i < position && charTimerIter != listOfTimers.end()){

            i++;
            charTimerIter++;
        }

        delete listOfTimers[position]->turnTimer;
        listOfTimers.erase(charTimerIter);

        return true;
    }
}

//Delete all the CharacterTimers.
//Pre:  None.
//Post: Cycles through the entire list and deletes all
//      TurnTimers.
void TurnTimerList::deleteList(){

    std::vector<CharacterTimer*>::iterator timersIter
        = listOfTimers.begin();

    while(timersIter != listOfTimers.end()){

        delete (*timersIter)->turnTimer;
        listOfTimers.erase(timersIter);
        timersIter = listOfTimers.begin();
    }
}

//Update turnTimers.
//Pre:  None.
//Post: Updates all the turnTimers. If the turnTimers are full then
//      the turnTimers are reset.
void TurnTimerList::updateTurnTimers(){

    for(int i = 0 ; i < listOfTimers.size() ; i++){
        listOfTimers[i]->turnTimer->updateCurrentFill();
        //listOfTimers[i]->turnTimer->draw();
                
        if(listOfTimers[i]->turnTimer->innerBarIsFull()){
         
            listOfTimers[i]->turnTimer->resetCurrentFill();
            //listOfTimers[i]->character->executeAction();
        }
    }
}


//Draw all timers.
//Pre:  None.
//Post: Draws all the turn timers to the screen.
void TurnTimerList::drawTurnTimers(){

    for(int i = 0 ; i < listOfTimers.size() ; i++){

        listOfTimers[i]->turnTimer->draw();
    }
}