//Stores the stats for each character's level.

#pragma once
#include "StatsByLevel.h"
#include <map>

class StatsByLevelStore{

private:
    
    std::map<std::string , StatsByLevel*> _statsStore;

public:

    StatsByLevelStore();
    ~StatsByLevelStore();
    void loadAllCharacterStats();
    void removeAllCharacterStats();
    int getHPForClassLevel(std::string characterClass , int level);
    int getMPForClassLevel(std::string characterClass , int level);
    int getAtkForClassLevel(std::string characterClass , int level);
    int getDefForClassLevel(std::string characterClass , int level);
    int getSpeedForClassLevel(std::string characterClass , int level);
    int getXPForClassLevel(std::string characterClass , int level);
};