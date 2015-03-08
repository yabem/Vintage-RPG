//Pauses the battle so the timers don't move.
#pragma once
#include "Animation.h"
#include "I_Manager.h"

class PauseBattle : public Animation{

private:

    //The manager that is paused.
    I_Manager *battleManager;

public:

    //Constructor.
    PauseBattle(I_Manager *i_Manager);
    
    //Initiates the pause.
    virtual bool play();
};