#include "LoadExitsForEasternCastle.h"

void LoadExitsForEasternCastle::LoadExitsForEasternCastle(
    AreaMap *easternCastle , AreaMap *westArea , AreaMap *insideCastle){

    //West exit.
    easternCastle->loadExit(0 , 29 , westArea , 48 , 25);
    easternCastle->loadExit(0 , 30 , westArea , 48 , 25);
    easternCastle->loadExit(0 , 31 , westArea , 48 , 25);
    easternCastle->loadExit(0 , 32 , westArea , 48 , 25);
    easternCastle->loadExit(0 , 33 , westArea , 48 , 25);

    //Castle exit.
    easternCastle->loadExit(18 , 42 , insideCastle , 17 , 38);
    easternCastle->loadExit(19 , 42 , insideCastle , 18 , 38);
    easternCastle->loadExit(20 , 42 , insideCastle , 19 , 38);
    easternCastle->loadExit(21 , 42 , insideCastle , 20 , 38);
}