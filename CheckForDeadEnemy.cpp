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

    if(theEnemy == NULL){
        //here
        return true;
    }

    if(theEnemy->getStats()->getCurrHP() <= 0){

        if(drawRepository->animationsEmpty()){
          
            CalculateRewards calculateRewards(battleManager , theEnemy);
            calculateRewards.deliverAllRewards();
            battleManager->addToDefeatedEnemyList(theEnemy->getIdentifierName());

            battleManager->deleteCurrEnemy();
        }
    }

    return true;
}