//Holds the calculations for attack damage.

#pragma once
#include "Character.h"
#include "Conversion.h"

namespace DamageCalculations{

    int damageWithoutDelayAtk(Character *initiator , Character *receiver);

    int damageWithDelayAtk(Character *initiator , Character *receiver,
        float damageMultiplier , float delayMultiplier);

    int damageWithoutDelayMgc(Character *initiator , Character *receiver);

    int damageWithDelayAtk(Character *initiator , Character *receiver,
        float damageMultiplier , float delayMultiplier);

    int damageWithDelayMgc(Character *initiator , Character *receiver,
        float damageMultiplier , float delayMultiplier);
}