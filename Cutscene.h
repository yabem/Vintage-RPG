#pragma once
#include "Draw.h"
#include "TextBox.h"
#include "Map.h"
#include "GameManager.h"
#include <allegro5/allegro_font.h>

#include <iostream>


//class GameManager;
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

public:
    Intro();
    virtual ~Intro();
    virtual bool play(const int pressedKey);  

private:
    int fade;
    int r , g , b;  //Red, green, and blue values for fading.
    ALLEGRO_FONT *introFont;
};


//////////////////////////////////Instruct Class/////////////////////////////
class Instruct: public Cutscene{

public:
    Instruct();
    virtual ~Instruct();
    virtual bool play(const int pressedKey);

private:
    int fade;
    int r , g , b;  //Red, green, and blue values for fading.
    ALLEGRO_FONT *introFont;
    TextBox textBox;
};

//////////////////////////////////BattleTrans Class/////////////////////////////
class BattleTrans: public Cutscene{

public:
    BattleTrans();
    BattleTrans(AreaMap *background , AreaMap *currMap , Character *player);
    virtual ~BattleTrans();
    virtual bool play(const int pressedKey);

private:

    int mapSwitch;   //Determines which map to show. 
    AreaMap *currMap;   //Pointer to the current AreaMap that the player exists on.
    AreaMap *background;  //Pointer to the default background used for the transition.
    Character *thePlayer;   //Pointer to the player.
};

//////////////////////////////////BattleVictory Class/////////////////////////////
class BattleVictory: public Cutscene{

public:
    BattleVictory();
    BattleVictory(AreaMap *currMap , CharacterList *characterList);
    virtual ~BattleVictory();
    virtual bool play(const int pressedKey);

private:

    int mapSwitch;   //Determines which map to show. 
    AreaMap *currMap;   //Pointer to the current AreaMap that the player exists on.
    CharacterList *characterList;   //Pointer to the player.
    TextBox textBox;
};