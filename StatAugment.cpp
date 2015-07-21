#include "StatAugment.h"

//Constructor.
StatAugment::StatAugment(
    std::string nameOfAugment , 
    std::string statToAugment ,
    float augmentAmount , 
    float totalDuration){

        _currentDuration = 0;
        _nameOfAugment = nameOfAugment;
        _statToAugment = statToAugment;
        _augmentAmount = augmentAmount;
        _totalDuration = totalDuration;
}

//Destructor.
StatAugment::~StatAugment(){

    //Default is fine.
}

//Returns _statToAugment.
std::string StatAugment::getStatToAugment(){

    return _statToAugment;
}

//Returns _nameOfAugment.
std::string StatAugment::getNameOfAugment(){

    return _nameOfAugment;
}

//Returns _currentDuration.
void StatAugment::increaseCurrentDuration(){

    _currentDuration += Conversion::getBattleTimeIncrement();
}

//Determines if the augment has run it's course.
//Pre:  None.
//Post: If the _currentDuration is >= _totalDuration return true.
//      Otherwise return false.
bool StatAugment::isDurationExpired(){

    if(_currentDuration >= _totalDuration){

        return true;
    }

    else{
        return false;
    }
}

//Returns the _augmentAmount.
float StatAugment::getAugmentAmount(){

    return _augmentAmount;
}