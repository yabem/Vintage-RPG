//Augmentation for a CharacterStat provide a time constrained
//boost to a Character's stat.

#pragma once
#include <string>
#include "Conversion.h"

class StatAugment{

private:

    std::string _nameOfAugment;
    std::string _statToAugment;
    float _augmentAmount;
    float _totalDuration;
    float _currentDuration;
    
public:

    StatAugment(
        std::string nameOfAugment , 
        std::string statToAugment ,
        float augmentAmount , 
        float totalDuration);

    ~StatAugment();
    std::string getStatToAugment();
    std::string getNameOfAugment();
    void increaseCurrentDuration();
    bool isDurationExpired();
    float getAugmentAmount();
};