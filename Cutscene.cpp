#include "Cutscene.h"

/////////////////////////////////////Cutscene Class/////////////////////////////////////////////
//Default constructor.
Cutscene::Cutscene(){

    frameCount = 0;
}

Cutscene::~Cutscene(){

}

bool Cutscene::play(){

    return false;
}

bool Cutscene::play(const int pressedKey){

    return false;
}

/////////////////////////////////////Intro Class/////////////////////////////////////////////
//Default constructor.
Intro::Intro(){

    fade = 8;
    r = 0 , g = 0 , b = 0;
    frameCount = 0;
    introFont = al_load_font("arial.ttf" , 18 , 0);
}

//Destructor.
Intro::~Intro(){

}

//Plays the cutscene. Returns false if not done playing, returns true
//when done playing.
bool Intro::play(const int pressedKey){

    r += fade ; g += fade ; b += fade;
    frameCount++;
    al_draw_textf(introFont , al_map_rgb(255, 255, 255), 250, SCREEN_H / 2, 0, "Vintage RPG");

    if(frameCount % 30 == 0)
        fade *= -1;

    al_draw_textf(introFont , al_map_rgb(r , g , b), 213, SCREEN_H / 2 + 30 , 0, "Press Space to Begin");

    if(pressedKey == SPACE)
        return true;

    else return false;
}

/////////////////////////////////////Instruct Class/////////////////////////////////////////////

//Constructor.
Instruct::Instruct(){

   frameCount = 0;

   textBox.loadText("You awaken in a strange town that you have never seen before. "
       "You don't know where you are and why you are there. "
       "Your first task is to find some clues and figure out what happened. " 
       "Go forth and start your quest.");
}

//Destructor.
Instruct::~Instruct(){

}

//Plays the cutscene. Returns false if not done playing, returns true
//when done playing.
bool Instruct::play(const int pressedKey){

    textBox.draw();

    if(pressedKey == SPACE)
        return true;

    else return false;
}

/////////////////////////////////////BattleTrans Class/////////////////////////

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

/////////////////////////////////////BattleVictory Class///////////////////////

//Constructor.
BattleVictory::BattleVictory(){

    frameCount = 0;
}

//Constructor with parameters.
BattleVictory::BattleVictory(AreaMap *currMap , CharacterList *characterList ,
    I_Manager *i_Manager){

    frameCount = 0;
    mapSwitch = 1;
    this->currMap = currMap;
    this->characterList = characterList;
    this->i_Manager = i_Manager;

    textBox.loadText("You have slain all the enemies! "
    "You gained 10xp and 50gold.");
}

//Destructor.
BattleVictory::~BattleVictory(){

}

//Plays the battle victory. The cutscene switches back and forth
//between the current map and a white background.
bool BattleVictory::play(const int pressedKey){
    
    frameCount++;

    Draw::drawArea(*currMap);
    Draw::drawCharListForBattle(characterList);

    textBox.draw();

    if(pressedKey == SPACE){

        i_Manager->switchVariablesToMap();
        return true;
    }

    else return false;
}