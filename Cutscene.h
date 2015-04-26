#pragma once
#include "Draw.h"
#include "TextBox.h"
#include "Map.h"
#include <allegro5/allegro_font.h>
#include <iostream>
#include "I_Manager.h"
#include "GameConfig.h"
#include "TreasureBox.h"
struct ALLEGRO_FONT;

//////////////////////////////////Cutscene Class/////////////////////////////
class Cutscene{

public:
    Cutscene();
    virtual ~Cutscene();
    virtual bool play();
    virtual bool play(const int pressedKey); 

protected:

    int frameCount;
};


//////////////////////////////////Intro Class/////////////////////////////



//////////////////////////////////Instruct Class/////////////////////////////

//////////////////////////////////BattleTrans Class/////////////////////////////


//////////////////////////////////BattleVictory Class/////////////////////////////
