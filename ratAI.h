//Stores the AI for rats.

#pragma once
#include "I_AI.h"
#include "I_List.h"
#include "CharacterManipulationStore.h"
//#include "I_Manager.h"
#include <string>
#include <vector>

class ratAI : public I_AI{

private:

    CharacterManipulationStore *characterManipulationStore;
    //vector<std::string> possibleAttacks;
    I_List *listOfPlayers;
    I_List *listOfEnemies;

public:

    //Constuctor.
    ratAI(CharacterManipulationStore *characterManipulationStore ,
        I_List *listOfPlayers , I_List *listOfEnemies);

    //Destructor.
    virtual ~ratAI();

    virtual void executeBattleLogic();
};