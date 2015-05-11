#include "LoadExitsForHomeTown.h"

void LoadExitsForHomeTown::LoadExitsForHomeTown(AreaMap *homeTown , 
        AreaMap *theShop , AreaMap *northArea , AreaMap *westArea ,
        AreaMap *eastArea , AreaMap *southArea){

    //West exit.
    homeTown->loadExit(0 , 24 , westArea , 48 , 7);
    homeTown->loadExit(0 , 25 , westArea , 48 , 7);
    
    //North exit.
    homeTown->loadExit(24 , 0 , northArea , 38 , 48);
    homeTown->loadExit(25 , 0 , northArea , 38 , 48);
    
    //East exit.
    homeTown->loadExit(49 , 24 , eastArea , 2 , 30);
    homeTown->loadExit(49 , 25 , eastArea , 2 , 30);
    
    //South exit.
    homeTown->loadExit(24 , 49 , southArea , 17 , 2);
    homeTown->loadExit(25 , 49 , southArea , 17 , 2);
    
    //Shop exits.
    homeTown->loadExit(29 , 10 , theShop , 4 , 5);
    homeTown->loadExit(28 , 10 , theShop , 4 , 5);
}