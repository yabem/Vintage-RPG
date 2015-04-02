#include "I_Creature.h"

I_Creature::~I_Creature(){}

std::string I_Creature::getAbilities(){return "";}

bool I_Creature::isPlayable() const{return false;}

bool I_Creature::isDead(){return false;}

void I_Creature::makeDead(){}

Stats* I_Creature::getStats(){return NULL;}

int I_Creature::getXPReward(){return 0;}

int I_Creature::getMoneyReward(){return 0;}

int I_Creature::getCurrHP(){return 0;}

int I_Creature::getTtlHP(){return 0;}

void I_Creature::setX(int x){}

void I_Creature::setY(int y){}

void I_Creature::setImage(ALLEGRO_BITMAP *image){}

bool I_Creature::setFacing(int direction){return false;}