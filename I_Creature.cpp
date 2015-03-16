#include "I_Creature.h"

I_Creature::~I_Creature(){}

std::string I_Creature::getAbilities(){return "";}

bool I_Creature::isPlayable() const{return false;}

bool I_Creature::isDead(){return false;}

void I_Creature::makeDead(){}

Stats* I_Creature::getStats(){return NULL;}