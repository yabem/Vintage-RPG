#include "LoadExitsForSouthernForest.h"

void LoadExitsForSouthernForest::LoadExitsForSouthernForest(
    AreaMap *southernForest , AreaMap *northArea){

    //South exit.
    southernForest->loadExit(17 , 0 , northArea , 25 , 48);
}