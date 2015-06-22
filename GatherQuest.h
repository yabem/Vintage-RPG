//Quest that can be finished by killing enemies.

#pragma once
#include "KillQuest.h"
#include "Backpack.h"

class GatherQuest : public KillQuest{

protected:

    Backpack *_backpack;

public:

    GatherQuest(Backpack *backpack);
    virtual ~GatherQuest();
    virtual void removeQuestItemsFromBackPack();
    virtual void updateQuestObjectives(std::vector<std::string> list);
};