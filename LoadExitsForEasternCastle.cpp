#include "LoadExitsForEasternCastle.h"

void LoadExitsForEasternCastle::LoadExitsForEasternCastle(
    AreaMap *easternCastle , AreaMap *westArea){

    //West exit.
    easternCastle->loadExit(0 , 30 , westArea , 48 , 25);
}