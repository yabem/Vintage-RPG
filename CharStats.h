#pragma once
#include "Stats.h"


class CharStats: public Stats{

private:

    int ttlXP;          //Total gained experience.
    int currLvlXP;      //Total XP for this level.
    int toLvlXP;        //Remaining XP to next level.

public:



    //Constructor.
    CharStats(int level , int baseHP , int baseMP , int baseAtk , int baseDef ,
        int ttlXP , int currLvlXP , int toLvlXP);
    
    virtual ~CharStats();   //Destructor.

    int getTtlXP() const;       //Total gained XP.
    int getCurrLvlXP() const;   //Returns currLvlXP;
    int getToLvlXP() const;        //Returns toLvlXP;
};