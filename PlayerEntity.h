//Holds all the information that defines a player such as the
//Inventory, available characters, etc.

#pragma once
#include "Backpack.h"
#include "CharacterList.h"
#include "ImageStore.h"
#include "CharStats.h"
#include "AddAbilityToCharacterInList.h"
#include "QuestLog.h"
#include "InfoTable.h"
#include "StatsByLevelStore.h"
#include "LevelUpCalculations.h"

//#define ALL_ABILITIES
//#define MAX_LEVEL

class PlayerEntity{

private:

    Backpack *backpack;
    ImageStore *imageStore;
    CharacterList *thePlayers;
    QuestLog *questLog;
    FontStore *fontStore;
    InfoTable *partyStatusDisplay;
    StatsByLevelStore *statsByLevelStore;

public:

    PlayerEntity(ImageStore *imageStore , FontStore *fontStore ,
        StatsByLevelStore *statsByLevelStore);
    ~PlayerEntity();
    bool createBackpack();
    bool createQuestLog();

    void displayActiveQuestsInQuestLog();
    void displayCompletedQuestsInQuestLog();
    void updateQuestDisplays();
    void displayPlayerStats();
    void updatePartyStatusDisplay();
    void centerPartyStatusDisplayToScreen();

    bool addQuest(std::string questName , Quest *quest);
    void updateQuestLog(std::vector<std::string> list);
    void loadDefaultPlayers();

    Backpack* getPlayerInventory();
    CharacterList* getThePlayers();
    Character* getFirstPlayer();

};