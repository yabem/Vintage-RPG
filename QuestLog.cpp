#include "QuestLog.h"

//Constructor.
QuestLog::QuestLog(FontStore *fontStore){

    this->fontStore = fontStore;
}

//Destructor.
QuestLog::~QuestLog(){

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

//Displays all of the player's active quests.
//Pre:  The QuestLog is valid.
//Post: Displays all quests marked as active but not complete.
void QuestLog::displayActiveQuests(){

    std::string allActiveQuests = 
        "------------------------Active Quests-------------------------,";

    std::map<std::string , Quest*>::iterator questIter = _quests.begin();

    if(questIter == _quests.end()){
        
        allActiveQuests += "None;";
    }

    //Get quest name and add it to the list.
    else{ 
        for(int i = 0 ; i < _quests.size() ; i++ , questIter++){

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

    Menu menu(allActiveQuests , fontStore->getFont("default"));
    menu.formatText();
    //TextBox activeQuests(allActiveQuests , fontStore->getFont("default"));
    menu.draw();
    //activeQuests.draw();
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