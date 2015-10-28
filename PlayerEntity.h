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

#define ADD_TIER_2_ABILITIES
#define ADD_TIER_3_ABILITIES
#define ADD_TIER_4_ABILITIES
#define ADD_TIER_5_ABILITIES

#define PROMOTE_ALL_PLAYERS_TO_LEVEL_2
#define PROMOTE_ALL_PLAYERS_TO_LEVEL_3
#define PROMOTE_ALL_PLAYERS_TO_LEVEL_4
#define PROMOTE_ALL_PLAYERS_TO_LEVEL_5
#define PROMOTE_ALL_PLAYERS_TO_LEVEL_6
#define PROMOTE_ALL_PLAYERS_TO_LEVEL_7
#define PROMOTE_ALL_PLAYERS_TO_LEVEL_8
#define PROMOTE_ALL_PLAYERS_TO_LEVEL_9
#define PROMOTE_ALL_PLAYERS_TO_LEVEL_10

class PlayerEntity{

private:

    Backpack *backpack;
    ImageStore *imageStore;
    CharacterList *thePlayers;
    QuestLog *questLog;
    FontStore *fontStore;
    InfoTable *partyStatusDisplay;
    StatsByLevelStore *statsByLevelStore;

    void appendCommas();

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