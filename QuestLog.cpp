#include "QuestLog.h"

//Constructor.
QuestLog::QuestLog(FontStore *fontStore){

    this->fontStore = fontStore;
    this->activeQuestDisplay = NULL;
    this->completedQuestDisplay = NULL;
}

//Destructor.
QuestLog::~QuestLog(){

    delete activeQuestDisplay;
    delete completedQuestDisplay;
}

//Adds a quest to _quests.
//Pre:  The quest is valid and not NULL.
//Post: Adds the quest to _quests and returns true if the quest
//      does not already exist and is added. Otherwise returns false.
bool QuestLog::addQuest(std::string questName , Quest *quest){

    std::map<std::string , Quest*>::iterator questIter = _quests.begin();
        
    questIter = _quests.find(questName);
    
    //Quest does not exist so add it.
    if(questIter == _quests.end()){
        _quests.insert(std::pair<std::string , Quest*>(questName , quest));
        updateQuestDisplay();
        return true;
    }
    //Quest already exists, cannot insert.
    else return false;
}

//Updates all of the Quest Objectives.
//Pre:  The list is not NULL.
//Post: Cycles through each quest all updates that quest's objectives with
//      the list provided and checks if the quest is complete.
void QuestLog::updateAllQuestObjectives(std::vector<std::string>
    listOfAccomplishments){

    std::map<std::string , Quest*>::iterator questIter;

    for(questIter = _quests.begin() ; questIter != _quests.end() ; questIter++){

        if(questIter->second->objectivesAreUpdateable()){
            questIter->second->updateQuestObjectives(listOfAccomplishments);
            questIter->second->checkComplete();
        }
    }

    updateQuestDisplay();
}

//Deletes all quests from _quests.
void QuestLog::removeAllQuests(){

    std::map<std::string , Quest*>::iterator questIter;

    for(questIter = _quests.begin() ; questIter != _quests.end() ; questIter++){

        delete questIter->second;
        questIter->second = NULL;
        _quests.erase(questIter);
        questIter = _quests.begin();
    }
}

//Recreates the quest log based off of the current quests.
//Pre:  None.
//Post: Permanently updates the InfoTable.
void QuestLog::updateQuestDisplay(){

    updateActiveQuestsDisplay();
    updateCompletedQuestsDisplay();
}

//Recreates the active quest log based off of the active quests.
//Pre:  None.
//Post: Permanently updates the activeQuestDisplay.
void QuestLog::updateActiveQuestsDisplay(){

    //Delete existing display.
    delete activeQuestDisplay;

    std::string allActiveQuests = 
        "------------------------Active Quests-------------------------,";

    std::map<std::string , Quest*>::iterator questIter = _quests.begin();

    //Get quest name and add it to the list.

    for(int i = 0 ; i < _quests.size() ; i++ , questIter++){

        if(questIter->second->isActiveForPlayer()){
            allActiveQuests += questIter->second->getQuestDisplayName();
            allActiveQuests += ": ";
            allActiveQuests += questIter->second->getObjectiveSummary();

            //Check if there's another element.
            if(i + 1 != _quests.size()){
                allActiveQuests += ",";
            }
        }
    }

    allActiveQuests += ";";

    InfoTable *activeQuestDisplay = new InfoTable(allActiveQuests ,
        fontStore->getFont("default"));
    activeQuestDisplay->formatText();
    this->activeQuestDisplay = activeQuestDisplay;
    centerActiveQuestDisplayToScreen();
}

//Recreates the completed quest log based off of the completed quests.
//Pre:  None.
//Post: Permanently updates the completedQuestDisplay.
void QuestLog::updateCompletedQuestsDisplay(){

    //Delete existing display.
    delete completedQuestDisplay;

    std::string allCompletedQuests = 
        "------------------------Completed Quests-------------------------,";

    std::map<std::string , Quest*>::iterator questIter = _quests.begin();

    //Get quest name and add it to the list.
    for(int i = 0 ; i < _quests.size() ; i++ , questIter++){

        if(!questIter->second->isActiveForPlayer() && 
            questIter->second->completedByPlayer()){
            
            allCompletedQuests += questIter->second->getQuestDisplayName();
            allCompletedQuests += ": ";
            allCompletedQuests += questIter->second->getObjectiveSummary();

            //Check if there's another element.
            if(i + 1 != _quests.size()){
                allCompletedQuests += ",";
            }
        }
    }

    allCompletedQuests += ";";

    InfoTable *completedQuestDisplay = new InfoTable(allCompletedQuests ,
        fontStore->getFont("default"));
    completedQuestDisplay->formatText();
    this->completedQuestDisplay = completedQuestDisplay;
    centerCompletedQuestDisplayToScreen();
}

//Moves the activeQuestDisplay to the middle of the screen.
//Pre:  None.
//Post: Gets the difference in width between the activeQuestDisplay and the screen 
//      width. Divides that by two, then adds it to the start position of
//      the activeQuestDisplay.
void QuestLog::centerActiveQuestDisplayToScreen(){

    int totalWidthOfInfoTable = 
        activeQuestDisplay->getDX() - activeQuestDisplay->getSX();
    int amountToAddToInfoTableToCenter = 
        (SCREEN_W - totalWidthOfInfoTable) / 2;

    activeQuestDisplay->setSX(amountToAddToInfoTableToCenter);
    activeQuestDisplay->calculateMenuEndCoordinates();
    activeQuestDisplay->calculateSelectorCoords();
}

//Moves the completedQuestDisplay to the middle of the screen.
//Pre:  None.
//Post: Gets the difference in width between the completedQuestDisplay and the screen 
//      width. Divides that by two, then adds it to the start position of
//      the completedQuestDisplay.
void QuestLog::centerCompletedQuestDisplayToScreen(){

    int totalWidthOfInfoTable = 
        completedQuestDisplay->getDX() - completedQuestDisplay->getSX();
    int amountToAddToInfoTableToCenter = 
        (SCREEN_W - totalWidthOfInfoTable) / 2;

    completedQuestDisplay->setSX(amountToAddToInfoTableToCenter);
    completedQuestDisplay->calculateMenuEndCoordinates();
    completedQuestDisplay->calculateSelectorCoords();
}

//Displays all of the player's active quests.
//Pre:  The QuestLog is valid.
//Post: Displays all quests marked as active but not complete.
void QuestLog::displayActiveQuests(){

    updateQuestDisplay();
    activeQuestDisplay->draw();
}

//Displays all of the player's completed quests.
//Pre:  The QuestLog is valid.
//Post: Displays all quests marked as inactive and complete.
void QuestLog::displayCompletedQuests(){

    updateQuestDisplay();
    completedQuestDisplay->draw();
}

//Retrieves the quest from _quests.
//Pre:  None.
//Post: Finds the quest and returns it if available. If not available returns NULL.
Quest* QuestLog::getQuest(std::string questName){

    std::map<std::string , Quest*>::iterator questIter;
    
    questIter = _quests.begin();

    _quests.find(questName);

    return questIter->second;
}