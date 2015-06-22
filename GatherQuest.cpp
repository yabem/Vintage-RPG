#include "GatherQuest.h"

GatherQuest::GatherQuest(Backpack *backpack) : KillQuest(){

    this->_backpack = backpack;
}

GatherQuest::~GatherQuest(){

    emptyObjectives();
}

//Updates the quest with the list of items in the player's posession.
//Pre:  The list is not NULL.
//Post: The list is updated as long as the quest is eligible to be updated.
void GatherQuest::updateQuestObjectives(std::vector<std::string> list){

    std::vector<std::string>::iterator strIter;
    std::vector<Objective*>::iterator objectiveIter;

    for(objectiveIter = _objectives.begin() ;
        objectiveIter != _objectives.end() ;
        objectiveIter++){

        //Update only when the objective item is in the inventory and the
        //quest is not already completed by the player.
        if(_backpack->itemExistsInInventory((*objectiveIter)->_goalToAccomplish) && 
            !_isCompletedByPlayer){

            //Check if the objective has already been accomplished.
            if((*objectiveIter)->_numberAcquired <
                (*objectiveIter)->_totalNecessaryToAchieveGoal){

                //Check if the amount in inventory is greater than the amount needed 
                //to accomplish the goal.
                if(_backpack->getAmountInInventory((*objectiveIter)->_goalToAccomplish) >
                    (*objectiveIter)->_totalNecessaryToAchieveGoal){

                    //Set the _numberAcquired to the max since the inventory has enough.
                    (*objectiveIter)->_numberAcquired =
                        (*objectiveIter)->_totalNecessaryToAchieveGoal;
                }

                //Set the _numberAcquired to the amount in inventory since the inventory
                //is less than the goal.
                else (*objectiveIter)->_numberAcquired =
                    _backpack->getAmountInInventory((*objectiveIter)->_goalToAccomplish);
            }
        }
    }
}

//Removes all the items from the backpack that are in the quest.
//Pre:  The quest is marked as complete.
//Post: Removes all of the quantities and items from the backpack
//      that are associated with this quest.
void GatherQuest::removeQuestItemsFromBackPack(){

    if(!_isCompletedByPlayer)
        return;

    std::vector<Objective*>::iterator objectiveIter;

    for(objectiveIter = _objectives.begin() ;
        objectiveIter != _objectives.end() ;
        objectiveIter++){

            //Remove the items that were objectives in the quest.
            this->_backpack->adjustItemQuantity(
                (*objectiveIter)->_goalToAccomplish ,
                -(*objectiveIter)->_numberAcquired);
    }
}