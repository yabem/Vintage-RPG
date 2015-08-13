//Loads the exits for the HomeTown map.

#pragma once
#include "AreaMap.h"

namespace LoadExitsForHomeTown{

    void LoadExitsForHomeTown(AreaMap *homeTown , 
        AreaMap *theShop , AreaMap *theArmory , AreaMap *theBar ,
        AreaMap *northArea , AreaMap *westArea ,
        AreaMap *eastArea , AreaMap *southArea);
};