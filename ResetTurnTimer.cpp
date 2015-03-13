#include "ResetTurnTimer.h"

//Constructor.
ResetTurnTimer::ResetTurnTimer(TurnTimer *turnTimer){

    this->turnTimer = turnTimer;
}

//Destructor.
ResetTurnTimer::~ResetTurnTimer(){

}
    
//Resets the TurnTimer.
//Pre:  The TurnTimer is valid.
//Post: Always returns true.
bool ResetTurnTimer::execute(){

    turnTimer->resetCurrentFill();
    return true;
}