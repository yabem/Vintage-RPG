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

    this->speed = 2;

    this->dead = false;
}

//Constructor.
Stats::Stats(int level , int baseHP , int baseMP , int baseAtk , int baseDef ,
    float speed){

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

    this->dead = false;

    this->speed = speed;
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

//Returns the speed.
float Stats::getSpeed() const{

    return speed;
}

//Adds to currHP.
//Pre:  The currHP is initialized.
//Post: The amount is added to the currHP.
//      If the result is over the ttlHP, the
//      currHP are increased to equal the ttlHP.
//      If the currHP result is below 0, the Character
//      is dead and the dead status will be set to true.
void Stats::addToCurrHP(int amount){

    currHP += amount;

    if(currHP >= ttlHP)
        currHP = ttlHP;

    if(currHP <= 0){
     
        currHP = 0;
        dead = true;
    }
}

//Determines if currHP are all gone.
//Pre:  The Stats object has been initialized.
//Post: Returns true if the currHP are 0. Returns
//      false if currHP is > 0.
bool Stats::isDead(){

    return dead;
}

//Sets the dead status to true.
//Pre:  The Stats object has been initialized.
//Post: Changes the isDead bool to true.
void Stats::makeDead(){

    dead = true;
}

//Sets the dead status to false.
//Pre:  The Stats object has been initialized.
//Post: Changes the isDead bool to false.
void Stats::makeAlive(){

    dead = false;
}