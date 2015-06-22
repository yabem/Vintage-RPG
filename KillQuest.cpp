#include "KillQuest.h"

KillQuest::KillQuest(){

    this->_isCompletedByPlayer = false;
    this->_isActiveForPlayer = false;
    this->_mustBeActiveForPlayerToUpdate = false;
    this->_displayName = "";
}

KillQuest::~KillQuest(){

    emptyObjectives();
}

bool KillQuest::completedByPlayer(){
    
    return _isCompletedByPlayer;
}

void KillQuest::makeCompletedByPlayer(){

    _isCompletedByPlayer = true;
}

bool KillQuest::isActiveForPlayer(){

    return _isActiveForPlayer;
}

void KillQuest::makeActiveForPlayer(){

    _isActiveForPlayer = true;
}

void KillQuest::makeInactiveForPlayer(){

    _isActiveForPlayer = false;
}

//Determines if the quest is updateable.
//Pre:  None.
//Post: Returns true if _mustBeActiveForPlayerToUpdate is false or
//      mustBeActiveForPlayerToUpdate is true and _isActiveForPlayer is
//      true. Otherwise returns false
bool KillQuest::objectivesAreUpdateable(){

    if(_mustBeActiveForPlayerToUpdate == false){
        return true;
    }
    else if(_isActiveForPlayer == true){
        return true;
    }

    else return false;
}

//Sets the flag that requires the quest to be active in order for the
//objectives to be updateable.
//Pre:  None.
//Post: Sets _mustBeActiveForPlayerToUpdate to true so that the quest can
//      only be updated if it is active for the player.
void KillQuest::setMustBeActiveForPlayerToUpdate(){

    this->_mustBeActiveForPlayerToUpdate = true;
}

//Updates the quest with the list of enemies.
//Pre:  The list is not NULL.
//Post: The list is updated as long as the quest is eligible to be updated.
void KillQuest::updateQuestObjectives(std::vector<std::string> list){

    std::vector<std::string>::iterator strIter;
    std::vector<Objective*>::iterator objectiveIter;

    for(strIter = list.begin() ; 
        strIter != list.end() ; 
        strIter++){

        for(objectiveIter = _objectives.begin() ;
            objectiveIter != _objectives.end() ;
            objectiveIter++){

                //Only add to _numberAcquired when the string matches and it won't
                //increase the _numberAcquired above the _totalNecessaryToAchieveGoal.
                if((*strIter) == (*objectiveIter)->_goalToAccomplish && 
                    (*objectiveIter)->_numberAcquired < 
                    (*objectiveIter)->_totalNecessaryToAchieveGoal){

                (*objectiveIter)->_numberAcquired++;
            }
        }
    }
}

void KillQuest::checkComplete(){

    bool complete = true;

    std::vector<Objective*>::iterator objIter;

    for(objIter = _objectives.begin() ;
        objIter != _objectives.end() ;
        objIter++){

            if((*objIter)->_numberAcquired < (*objIter)->_totalNecessaryToAchieveGoal)
                complete = false;
    }

    this->_isCompletedByPlayer = complete;
}

void KillQuest::addObjective(std::string goalToAccomplish ,
        int totalNecessaryToAchieveGoal){

    Objective *objective = new Objective();
    objective->_goalToAccomplish = goalToAccomplish;
    objective->_totalNecessaryToAchieveGoal = totalNecessaryToAchieveGoal;
    objective->_numberAcquired = 0;

    this->_objectives.push_back(objective); 
}

void KillQuest::emptyObjectives(){
    
    std::vector<Objective*>::iterator objIter = _objectives.begin();

    while(objIter != _objectives.end()){
     
        delete (*objIter);
        objIter++;
    }

    _objectives.clear();
}

std::string KillQuest::getObjectiveSummary(){
    
    std::string objectiveSummary = "";

    std::vector<Objective*>::iterator objectiveIter;
    
    for(objectiveIter = _objectives.begin() ; 
        objectiveIter != _objectives.end() ;
        objectiveIter++){

            char tempChar[3];

            //Populate quest status.
            objectiveSummary += (*objectiveIter)->_goalToAccomplish;
            objectiveSummary += "-";
             _itoa_s((*objectiveIter)->_numberAcquired , tempChar , 10);
            objectiveSummary += tempChar;
            objectiveSummary += "/";
            _itoa_s((*objectiveIter)->_totalNecessaryToAchieveGoal , tempChar , 10);
            objectiveSummary += tempChar;

            //Add a comma if there's a list.
            if(objectiveIter + 1 !=_objectives.end())
                objectiveSummary += "  ";
    }

    return objectiveSummary;
}

void KillQuest::setQuestDisplayName(std::string displayName){

    this->_displayName = displayName;
}

std::string KillQuest::getQuestDisplayName(){

    return _displayName;
}