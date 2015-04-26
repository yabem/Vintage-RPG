#include "BattleTrans.h"

//Constructor.
BattleTrans::BattleTrans(){

    frameCount = 0;
}

//Constructor with parameters.
BattleTrans::BattleTrans(AreaMap *background , AreaMap *currMap , 
    Character *thePlayer , I_Manager *i_MapManager, I_Manager *i_BattleManager){

    frameCount = 0;
    mapSwitch = 1;
    this->currMap = currMap;
    this->background = background;
    this->thePlayer = thePlayer;
    this->i_MapManager = i_MapManager;
    this->i_BattleManager = i_BattleManager;
}

//Destructor.
BattleTrans::~BattleTrans(){

}

//Plays the battle transition. The cutscene switches back and forth
//between the current map and a white background.
bool BattleTrans::play(const int pressedKey){

    //Lasts for 80 frames and switches between the current map and
    //the white background every 5 frames.
    if(frameCount < 80){
    
        frameCount++;

        if(frameCount % 5 == 0)
            mapSwitch *= -1;
                        
        if(mapSwitch == 1)
            Draw::drawArea(*currMap , *thePlayer);

        else Draw::drawArea(*background , *thePlayer); 

        return false;
    }

    else{

        i_MapManager->saveAreaMapVariables();
        i_BattleManager->generatePlayers(i_MapManager->getList() ,
            MAX_PLAYERS_PER_BATTLE);
        return true;
    }
}