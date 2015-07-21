#include "DamageCalculations.h"

int DamageCalculations::damageWithoutDelay(
    Character *initiator , Character *receiver){

    //Get attack and defense for calculation.
    int charAAttack = initiator->getAttack();
    int charBDefense = receiver->getDefense();

    int damageToReceiver = charAAttack - charBDefense;

    //No damage done, the defense negated the attack.
    if(damageToReceiver < 0)
        damageToReceiver = 0;

    return damageToReceiver;
}

int DamageCalculations::damageWithDelay(
    Character *initiator , Character *receiver,
    float damageMultiplier , float delayMultiplier){

        //Get attack and defense for calculation.
        int charAAttack = initiator->getAttack() * damageMultiplier;
        int charBDefense = receiver->getDefense();

        int damageToReceiver = charAAttack - charBDefense;

        //No damage done, the defense negated the attack.
        if(damageToReceiver < 0){

            damageToReceiver = 0;
        }

        float baseSpeed = initiator->getStats()->getSpeed();
        float speedAugmentAmount = (baseSpeed * delayMultiplier) - baseSpeed;

        //Gets rid of the rounding issue with floats.
        float timingBuffer = Conversion::getBattleTimeIncrement();

        //Delay lasts the length of the next turn.
        float lengthOfDelay = baseSpeed + speedAugmentAmount - timingBuffer;

        initiator->getStats()->loadAugment(
            "JumpDelay" , "speed" , speedAugmentAmount , lengthOfDelay); 

        return damageToReceiver;
}