#pragma once
#include "Stats.h"
#include "GameConfig.h"
#include <vector>
#include "I_CharacterValuesList.h"


class CharStats: public Stats{

private:

    
    int ttlXPGained;    //Total gained experience.
    int currLvlXP;      //Total XP for this level.
    int toLvlXP;        //Remaining XP to next level.    
    int xpRewardForSlaying; //The amount of XP awarded for killing this creature.
    int moneyRewardForSlaying;  //The amount of money awarded for killing the creature.
    I_CharacterValuesList *XPToLevel;    //Stores the amount needed to level.
    std::vector<std::string> listOfRewards;

public:

    //Constructor.
    CharStats(int level , int baseHP , int baseMP , int baseAtk ,
        int baseDef , int ttlXPGained , int currLvlXP , int toLvlXP ,
        float speed , int xpRewardForSlaying , int moneyRewardForSlaying ,
        std::vector<std::string> listOfRewards);
    
    virtual ~CharStats();   //Destructor.

    int getTtlXPGained() const;     //Total gained XP.

    //Reward for killing the Character.
    virtual int getXPRewardForSlaying() const;
    virtual int getMoneyRewardForSlaying() const;

    //Returns listOfRewards.
    virtual std::vector<std::string>getRewards() const; 
    virtual void addReward(std::string reward);

    int getCurrLvlXP() const;       //Returns currLvlXP.
    int getToLvlXP() const;         //Returns toLvlXP.
    void addToTtlXP(int amount);     //Add to ttlXPGained.
    bool hasLeveledUp();    //Checks if the character has leveled up.

    virtual void setToLvlXP(int toLvlXP);  //Sets the ToLvlXP.

    //Retrieves a summary of the pertinent stats to display.
    virtual std::string getSummary();  
};