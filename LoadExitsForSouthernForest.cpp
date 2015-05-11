#include "LoadExitsForSouthernForest.h"

void LoadExitsForSouthernForest::LoadExitsForSouthernForest(
    AreaMap *southernForest , AreaMap *northArea){

    //North exit.
    southernForest->loadExit(15 , 0 , northArea , 25 , 48);
    southernForest->loadExit(16 , 0 , northArea , 25 , 48);
    southernForest->loadExit(17 , 0 , northArea , 25 , 48);
    southernForest->loadExit(18 , 0 , northArea , 25 , 48);
    southernForest->loadExit(19 , 0 , northArea , 25 , 48);
}