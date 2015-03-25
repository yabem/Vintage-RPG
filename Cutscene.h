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
class Intro: public Cutscene{

private:
    int fade;
    int r , g , b;  //Red, green, and blue values for fading.
    ALLEGRO_FONT *introFont;

public:
    Intro();
    virtual ~Intro();
    virtual bool play(const int pressedKey);  
};


//////////////////////////////////Instruct Class/////////////////////////////
class Instruct: public Cutscene{

private:
    int fade;
    int r , g , b;  //Red, green, and blue values for fading.
    ALLEGRO_FONT *introFont;
    TextBox textBox;

public:
    Instruct();
    virtual ~Instruct();
    virtual bool play(const int pressedKey);
};

//////////////////////////////////BattleTrans Class/////////////////////////////
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

//////////////////////////////////BattleVictory Class/////////////////////////////
class BattleVictory: public Cutscene{

private:

    int mapSwitch;   //Determines which map to show. 
    AreaMap *currMap;   //Pointer to the current AreaMap that the player exists on.
    CharacterList *characterList;   //Pointer to the player.
    TextBox textBox;
    I_Manager *i_Manager;
    TreasureBox *treasureBox;

public:
    BattleVictory();
    BattleVictory(AreaMap *currMap , CharacterList *characterList ,
        I_Manager *i_Manager , TreasureBox *treasureBox);
    virtual ~BattleVictory();
    virtual bool play(const int pressedKey);
};