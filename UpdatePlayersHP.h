//Updates the player's HP for displaying.

#pragma once
#include "I_Event.h"
#include "I_Manager.h"

class UpdatePlayersHP : public I_Event{

private:

    I_Manager *battleManager;

public:

    UpdatePlayersHP(I_Manager *battleManager);
    virtual ~UpdatePlayersHP();
    virtual bool execute();
};