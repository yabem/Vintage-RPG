#include "EnemyTurn.h"

//Constructor.
EnemyTurn::EnemyTurn(Character *enemy ,
        DrawRepository *drawRepository ,
        CharacterManipulationStore *characterManipulationStore ,
        I_List *listOfPlayers ,
        I_List *listOfEnemies , 
        I_Manager *battleManager,
        TurnTimer *turnTimer){

    this->enemy = enemy;
    this->drawRepository = drawRepository;
    this->characterManipulationStore = characterManipulationStore;
    this->listOfPlayers = listOfPlayers;
    this->listOfEnemies = listOfEnemies;
    this->i_AI = NULL;
    this->battleManager = battleManager;
    this->turnTimer = turnTimer;

    this->isExecuted = false;
}

//Destructor.
EnemyTurn::~EnemyTurn(){

    delete i_AI;
}

//Executes the enemy's turn.
//Pre:  The AI is loaded.
//Post: Returns false if not done. Returns true if done.
bool EnemyTurn::execute(){

    //Execute the EnemyLogic.
    ratAI *i_AI = new ratAI(enemy ,
        characterManipulationStore , 
        listOfPlayers ,
        listOfEnemies ,
        drawRepository);

    ProcessAI *processAI = new ProcessAI(i_AI , drawRepository);
    battleManager->loadEvent(processAI);

    //Check if any players died after the enemyAI.
    for(int i = 0 ; i < listOfPlayers->getSize() ; i++){

        CheckForDeadPlayer *checkForDeadPlayer = new CheckForDeadPlayer(
            listOfPlayers->getCharacterSelection(i) , 
            drawRepository);

        battleManager->loadEvent(checkForDeadPlayer);
    }

    //Load the ResetTurnTimer event.
    ResetTurnTimer *resetTurnTimer = new ResetTurnTimer(turnTimer);
    battleManager->loadEvent(resetTurnTimer);

    //Load the UpdatePlayersHP event.
    UpdatePlayersHP *updatePlayersHP = new UpdatePlayersHP(battleManager);
    battleManager->loadEvent(updatePlayersHP);

    isExecuted = true;

    return true;
}