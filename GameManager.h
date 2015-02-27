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

const int RESET_TIMER = 2000;
const int BATTLE_TIMER = 100;   //Determines when a battle will take place.

class GameManager{

private:

    queue<Cutscene*> cutscenes;
    queue<Animation*> animations;   //Stores the animations to be played.
    vector<Menu*> menus;
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

    CharacterList *thePlayers;

    //Timer that counts up as the game progresses each frame.
    int gameTimer;          
    int pressedKey;

    //Flag for if a battle is happening.
    bool battle;   

    //Flag for first time through the battle to save the variables.
    bool firstTime;     
    
    //The the x and y locations on the areamap.
    int charOnMapX , charOnMapY;  

    //Direction the character is facing on the areamap.
    int charOnMapFacing;    

    //Vector of pointers to enemy bitmaps.
    vector<ALLEGRO_BITMAP*> enemyModels;    

    GameManager();
    //x
    bool loadCutscene(Cutscene *cutscene);
    bool loadMenu(Menu *menu);

    //x
    void playCutscenes();
    void updateKey(int key);

    //Returns a pointer to the player at the front of the list.
    Character* getFrontPlayer();

    //Determines if the key is pressed.
    bool isKeyActive(int key);  

    //Makes a key inactive.
    void makeKeyInactive(int key);

    void saveAreaMapVariables();

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

    //Loads the list of players.
    void loadPlayers(CharacterList *characterList);  
    
    //Sets the current pressed key to unpressed.
    void resetPressedKey(); 
    
    //Creates the victory CutScene.
    void generateVictoryCutScene(); 

    //Determines if there are remaining cutscenes.
    bool cutscenesEmpty() const;      

    //Returns the pressedKey
    int getPressedKey() const;

    //Sets the pressedKey to inactive.
    void setPressedKeyToInactive();
};