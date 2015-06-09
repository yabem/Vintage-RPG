//Quests are objectives that can be met by accomplishing things such as 
//killing enemies and collecting loot.

#pragma once
#include <vector>
#include <string>

class Quest{

protected:

public:

    Quest();
    virtual ~Quest();
    virtual bool completedByPlayer() = 0;
    virtual bool isActiveForPlayer() = 0;
    virtual void makeActiveForPlayer() = 0;
    virtual bool objectivesAreUpdateable() = 0;
    virtual void updateQuestObjectives(std::vector<std::string> list) = 0;
    virtual void checkComplete() = 0;
    virtual void setQuestDisplayName(std::string displayName) = 0;
    virtual std::string getQuestDisplayName() = 0;
    virtual std::string getObjectiveSummary() = 0;
};