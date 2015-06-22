//Holds all the quests for the player.

#pragma once
#include "Quest.h"
#include <map>
#include "TextBox.h"
#include "FontStore.h"

#include "InfoTable.h"

class QuestLog{

private:

    std::map<std::string , Quest*> _quests;
    FontStore *fontStore;
    InfoTable *activeQuestDisplay;
    InfoTable *completedQuestDisplay;
    void centerActiveQuestDisplayToScreen();
    void centerCompletedQuestDisplayToScreen();

public:

    QuestLog(FontStore *fontStore);
    ~QuestLog();
    bool addQuest(std::string questName , Quest *quest);
    void updateAllQuestObjectives(std::vector<std::string> listOfAccomplishments);
    void removeAllQuests();
    void updateQuestDisplay();
    void updateActiveQuestsDisplay();
    void updateCompletedQuestsDisplay();
    void displayActiveQuests();
    void displayCompletedQuests();
    Quest* getQuest(std::string questName);
};