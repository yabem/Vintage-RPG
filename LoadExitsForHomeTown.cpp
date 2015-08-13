#include "LoadExitsForHomeTown.h"

void LoadExitsForHomeTown::LoadExitsForHomeTown(AreaMap *homeTown , 
        AreaMap *theShop , AreaMap *theArmory , AreaMap *theBar , 
        AreaMap *northArea , AreaMap *westArea ,
        AreaMap *eastArea , AreaMap *southArea ){

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
    homeTown->loadExit(28 , 10 , theShop , 3 , 6);
    homeTown->loadExit(29 , 10 , theShop , 4 , 6);

    //Armory exits.
    homeTown->loadExit(37 , 10 , theArmory , 3 , 6);
    homeTown->loadExit(38 , 10 , theArmory , 4 , 6);

    //Bar exits.
    homeTown->loadExit(43 , 44 , theBar , 3 , 6);
    homeTown->loadExit(44 , 44 , theBar , 4 , 6);
}