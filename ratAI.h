//Stores the AI for rats.

#pragma once
#include "I_AI.h"
#include "I_List.h"
#include "Character.h"
#include "CharacterManipulationStore.h"
#include <string>
#include <vector>
class DrawRepository;

class ratAI : public I_AI{

private:

    //Used to execute an attack against the player.
    CharacterManipulationStore *characterManipulationStore;
    
    //List of eligible attacks.
    vector<std::string> possibleAttacks;

    //A pointer to the enemy initiating the attack.
    Character *initiator;

    //All the players.
    I_List *listOfPlayers;

    //All the enemies.
    I_List *listOfEnemies;

    //Used to load animations.
    DrawRepository *drawRepository;

public:

    //Constuctor.
    ratAI(Character *initiator , 
        CharacterManipulationStore *characterManipulationStore ,
        I_List *listOfPlayers , 
        I_List *listOfEnemies ,
        DrawRepository *drawRepository);

    //Destructor.
    virtual ~ratAI();

    //Attacks a random player.
    virtual void executeBattleLogic();
};