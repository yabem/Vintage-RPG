//Stores the AI for rats.

#pragma once
#include "I_AI.h"
#include "CharacterManipulationStore.h"
#include "BattleManager.h"
#include <string>
#include <vector>

class ratAI : public I_AI{

private:

    CharacterManipulationStore *characterManipulationStore;
    vector<std::string> possibleAttacks;

public:
    //Constuctor.
    ratAI();

    //Destructor.
    virtual ~ratAI();

    virtual void executeBattleLogic();
};