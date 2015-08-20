#include "LoadExitsForCastle.h"

void LoadExitsForCastle::LoadExitsForCastle(
    AreaMap *castle , AreaMap *easternCastleArea){

    //South exit.
    castle->loadExit(16 , 39 , easternCastleArea , 17 , 43);
    castle->loadExit(17 , 39 , easternCastleArea , 17 , 43);
    castle->loadExit(18 , 39 , easternCastleArea , 18 , 43);
    castle->loadExit(19 , 39 , easternCastleArea , 19 , 43);
    castle->loadExit(20 , 39 , easternCastleArea , 20 , 43);
}