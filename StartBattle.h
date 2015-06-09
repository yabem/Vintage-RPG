//Initiates a battle.

#pragma once
#include "Cutscene.h"
#include "BattleManager.h"

class StartBattle : public Cutscene{

private:

    BattleManager *battleManager;
    std::vector<int> enemyList;
    std::vector<int> enemyLevels;

public:

    StartBattle(BattleManager *battleManager , std::vector<int> enemyList , 
        std::vector<int> enemyLevels);
    ~StartBattle();
    virtual bool play(const int pressedKey); 
};