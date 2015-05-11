#include "LoadExitsForNorthernSnow.h"

void LoadExitsForNorthernSnow::LoadExitsForNorthernSnow(
    AreaMap *northernSnow , AreaMap *homeTown){

    //South exit.
    northernSnow->loadExit(37 , 49 , homeTown , 25 , 2);
    northernSnow->loadExit(38 , 49 , homeTown , 25 , 2);
    northernSnow->loadExit(39 , 49 , homeTown , 25 , 2);
}