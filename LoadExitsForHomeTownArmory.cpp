#include "LoadExitsForHomeTownArmory.h"

void LoadExitsForHomeTownArmory::LoadExitsForHomeTownArmory(
    AreaMap *homeTownArmory , AreaMap *homeTown){

    homeTownArmory->loadExit(3 , 7 , homeTown , 37 , 12);
    homeTownArmory->loadExit(4 , 7 , homeTown , 38 , 12);
}