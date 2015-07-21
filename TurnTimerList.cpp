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


//Loads the DrawRepository.
void TurnTimerList::loadDrawRepository(DrawRepository *drawRepository){

    this->drawRepository = drawRepository;
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

    float test = i_Creature->getStats()->getTtlSpeed();
    turnTimer->setRate(i_Creature->getStats()->getTtlSpeed());

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

    //Only cycle if there aren't any pending events in the battle.
    if(!this->battleManager->isEventsEmpty()){
        return;
    }

    else if(battleManager->battlePaused())
        return;

    else for(unsigned int i = 0 ; i < listOfCharTimers.size() ; i++){
         
        //Cycle through the entire list of Characters.
        if(listOfCharTimers[i]->turnTimer->innerBarIsFull()){
         
            //Player's turn.
            if(listOfCharTimers[i]->i_Creature->isPlayable()){
                                        
                //Load the PlayerTurn.
                PlayerTurn *playerTurn = new PlayerTurn(i , battleManager ,
                    menusList->getSelection(i) , 
                    listOfCharTimers[i]->turnTimer ,
                    battleManager->getEnemiesList() ,
                    battleManager->getDrawRepository());
                
                battleManager->loadEvent(playerTurn);
                return;
            }

            //Enemy's turn.
            else{
                
                battleManager->setCurrEnemy(i);

                //Load the EnemyTurn.
                EnemyTurn *enemyTurn = new EnemyTurn(
                    battleManager->getCurrEnemy() ,
                    battleManager->getDrawRepository() ,
                    battleManager->getCharManipStore() ,
                    battleManager->getPlayersList() ,
                    battleManager->getEnemiesList() ,
                    battleManager , 
                    listOfCharTimers[i]->turnTimer);

                battleManager->loadEvent(enemyTurn);
                    
                battleManager->getEnemiesList()->resetSelection();
                return;
            }
        }
    }

    //Cycle through the entire list of Characters.
    //Only update if it's not the player's or enemy's turn.
    for(unsigned int i = 0 ; i < listOfCharTimers.size() ; i++){

        //Only update of the Character is alive.
        if(!listOfCharTimers[i]->i_Creature->isDead())
            listOfCharTimers[i]->turnTimer->updateCurrentFill();
    }
}

//Resets the turnTimer for the timer in the position.
//Pre:  The position is within the bounds of the vector.
//Post: Accesses the vector to get the timer then resets it.
void TurnTimerList::resetTurnTimerAtPosition(int position){

    listOfCharTimers[position]->turnTimer->resetCurrentFill();
}

//Draw all timers.
//Pre:  None.
//Post: Draws all the turn timers to the screen.
void TurnTimerList::drawTurnTimers(){

    for(unsigned int i = 0 ; i < listOfCharTimers.size() ; i++){

        listOfCharTimers[i]->turnTimer->draw();
    }
}

//Recalculates fill rate on the CharacterTimers.
//Pre:  None.
//Post  Cycles through each of the CharacterTimers and sets the
//      fill rate based on the the Character's speed.
void TurnTimerList::recalculateAllFillRates(){

    for(unsigned int i = 0 ; i < listOfCharTimers.size() ; i++){
        
        float fillRate = 
            listOfCharTimers[i]->i_Creature->getStats()->getTtlSpeed();

        listOfCharTimers[i]->turnTimer->setRate(fillRate);
    }
}