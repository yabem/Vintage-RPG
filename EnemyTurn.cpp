#include "EnemyTurn.h"

//Constructor.
EnemyTurn::EnemyTurn(I_AI *i_AI , DrawRepository *drawRepository){

    this->i_AI = i_AI;
    this->drawRepository = drawRepository;
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

    //Execute for the first time.
    if(!isExecuted){
        i_AI->executeBattleLogic();
        isExecuted = true;
        return false;
    }

    //Enemy turn is not done yet.
    else if(!drawRepository->animationsEmpty())
        return false;  
    
    //Execution is complete.
    else return true;
}