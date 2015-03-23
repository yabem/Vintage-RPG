#include "GainedExperiencePoints.h"

//Constructor.
GainedExperiencePoints::GainedExperiencePoints(I_List *listOfPlayers ,
    int amountGained){

    this->amountGained = amountGained;
    this->listOfPlayers = listOfPlayers;
}

//Destructor.
GainedExperiencePoints::~GainedExperiencePoints(){

}

//Delivers the reward to the player.
//Pre:  The object has been initialized.
//Post: Delivers the experience points to the player.
bool GainedExperiencePoints::deliverToPlayer(){

    int listSize = listOfPlayers->getSize();

    for(int i = 0 ; i < listSize ; i++)
        listOfPlayers->getCharacterSelection(i)->addToTotalXP(amountGained);

    return true;
}

//Returns the name of the reward.
//Pre:  None.
//Post: Returns the name of the reward.
std::string GainedExperiencePoints::getName(){

    return "XP";//EXPERIENCE_TYPE;
}

//Returns the XP that is stored in the reward.
//Pre:  None.
//Post: Returns the amount of XP.
int GainedExperiencePoints::getAmount(){

    return amountGained;
}