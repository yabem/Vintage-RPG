#include "LoadExitsForWesternDesert.h"

void LoadExitsForWesternDesert::LoadExitsForWesternDesert(
    AreaMap *westernDesert , AreaMap *eastArea){

    //South exit.
    westernDesert->loadExit(49 , 7 , eastArea , 2 , 25);
}