#pragma once
#include "Cutscene.h"
#include "Map.h"
#include <allegro5/allegro_font.h>
#include "I_Manager.h"
#include "GameConfig.h"
struct ALLEGRO_FONT;

class BattleTrans: public Cutscene{

private:

    int mapSwitch;   //Determines which map to show. 
    AreaMap *currMap;   //Pointer to the current AreaMap that the player exists on.
    AreaMap *background;  //Pointer to the default background used for the transition.
    Character *thePlayer;   //Pointer to the player.
    I_Manager *i_MapManager;    //Used for saving map variables.
    I_Manager *i_BattleManager; //Used for generating enemies.

public:
    BattleTrans();
    BattleTrans(AreaMap *background , AreaMap *currMap , Character *player ,
        I_Manager *i_MapManager, I_Manager *i_BattleManager);
    virtual ~BattleTrans();
    virtual bool play(const int pressedKey);
};