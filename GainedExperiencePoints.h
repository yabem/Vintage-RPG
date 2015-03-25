//A reward of experience points.

#pragma once
#include "I_Reward.h"
#include "I_List.h"
#include "Character.h"
#include "GameConfig.h"

class GainedExperiencePoints : public I_Reward{

private:

    int amountGained;
    I_List *listOfPlayers;

public:
    GainedExperiencePoints();
    GainedExperiencePoints(I_List *listOfPlayers , int amountOfPoints);
    virtual ~GainedExperiencePoints();
    virtual bool deliverToPlayer();
    virtual std::string getName();
    virtual int getAmount();
};