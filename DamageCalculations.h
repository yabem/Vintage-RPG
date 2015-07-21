//Holds the calculations for attack damage.

#pragma once
#include "Character.h"
#include "Conversion.h"

namespace DamageCalculations{

    int damageWithoutDelay(Character *initiator , Character *receiver);

    int damageWithDelay(Character *initiator , Character *receiver,
        float damageMultiplier , float delayMultiplier);
}