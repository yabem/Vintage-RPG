#pragma once
#include <time.h>
#include <vector>
#include <queue>
#include <allegro5/allegro_font.h>
#include "I_Animation.h"
#include "Movement.h"
#include "InitEnemies.h"
#include "CharFactory.h"
#include "CharacterList.h"
#include "I_Manager.h"
#include "DrawRepository.h"

const int RESET_TIMER = 2000;
const int BATTLE_TIMER = 100;   //Determines when a battle will take place.

class GameManager: public I_Manager{

private:

    ALLEGRO_FONT *introFont;
    DrawRepository *drawRepository;

    //Determines when the gameloop exits.
    bool endOfGameLoop; 

public:

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

    //The the x and y locations on the areamap.
    int charOnMapX , charOnMapY;  

    //Direction the character is facing on the areamap.
    int charOnMapFacing;    

    //Vector of pointers to enemy bitmaps.
    vector<ALLEGRO_BITMAP*> enemyModels;    

    //Constructor.
    GameManager();

    //Destructor.
    virtual ~GameManager();

    //Sets the endOfGameLoop to exit.
    virtual void setEndOfGameLoopToEnd();

    //Gets the value of endOfGameLoop.
    bool isEndOfGameLoop();

    //Updates the pressed key.
    void updateKey(int key);

    //Returns a pointer to the player at the front of the list.
    Character* getFrontPlayer();

    //Returns the charList.
    virtual CharacterList* getList();

    //Determines if the key is pressed.
    bool isKeyActive(int key);  

    //Makes a key inactive.
    void makeKeyInactive(int key);

    virtual void saveAreaMapVariables();

    //Increase the game timer by 1.
    void increaseGameTimer();  
    
    //Checks the status of the battle.
    bool isBattle();            
    
    //Switch variables bak to the player moving on the map.
    virtual void switchVariablesToMap();    
    
    //Reset game timer to 0.
    void resetGameTimer();      

    //Loads the DrawRepository
    void loadDrawRepository(DrawRepository *drawRepository);

    //Loads the list of players.
    void loadPlayers(CharacterList *characterList);  
    
    //Sets the current pressed key to unpressed.
    void resetPressedKey(); 

    //Returns the pressedKey
    virtual int getPressedKey() const;

    //Sets the pressedKey to inactive.
    virtual void setPressedKeyToInactive();
};