#include "LoadExitsForNorthernSnow.h"

void LoadExitsForNorthernSnow::LoadExitsForNorthernSnow(
    AreaMap *northernSnow , AreaMap *homeTown){

    //South exit.
    northernSnow->loadExit(38 , 49 , homeTown , 25 , 2);
}