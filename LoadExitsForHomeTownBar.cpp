#include "LoadExitsForHomeTownBar.h"

void LoadExitsForHomeTownBar::LoadExitsForHomeTownBar(
    AreaMap *homeTownBar , AreaMap *homeTown){

    homeTownBar->loadExit(3 , 7 , homeTown , 43 , 46);
    homeTownBar->loadExit(4 , 7 , homeTown , 44 , 46);
}