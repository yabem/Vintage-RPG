#include "DamageCalculations.h"

int DamageCalculations::damageWithoutDelayAtk(
    Character *initiator , Character *receiver){

    //Get attack and defense for calculation.
    int initiatorAtk = initiator->getStats()->getTtlAtk();
    int receiverDef = receiver->getStats()->getTtlDef();

    int damageToReceiver = initiatorAtk - receiverDef;

    //No damage done, the defense negated the attack.
    if(damageToReceiver < 0)
        damageToReceiver = 0;

    return damageToReceiver;
}

int DamageCalculations::damageWithoutDelayMgc(
    Character *initiator , Character *receiver){

    //Get attack and defense for calculation.
    int initiatorMgc = initiator->getStats()->getTtlMgc();
    int receiverDefense = receiver->getStats()->getTtlDef();

    int damageToReceiver = initiatorMgc - receiverDefense;

    //No damage done, the defense negated the attack.
    if(damageToReceiver < 0)
        damageToReceiver = 0;

    return damageToReceiver;
}

int DamageCalculations::damageWithDelayAtk(
    Character *initiator , Character *receiver,
    float damageMultiplier , float delayMultiplier){

        //Get attack and defense for calculation.
        int initiatorAtk = initiator->getStats()->getTtlAtk() * damageMultiplier;
        int receiverDef = receiver->getStats()->getTtlDef();

        int damageToReceiver = initiatorAtk - receiverDef;

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
            "abilityDelay" , "speed" , speedAugmentAmount , lengthOfDelay); 

        return damageToReceiver;
}

int DamageCalculations::damageWithDelayMgc(
    Character *initiator , Character *receiver,
    float damageMultiplier , float delayMultiplier){

        //Get attack and defense for calculation.
        int initiatorMgc = initiator->getStats()->getTtlMgc() * damageMultiplier;
        int receiverDef = receiver->getStats()->getTtlDef();

        int damageToReceiver = initiatorMgc - receiverDef;

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
            "abilityDelay" , "speed" , speedAugmentAmount , lengthOfDelay); 

        return damageToReceiver;
}