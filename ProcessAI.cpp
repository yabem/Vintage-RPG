#include "ProcessAI.h"

//Constructor.
ProcessAI::ProcessAI(I_AI *i_AI , DrawRepository *drawRepository){

    this->i_AI = i_AI;
    this->drawRepository = drawRepository;
    isExecuted = false;
}

//Destructor.
ProcessAI::~ProcessAI(){

}
    
//Executes the AI.
//Pre:  None.
//Post: Executes the AI. Returns true when the execution is
//      complete. Otherwise returns false.
bool ProcessAI::execute(){

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