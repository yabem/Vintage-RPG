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

//Returns ttlHP plus any bonuses.
int Stats::getTtlHP() const{

    return baseHP;
}

//Returns currHP.
int Stats::getCurrHP() const{

    return currHP;
}    

//Returns baseMP.
int Stats::getBaseMP() const{

    return baseMP;
}

//Returns ttlMP plus any bonuses.
int Stats::getTtlMP() const{

    return baseMP;
}

//Returns currMP.
int Stats::getCurrMP() const{

    return currMP;
}

//Returns baseAtk.
int Stats::getBaseAtk() const{

    return baseAtk;
}

//Returns baseAtk plus any bonuses.
int Stats::getTtlAtk() const{

    return baseAtk;
}

//Returns baseDef.
int Stats::getBaseDef() const{

    return baseDef;
}

//Returns ttlDef plus any bonuses.
int Stats::getTtlDef() const{

    return baseDef;
}     

//Returns the speed.
float Stats::getSpeed() const{

    return speed;
}

//Returns the level.
void Stats::setLevel(int level){

    this->level = level;
}

//Sets the baseHP.
void Stats::setBaseHP(int baseHP){

    this->baseHP = baseHP;
}

//Sets the currHP.
void Stats::setCurrHP(int currHP){

    this->currHP = currHP;
}

//Sets the baseMP.
void Stats::setBaseMP(int baseMP){

    this->baseMP = baseMP;
}

//Sets the baseAtk.
void Stats::setBaseAtk(int baseAtk){

    this->baseAtk = baseAtk;
}

//Sets the baseDef.
void Stats::setBaseDef(int baseDef){

    this->baseDef = baseDef;
}

//Sets the speed.
void Stats::setSpeed(int speed){

    this->speed = speed;
}

//Returns the XP reward.
int Stats::getXPRewardForSlaying() const{

    return 0;
}

//Returns money reward.
int Stats::getMoneyRewardForSlaying() const{

    return 0;
}

//Returns the rewards.
std::vector<std::string> Stats::getRewards() const{

    std::vector<std::string> temp;

    return temp;
}

//Adds a reward.
void Stats::addReward(std::string reward){

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

//Gets the role.
std::string Stats::getRole(){

    return role;
}


//Sets the role.
void Stats::setRole(std::string role){

    this->role = role;
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

//Recreates the player's stats.
//Pre:  None.
//Post: Permanently updates the statsDisplay.
std::string Stats::getSummary(){

    std::string statsSummary = "";

    char tempChar[10];

    statsSummary += "Class: ";
    statsSummary += role;
    
    statsSummary += "   Level: ";
    _itoa_s(level , tempChar , 10);
    statsSummary += tempChar; 

    statsSummary += "   HP: ";
    _itoa_s(currHP , tempChar , 10);
    statsSummary += tempChar; 
    statsSummary += "/";
    _itoa_s(ttlHP , tempChar , 10);
    statsSummary += tempChar; 

    statsSummary += "   Attack: ";
    _itoa_s(ttlAtk , tempChar , 10);
    statsSummary += tempChar; 

    statsSummary += "   Defense: ";
    _itoa_s(ttlDef , tempChar , 10);
    statsSummary += tempChar; 

    statsSummary += "   Speed: ";
    _itoa_s(speed , tempChar , 10);
    statsSummary += tempChar; 

    return statsSummary;
}