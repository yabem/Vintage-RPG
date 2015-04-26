#include "LoadExitsForNorthernSnow.h"

void LoadExitsForNorthernSnow::LoadExitsForNorthernSnow(
    AreaMap *northernSnow , AreaMap *homeTown){

    northernSnow->loadExit(0 , 25 , homeTown , 48 , 25);
    northernSnow->loadExit(25 , 0 , homeTown , 25, 48);
    northernSnow->loadExit(49 , 25 , homeTown , 2 , 25);
    northernSnow->loadExit(25 , 49 , homeTown , 25 , 2);
}