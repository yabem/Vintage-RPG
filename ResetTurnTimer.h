//Resets a turntimer.

#pragma once
#include "I_Event.h"
#include "TurnTimer.h"

class ResetTurnTimer: public I_Event{

private:

    TurnTimer *turnTimer;

public:

    ResetTurnTimer(TurnTimer *turnTimer);
    virtual ~ResetTurnTimer();
    virtual bool execute();
};