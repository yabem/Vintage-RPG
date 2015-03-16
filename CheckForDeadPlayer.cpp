#include "CheckForDeadPlayer.h"


//Constructor.
CheckForDeadPlayer::CheckForDeadPlayer(I_Creature *thePlayer ,
    DrawRepository *drawRepository){

    this->thePlayer = thePlayer;
    this->drawRepository = drawRepository;
}

//Destructor.
CheckForDeadPlayer::~CheckForDeadPlayer(){

    //Default is fine.
}

//Executes the CheckForDeadPlayer.
//Pre:  None.
//Post: Always returns true because the event only executes once.
bool CheckForDeadPlayer::execute(){

    if(thePlayer->getStats()->getCurrHP() <= 0){

        thePlayer->makeDead();
    }

    return true;
}