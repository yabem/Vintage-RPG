#include "CharStats.h"

//Constructor.
CharStats::CharStats(int level , int baseHP , int baseMP , int baseAtk , int baseDef ,
    int ttlXP , int currLvlXP , int toLvlXP , float speed){

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

    this->ttlXP = ttlXP;
    this->currLvlXP = currLvlXP;
    this->toLvlXP = toLvlXP;

    this->speed = speed;
}
 
//Destructor.
CharStats::~CharStats(){
    
    //Default is fine.
}

//Total gained XP.
int CharStats::getTtlXP() const{

    return ttlXP;
}

//Returns currLvlXP;
int CharStats::getCurrLvlXP() const{

    return currLvlXP;
}

//Returns toLvlXP;
int CharStats::getToLvlXP() const{

    return toLvlXP;
}