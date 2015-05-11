#include "LoadExitsForEasternCastle.h"

void LoadExitsForEasternCastle::LoadExitsForEasternCastle(
    AreaMap *easternCastle , AreaMap *westArea){

    //West exit.
    easternCastle->loadExit(0 , 29 , westArea , 48 , 25);
    easternCastle->loadExit(0 , 30 , westArea , 48 , 25);
    easternCastle->loadExit(0 , 31 , westArea , 48 , 25);
    easternCastle->loadExit(0 , 32 , westArea , 48 , 25);
    easternCastle->loadExit(0 , 33 , westArea , 48 , 25);
}