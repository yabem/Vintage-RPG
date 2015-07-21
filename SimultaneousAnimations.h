//Plays multiple animations simulataneously.

#pragma once
#include "I_Animation.h"

class SimultaneousAnimations : public I_Animation{

private:

    std::vector<I_Animation*> animations;

public:

    SimultaneousAnimations();
    ~SimultaneousAnimations();
    void loadAnimation(I_Animation *i_Animation);
    virtual bool play();
    bool allAnimationsAreNULL();
};