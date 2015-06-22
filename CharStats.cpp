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
void CharStats::addToTtlXP(int amount){

    ttlXPGained += amount;
}

//Checks if the character has leveled up.
//Pre:  None.
//Post: Returns true if ttlXPGained > toLvlXP and the character is not at the
//      max allowable level. Otherwise returns false.
bool CharStats::hasLeveledUp(){

    if(ttlXPGained > toLvlXP && level < MAX_CHARACTER_LEVEL){

        return true;
    }

    return false;
}

//Sets the ToLvlXP.
void CharStats::setToLvlXP(int toLvlXP){

    this->toLvlXP = toLvlXP;
}

//Returns listOfRewards.
std::vector<std::string> CharStats::getRewards() const{

    return listOfRewards;
}

//Adds a reward to listOfRewards.
void CharStats::addReward(std::string reward){

    listOfRewards.push_back(reward);
}

//Recreates the player's stats.
//Pre:  None.
//Post: Permanently updates the statsDisplay.
std::string CharStats::getSummary(){

   std::string statsSummary = "";

    char tempChar[10];

    statsSummary += "Class:";
    statsSummary += role;
    
    statsSummary += " Lvl:";
    _itoa_s(getLevel() , tempChar , 10);
    statsSummary += tempChar; 

    statsSummary += "  HP:";
    _itoa_s(getCurrHP() , tempChar , 10);
    statsSummary += tempChar; 
    statsSummary += "/";
    _itoa_s(getTtlHP() , tempChar , 10);
    statsSummary += tempChar; 

    statsSummary += "  Atk:";
    _itoa_s(getTtlAtk() , tempChar , 10);
    statsSummary += tempChar; 

    statsSummary += "  Def:";
    _itoa_s(getTtlDef() , tempChar , 10);
    statsSummary += tempChar; 

    statsSummary += " Spd:";
    _itoa_s(getSpeed() , tempChar , 10);
    statsSummary += tempChar; 

    statsSummary += "  XP:";
    _itoa_s(getTtlXPGained() , tempChar , 10);
    statsSummary += tempChar; 

    statsSummary += "  XPtoLvl:";
    _itoa_s(getToLvlXP() , tempChar , 10);
    statsSummary += tempChar; 

    return statsSummary;
}
