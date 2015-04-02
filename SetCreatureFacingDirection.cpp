#include "SetCreatureFacingDirection.h"

//Constructor.
SetCreatureFacingDirection::SetCreatureFacingDirection(I_Creature *i_Creature ,
    int facingDirection){

    this->i_Creature = i_Creature;
    this->facingDirection = facingDirection;
}

//Destructor.
SetCreatureFacingDirection::~SetCreatureFacingDirection(){

    //Default destructor is fine.
}

//Changes the I_Creature's facing direction.
//Pre:  None.
//Post: The facing direction must be within the bounds 
//      of UP, DOWN, LEFT, or RIGHT. Always returns true since
//      the function is executed exactly 1 time.
bool SetCreatureFacingDirection::play(){

    i_Creature->setFacing(facingDirection);

    return true;
}