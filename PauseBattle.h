//Pauses the battle so the timers don't move.
#pragma once
#include "I_Animation.h"
#include "I_Manager.h"

class PauseBattle : public I_Animation{

private:

    //The manager that is paused.
    I_Manager *battleManager;

public:

    //Constructor.
    PauseBattle(I_Manager *i_Manager);
    
    //Initiates the pause.
    virtual bool play();
};