#include "LoadExitsForHomeTownShop.h"

void LoadExitsForHomeTownShop::LoadExitsForHomeTownShop(
    AreaMap *homeTownShop , AreaMap *homeTown){

    homeTownShop->loadExit(4 , 7 , homeTown , 29 , 12);
    homeTownShop->loadExit(3 , 7 , homeTown , 28 , 12);
}