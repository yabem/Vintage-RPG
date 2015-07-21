//Holds all the stats for each type of character's level.

#pragma once
#include "CharStats.h"
#include "GameConfig.h"

const int MAX_LEVEL_INDEX = MAX_CHARACTER_LEVEL + 1;

class StatsByLevel{

private:

    struct StatSheetForLevel{
        int _level;
        int _HP; 
        int _MP;
        int _Atk;
        int _Def;
        float _speed;
        int _XPToAchieveLevel;
    };

    std::vector<StatSheetForLevel*> _listOfStats;
    int _maxLevel;

public:

    StatsByLevel();
    ~StatsByLevel();
    void loadLevelStats(int level , int HP , int MP , int atk ,
        int def , float speed , int XPToAchieveLevel);
    int getHPAtLevel(int level);
    int getMPAtLevel(int level);
    int getAtkAtLevel(int level);
    int getDefAtLevel(int level);
    float getSpeedAtLevel(int level);
    int getXPToAchieveLevelAtLevel(int level);
    void removeAllStats();
    void resizeWithNulls();
};