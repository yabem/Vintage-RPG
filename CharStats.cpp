#include "CharStats.h"

//Constructor.
CharStats::CharStats(int level , int baseHP , int baseMP , int baseAtk ,
    int baseMgc, int baseDef , int ttlXPGained , int currLvlXP , int toLvlXP ,
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

    this->baseMgc = baseMgc;
    this->ttlMgc = baseMgc;

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

//Sets the CurrLvlXP.
void CharStats::setTtlXPGained(int ttlXPGained){

    this->ttlXPGained = ttlXPGained;
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

    statsSummary += role;
    statsSummary += ":";
    
    statsSummary += " Lvl:";
    statsSummary += Conversion::convertIntToString(getLevel());

    statsSummary += " HP:";
    statsSummary += Conversion::convertIntToString(getCurrHP());
    statsSummary += "/";
    statsSummary += Conversion::convertIntToString(getTtlHP());

    statsSummary += " Atk:";
    statsSummary += Conversion::convertIntToString(getTtlAtk());

    statsSummary += " Mgc:";
    statsSummary += Conversion::convertIntToString(getTtlMgc());

    statsSummary += " Spd:";
    statsSummary  += Conversion::convertFloatToString(getSpeed());

    statsSummary += "  XP:";
    _itoa_s(getTtlXPGained() , tempChar , 10);
    statsSummary += Conversion::convertIntToString(getTtlXPGained());

    statsSummary += "  XPtoLvl:";
    statsSummary += Conversion::convertIntToString(getToLvlXP());

    return statsSummary;
}
