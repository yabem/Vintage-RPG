#include "GainedMoney.h"

//Constructor.
GainedMoney::GainedMoney(//Addbackpack object
    int amountGained){

    this->amountGained = amountGained;
}

//Destructor.
GainedMoney::~GainedMoney(){

}

//Delivers the reward to the player.
//Pre:  The object has been initialized.
//Post: Delivers the experience points to the player.
bool GainedMoney::deliverToPlayer(){

    //Need to deliver to the player via a backpack object.

    return true;
}

//Returns the name of the reward.
//Pre:  None.
//Post: Returns the name of the reward.
std::string GainedMoney::getName(){

    return MONEY_TYPE;
}

//Returns the XP that is stored in the reward.
//Pre:  None.
//Post: Returns the amount of money.
int GainedMoney::getAmount(){

    return amountGained;
}