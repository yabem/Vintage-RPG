//Holds all the information that defines a player such as the
//Inventory, available characters, etc.

#pragma once
#include "Backpack.h"
#include "CharacterList.h"
#include "ImageStore.h"
#include "CharStats.h"
#include "AddAbilityToCharacterInList.h"
#include "QuestLog.h"

class PlayerEntity{

private:

    Backpack *backpack;
    ImageStore *imageStore;
    CharacterList *thePlayers;
    QuestLog *questLog;
    FontStore *fontStore;

public:

    PlayerEntity(ImageStore *imageStore , FontStore *fontStore);
    ~PlayerEntity();
    bool createBackpack();
    bool createQuestLog();
    void displayActiveQuestsInQuestLog();
    void displayCompletedQuestsInQuestLog();
    bool addQuest(std::string questName , Quest *quest);
    void updateQuestLog(std::vector<std::string> list);
    void loadDefaultPlayers();
    Backpack* getPlayerInventory();
    CharacterList* getThePlayers();
    Character* getFirstPlayer();
};