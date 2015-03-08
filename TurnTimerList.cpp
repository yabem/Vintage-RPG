#include "TurnTimerList.h"

//Constructor.
TurnTimerList::TurnTimerList(){

}

//Destructor.
TurnTimerList::~TurnTimerList(){

    deleteList();
}

//Load I_Manager.
void TurnTimerList::loadManager(I_Manager *i_Manager){

    this->battleManager = i_Manager;
}

//Load I_List.
//Pre:  None.
//Post: Changes the menuList pointer to the list i_List is pointing to.
void TurnTimerList::loadList(I_List *i_List){

    this->menusList = i_List;
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

    listOfCharTimers.push_back(characterTimer);
}

//Deletes the specified TurnTimer.
//Pre:  The positio is within the bounds of the vector.
//Post: Deletes the TurnTimer in the position.
//      Returns true if the delete was successful, otherwise
//      returns false.
bool TurnTimerList::deleteSelection(int position){

    if(listOfCharTimers.empty())
        return false;

    else{
        vector<CharacterTimer*>::iterator charTimerIter = listOfCharTimers.begin();

        //Sets the iterator to the correct delete position.
        int i = 0;
        while(i < position && charTimerIter != listOfCharTimers.end()){

            i++;
            charTimerIter++;
        }

        delete listOfCharTimers[position]->turnTimer;
        listOfCharTimers.erase(charTimerIter);

        return true;
    }
}

//Delete all the CharacterTimers.
//Pre:  None.
//Post: Cycles through the entire list and deletes all
//      TurnTimers.
void TurnTimerList::deleteList(){

    std::vector<CharacterTimer*>::iterator timersIter
        = listOfCharTimers.begin();

    while(timersIter != listOfCharTimers.end()){

        delete (*timersIter)->turnTimer;
        listOfCharTimers.erase(timersIter);
        timersIter = listOfCharTimers.begin();
    }
}

//Update turnTimers.
//Pre:  None.
//Post: Updates all the turnTimers. If the turnTimers are full then
//      the turnTimers are reset.
void TurnTimerList::updateTurnTimers(){

    if(battleManager->battlePaused())
        return;

    else{
        for(int i = 0 ; i < listOfCharTimers.size() ; i++){
        
            listOfCharTimers[i]->turnTimer->updateCurrentFill();
            //listOfCharTimers[i]->turnTimer->draw();
                
            if(listOfCharTimers[i]->turnTimer->innerBarIsFull()){
         
                //Player's turn.
                if(listOfCharTimers[i]->i_Creature->isPlayable()){
                
                    battleManager->pauseBattle();
                    battleManager->setCurrPlayer(i);

                    //Load the players Menu for selection.
                    battleManager->loadMenu(menusList->getSelection(i));
                    listOfCharTimers[i]->turnTimer->resetCurrentFill();
                    return;
                }

                //Enemy's turn.
                else{
                //battleManager->loadMenu(listOfCharTimers[]
                //
                //loadMenu(listOfCharTimers[i]->i_creature->getmenus());
                //battleManager->loadMenu(listOfCharTimers[i]->i_Creature->getMenu();
                //Resets the timer.
                listOfCharTimers[i]->turnTimer->resetCurrentFill();
                //listOfCharTimers[i]->i_Creature->
                }
                //listOfCharTimers[i]->character->executeTurn();
            }
        }
    }
}

//Draw all timers.
//Pre:  None.
//Post: Draws all the turn timers to the screen.
void TurnTimerList::drawTurnTimers(){

    for(int i = 0 ; i < listOfCharTimers.size() ; i++){

        listOfCharTimers[i]->turnTimer->draw();
    }
}