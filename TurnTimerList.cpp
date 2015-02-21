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

    int charX = characterTimer->character->getX();
    int charY = characterTimer->character->getY();
    int charHeight = characterTimer->character->getH();

    finalTurnTimerDrawX = charX;
    finalTurnTimerDrawY = charY + charHeight;
    
    /*
    int charWidth = characterTimer->character->getW();
    int charHeight = characterTimer->character->getH();
        
    int turnTimerWidth = characterTimer->turnTimer->getOutterWidth();

    //Calculate the offset to center the TurnTimer on the Character.
    int widthDiff = abs(turnTimerWidth - charWidth);
    int adjustmentWidth = widthDiff / 2;

    //Y draw coordinate will always be the same.
    finalTurnTimerDrawY = charY + charHeight;

    //Set the TurnTimer to the center of the Character.
    if(turnTimerWidth < charWidth)
        finalTurnTimerDrawX = charX + adjustmentWidth;

    else finalTurnTimerDrawX = charX - adjustmentWidth;
    */

    characterTimer->turnTimer->setDrawX(finalTurnTimerDrawX);
    characterTimer->turnTimer->setDrawY(finalTurnTimerDrawY);
 }

//Inserts a TurnTimer connected to a Character.
//Pre:  None.
//Post: Creates a CharacterTimer with a TurnTimer and the input Character.
//      The CharacterTimer is pushed to the end of the vector.
void TurnTimerList::addConnection(Character *character){

    //Create and load the CharacterTimer.
    CharacterTimer *characterTimer = new CharacterTimer;
    TurnTimer *turnTimer = new TurnTimer;
    
    characterTimer->character = character;
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

    if(position > listOfTimers.size())
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