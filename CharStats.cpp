#include "CharStats.h"

//Constructor.
CharStats::CharStats(int level , int baseHP , int baseMP , int baseAtk ,
    int baseDef , int ttlXPGained , int currLvlXP , int toLvlXP ,
    float speed , int xpRewardForSlaying , int moneyRewardForSlaying ,
    std::vector<std::string> listOfRewards){

    this->level = level;
    this->baseHP = baseHP;
    this->currHP = baseHP;
    this->ttlHP = baseHP;

    this->baseMP = baseMP;
    this->currMP = baseMP;
    this->ttlMP = baseMP;

    this->baseAtk = baseAtk;
    this->ttlAtk = baseAtk;

    this->baseDef = baseDef;
    this->ttlDef = baseDef;

    this->ttlXPGained = ttlXPGained;
    this->currLvlXP = currLvlXP;
    this->toLvlXP = toLvlXP;

    this->speed = speed;

    this->xpRewardForSlaying = xpRewardForSlaying;
    this->moneyRewardForSlaying = moneyRewardForSlaying;

    this->listOfRewards = listOfRewards;
}
 
//Destructor.
CharStats::~CharStats(){
    
    //Default is fine.
}

//Total gained XP.
int CharStats::getTtlXPGained() const{

    return ttlXPGained;
}

//Returns XPRewardForSlaying.
int CharStats::getXPRewardForSlaying() const{

    return this->xpRewardForSlaying;
}

//Returns moneyRewardForSlaying
int CharStats::getMoneyRewardForSlaying() const{

    return this->moneyRewardForSlaying;
}

//Returns currLvlXP;
int CharStats::getCurrLvlXP() const{

    return currLvlXP;
}

//Returns toLvlXP;
int CharStats::getToLvlXP() const{

    return toLvlXP;
}

//Increases the total xp by the amount.
void CharStats::addTottlXPGained(int amount){

    ttlXPGained += amount;
}

//Returns listOfRewards.
std::vector<std::string> CharStats::getRewards() const{

    return listOfRewards;
}

//Adds a reward to listOfRewards.
void CharStats::addReward(std::string reward){

    listOfRewards.push_back(reward);
}