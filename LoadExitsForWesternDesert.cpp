#include "LoadExitsForWesternDesert.h"

void LoadExitsForWesternDesert::LoadExitsForWesternDesert(
    AreaMap *westernDesert , AreaMap *eastArea){

    //West exit.
    westernDesert->loadExit(49 , 6 , eastArea , 2 , 25);
    westernDesert->loadExit(49 , 7 , eastArea , 2 , 25);
    westernDesert->loadExit(49 , 8 , eastArea , 2 , 25);
}