#include "Stats.h"

//Default constuctor.
Stats::Stats(){

    this->level = 0;
    this->baseHP = 0;
    this->currHP = 0;
    this->ttlHP = 0;

    this->baseMP = 0;
    this->currMP = 0;
    this->ttlMP = 0;

    this->baseAtk = 0;
    this->ttlAtk = 0;

    this->baseDef = 0;
    this->ttlAtk = 0;

}

//Constructor.
Stats::Stats(int level , int baseHP , int baseMP , int baseAtk , int baseDef){

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
    this->ttlAtk = baseDef;
}

Stats::~Stats(){

    //Default destructor is fine.
}

//Returns character's level.
int Stats::getLevel() const{

    return level;
}

//Returns BaseHP.
int Stats::getBaseHP() const{

    return baseHP;
}

//Returns ttlHP.
int Stats::getTtlHP() const{

    return ttlHP;
}

//Returns currHP.
int Stats::getCurrHP() const{

    return currHP;
}    

//Returns baseMP.
int Stats::getBaseMP() const{

    return baseMP;
}

//Returns ttlMP.
int Stats::getTtlMP() const{

    return ttlMP;
}

//Returns currMP.
int Stats::getCurrMP() const{

    return currMP;
}

//Returns baseAtk.
int Stats::getBaseAtk() const{

    return baseAtk;
}

//Returns ttlAtk.
int Stats::getTtlAtk() const{

    return ttlAtk;
}

//Returns baseDef.
int Stats::getBaseDef() const{

    return baseDef;
}

//Returns ttlDef.
int Stats::getTtlDef() const{

    return ttlDef;
}     

//Adds to currHP.
void Stats::addToCurrHP(int amount){

    currHP += amount;
}