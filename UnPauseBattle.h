//Unpauses the battle so the battle resumes.

#pragma once
#include "I_Animation.h"
#include "I_Manager.h"

class UnPauseBattle : public I_Animation{

private:

    //The manager that is paused.
    I_Manager *battleManager;

public:

    //Constructor.
    UnPauseBattle(I_Manager *i_Manager);
    
    //Initiates the pause.
    virtual bool play();
};