#pragma once
#include <time.h>
#include <vector>
#include <queue>
#include "Cutscene.h"
#include <allegro5/allegro_font.h>
#include "Animation.h"
#include "Movement.h"
#include "InitEnemies.h"
#include "CharFactory.h"
#include "Menu.h"
#include "CharacterList.h"

class Cutscene;
class Menu;

const int MAX_NUM_KEYS = 6;
const int RESET_TIMER = 2000;
const int BATTLE_TIMER = 100;   //Determines when a battle will take place.

class GameManager{

private:

    queue<Cutscene*> cutscenes;
    vector<Menu*> menus;
    CharacterList theEnemies;
    ALLEGRO_FONT *introFont;

public:

    int menuChoice;
    AreaMap *prevMap;       //Previous AreaMap.
    AreaMap *currMap;       //Current AreaMap.
    AreaMap *battleMap;     //Battle AreaMap.
    AreaMap *cutSceneMap;   //Cutscene AreaMap used for battle transitions.
    Character *player;      //The player.
    int numEnemies;
    vector<bool> keys;

    //Timer that counts up as the game progresses each frame.
    int gameTimer;          
    int pressedKey;

    GameManager();
    bool loadCutscene(Cutscene *cutscene);
    bool loadMenu(Menu *menu);
    void playCutscenes();
    void updateKey(int key);
    bool battle;        //Flag for if a battle is happening.
    bool firstTime;     //Flag for first time through the battle to save the variables.
    
    //The the x and y locations on the areamap.
    int charOnMapX , charOnMapY;  

    //Direction the character is facing on the areamap.
    int charOnMapFacing;  

    //Factory for the enemies.
    CharFactory enemyFactory;     

    //Vector of pointers to enemy bitmaps.
    vector<ALLEGRO_BITMAP*> enemyModels;    

    void saveAreaMapVariables();

    void initializeBattle();

    //Increase the game timer by 1.
    void increaseGameTimer();  
    
    //Checks the status of the battle.
    bool isBattle();            
    
    //Switch variables bak to the player moving on the map.
    void switchVariablesToMap();    
    
    //Reset game timer to 0.
    void resetGameTimer();      

    //Loads all the input model.
    void loadEnemyModel(ALLEGRO_BITMAP *model);  
    
    //Sets the current pressed key to unpressed.
    void resetPressedKey(); 
    
    //Creates the victory CutScene.
    void generateVictoryCutScene(); 

    //Determines if there are remaining cutscenes.
    bool cutscenesEmpty() const;      

    //Returns the pressedKey
    int getPressedKey() const;

    //Update key to unpressed.
    void updateKeyToUnpressed(int theKey);
};