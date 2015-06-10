//Quest that can be finished by killing enemies.

#pragma once
#include "Quest.h"
#include <queue>

class KillQuest : public Quest{

private:

    struct Objective{

        std::string displayName;
        std::string enemy;
        int totalToKill;
        int numberKilled;
    };

    std::string _displayName;
    bool _isCompletedByPlayer;
    bool _isActiveForPlayer;
    bool _mustBeActiveForPlayerToUpdate;
    std::vector<Objective*> _objectives; 

public:

    KillQuest();
    virtual ~KillQuest();
    virtual bool completedByPlayer();
    virtual void makeCompletedByPlayer();
    virtual bool isActiveForPlayer();
    virtual void makeActiveForPlayer();
    virtual void makeInactiveForPlayer();
    virtual bool objectivesAreUpdateable();
    void setMustBeActiveForPlayerToUpdate();
    virtual void updateQuestObjectives(std::vector<std::string> list);
    virtual void checkComplete();
    void addObjective(std::string enemy , int numberToKill);
    void emptyObjectives();
    virtual void setQuestDisplayName(std::string displayName);
    virtual std::string getQuestDisplayName();
    virtual std::string getObjectiveSummary();
};