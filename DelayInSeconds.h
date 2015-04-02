//Delays the I_Animation playing

#pragma once
#include "I_Animation.h"
#include "GameConfig.h"

class DelayInSeconds : public I_Animation{

private:

    int currentFrame;
    int ttlFrames;

public:

    DelayInSeconds(float finalFrame);
    virtual ~DelayInSeconds();
    virtual bool play();
};