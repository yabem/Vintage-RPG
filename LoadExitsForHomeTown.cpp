#include "LoadExitsForHomeTown.h"

void LoadExitsForHomeTown::LoadExitsForHomeTown(AreaMap *homeTown , 
        AreaMap *theShop , AreaMap *northernSnow){

    homeTown->loadExit(0 , 25 , northernSnow , 48 , 25);
    homeTown->loadExit(25 , 0 , northernSnow , 25 , 48);
    homeTown->loadExit(49 , 25 , northernSnow , 2 , 25);
    homeTown->loadExit(25 , 49 , northernSnow , 25 , 2);
    homeTown->loadExit(29 , 10 , theShop , 4 , 5);
    homeTown->loadExit(28 , 10 , theShop , 4 , 5);
}