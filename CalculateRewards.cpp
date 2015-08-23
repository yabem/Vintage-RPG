#include "CalculateRewards.h"

CalculateRewards::CalculateRewards(I_Manager *battleManager ,
    I_Creature *theEnemy){

    this->battleManager = battleManager;
    this->theEnemy = theEnemy;    
}

CalculateRewards::~CalculateRewards(){

}

void CalculateRewards::deliverAllRewards(){

    deliverMoney();
    deliverXP();
    deliverItems();
}

void CalculateRewards::deliverMoney(){

    GainedMoney *gainedMoney =
        new GainedMoney(theEnemy->getMoneyReward() ,
        battleManager->getBackpack());

    battleManager->loadReward(gainedMoney);
}

void CalculateRewards::deliverXP(){

    GainedExperiencePoints *gainedExperiencePoints =
        new GainedExperiencePoints(battleManager->getPlayersList() ,
        theEnemy->getXPReward());

    battleManager->loadReward(gainedExperiencePoints);
}

void CalculateRewards::deliverItems(){

    std::vector<std::string> theRewards = theEnemy->getStats()->getRewards();

    //No rewards.
    if(theRewards.empty())
        return;

    else{

        std::vector<std::string>::iterator rewardsIter = theRewards.begin();

        while(rewardsIter != theRewards.end()){

            GainedItem *gainedItem = 
                new GainedItem(*rewardsIter , 1 , battleManager->getBackpack());

                battleManager->loadReward(gainedItem);

                rewardsIter++;
        }
    }
}
