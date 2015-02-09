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

//class AreaMap;
class Cutscene;
class Menu;
//class CharFactory;
//struct ALLEGRO_FONT;

const int MAX_NUM_KEYS = 6;
const int RESET_TIMER = 2000;
const int BATTLE_TIMER = 100;   //Determines when a battle will take place.

class GameManager{

public:
    //Confirmed for use
    GameManager();
    bool loadCutscene(Cutscene *cutscene);
    bool loadMenu(Menu *menu);
    void drawMenus();

    //Set menu draw location to character.
    void placeMenuToLeftOfCharacter(Character *character);
    
    //Removes all the submenus objects from menus leaving the first
    //Menu in the vector.
    void removeAllSubMenus();

    void playCutscenes();
    void updateKey(int key);
    int gameTimer;          //Timer that counts up as the game progresses each frame.
    int pressedKey;

    CharFactory enemyFactory;     //Factory for the enemies.
    vector<ALLEGRO_BITMAP*> enemyModels;    //Vector of pointers to enemy bitmaps.

    //Not confirmed for use
    bool test;   //Used to set start location.
    bool battle;        //Flag for if a battle is happening.
    bool firstTime;     //Flag for first time through the battle to save the variables.
    bool cutscenebool;  //Flag for if there is a cutscene.
    int cutSwitch;      //Switches between map and white background
    bool intro;   //Flag for start screen.
    bool battleCutscene,    //Flag for if there is a cutscene during battle.
        battleVictory,      //Flag for if the battle was won.
        startingInstructions;   //Flag for the startingInstructions.
    int selectEnemy ,       //
        enemyChoice;
    
    int brow , bcol , charOnMapX , charOnMapY;  //The the x and y locations on the areamap.
    int charOnMapFacing;  //Direction the character is facing on the areamap.

    int cutsceneFrameCount , miniCount;
    int r , g , b , fade;
    int menuChoice;
    AreaMap *prevMap;       //Previous AreaMap.
    AreaMap *currMap;       //Current AreaMap.
    AreaMap *battleMap;     //Battle AreaMap.
    AreaMap *cutSceneMap;   //Cutscene AreaMap used for battle transitions.
    Character *player;      //The player.
    int numEnemies;

    vector<bool> keys;

    void saveAreaMapVariables();
    void initializeBattle();

    void increaseGameTimer();   //Increase the game timer by 1.
    bool isBattle();            //Checks the status of the battle.
    void switchVariablesToMap();    //Switch variables bak to the player moving on the map.
    void resetGameTimer();      //Reset game timer to 0.
    void generateEnemies(int maxNumberOfEnemies); //Generates the enemies for the battle.
    void loadEnemyModel(ALLEGRO_BITMAP *model);  //Loads all the input model.

    bool checkForBattle();  //Determines if a battle will occur.
    
    void resetPressedKey(); //Sets the current pressed key to unpressed.
    void generateVictoryCutScene(); //Creates the victory CutScene.

    std::string getMenuSelectionName();    //Get's the curr menu selection's name.
    bool enemiesRemaining();    //Determines if there are still enemies remaining.
    std::vector<Character*> getEnemiesList();   //Returns the enemies list.
    Character* getCurrEnemy();   //Gets the currently selected enemy.
    bool currEnemyDead();   //Returns whether or not the currently selected enemy is dead.
    void deleteCurrEnemy(); //Deletes the currently selected enemy.

    void moveEnemySelectionDown();  //Moves the currently selected enemy down.
    void moveEnemySelectionUp();  //Moves the currently selected enemy up.

    bool cutscenesEmpty() const;      //Determines if there are remaining cutscenes.

    //Determines if the cursor menu should be moved.
    void checkForMenuCursorMovement();

private:
    queue<Cutscene*> cutscenes;
    vector<Menu*> menus;
    CharacterList theEnemies;
    ALLEGRO_FONT *introFont;

    //Moves the menu selection to the beginning.
    void moveMenuSelectionToBegin();
};