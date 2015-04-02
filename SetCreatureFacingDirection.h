//Sets the I_Creature's facing direction.

#pragma once
#include "I_Animation.h"
#include "I_Creature.h"

class SetCreatureFacingDirection : public I_Animation{

private:

    I_Creature *i_Creature;
    int facingDirection;

public:

    SetCreatureFacingDirection(I_Creature *i_Creature , int facingDirection);
    virtual ~SetCreatureFacingDirection();
    virtual bool play();
};