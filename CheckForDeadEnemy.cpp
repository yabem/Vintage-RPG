#include "CheckForDeadEnemy.h"

//Constructor.
CheckForDeadEnemy::CheckForDeadEnemy(I_Creature *theEnemy ,
    DrawRepository *drawRepository , I_Manager *battleManager){

    this->theEnemy = theEnemy;
    this->drawRepository = drawRepository;
    this->battleManager = battleManager;
}

//Destructor.
CheckForDeadEnemy::~CheckForDeadEnemy(){

    //Default is fine.
}

//Executes the CheckForDeadEnemy.
//Pre:  None.
//Post: Always returns true because the event only executes once.
bool CheckForDeadEnemy::execute(){

    if(theEnemy->getStats()->getCurrHP() <= 0){

        if(drawRepository->animationsEmpty()){
          
            CalculateRewards calculateRewards(battleManager , theEnemy);
            calculateRewards.deliverAllRewards();

            /*
            GainedExperiencePoints *gainedExperiencePoints =
                new GainedExperiencePoints(battleManager->getPlayersList() ,
                theEnemy->getXPReward());

            GainedMoney *gainedMoney =
                new GainedMoney(theEnemy->getMoneyReward() ,
                battleManager->getBackpack());
            
            GainedItem *gainedItem = 
                new GainedItem("Potion" , 1 ,
                battleManager->getBackpack());

            battleManager->loadReward(gainedItem);
            battleManager->loadReward(gainedMoney);
            battleManager->loadReward(gainedExperiencePoints);
            */

            battleManager->deleteCurrEnemy();
        }
    }

    return true;
}