//An item or anything that is awarded to the player after
//a completed battle or quest.

#pragma once
#include <string>

class I_Reward{

private:


public:

    I_Reward();
    virtual ~I_Reward();
    virtual bool deliverToPlayer() = 0;
    virtual std::string getName() = 0;
    virtual int getAmount() = 0;
};