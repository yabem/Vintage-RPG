//Stores all the information about the battle including players,
//enemies, and variables.

#pragma once
#include "Cursor.h"
#include "Character.h"
#include <vector>
#include "Menu.h"
#include "Draw.h"
#include "GameManager.h"
#include "CharacterList.h"
#include "Enums.h"
#include "CharacterManipulationStore.h"
#include "TurnTimerList.h"
#include "SetTurnTimerListToCharacterList.h"
#include "InitPlayers.h"
#include "I_Manager.h"

class BattleManager: public I_Manager{

private:

    enum turnTypes{NO_TARGET , PLAYER , ENEMY};
    
    //The enemies' or players' turn.
    int currentTarget;          

    //Cursor for the enemies.
    Cursor *battleCursor;

    //List of menus.
    vector<Menu*> menus;     

    //List of players for the battle.
    CharacterList thePlayers;

    //List of enemies for the battle.
    CharacterList theEnemies;

    //List of TurnTimers for theEnemies.
    TurnTimerList enemyTurnTimerList;

    //List of TurnTimers for thePlayers.
    TurnTimerList playerTurnTimerList;

    //Factory for the enemies.
    CharFactory enemyFactory;   
    
    //Vector of pointers to enemy bitmaps.
    vector<ALLEGRO_BITMAP*> enemyModels;    

    //Used to generate actions between Characters.
    CharacterManipulationStore *characterManipulationStore;

    //Used to get the current player.
    GameManager *gameManager;

    //Determines if the battle is paused.
    bool isBattlePaused;
    
public:
    
    //Default constructor.
    BattleManager();

    //Destructor.
    virtual ~BattleManager();

    //Switches the turnToAct to the specified type.
    void changeTarget(int currentTarget);

    //Loads a cursor.
    void loadCursor(Cursor *cursor);

    //Loads a menu.
    void loadMenu(Menu *menu);

    //Loads all the input model.
    void loadEnemyModel(ALLEGRO_BITMAP *model);

    //Load GameManager.
    void loadGameManager(GameManager *gameManager);

    //Load CharacterManipulation.
    void loadCharacterManipulationStore(CharacterManipulationStore 
        *CharacterManipulationStore);

    //Set menu draw location to character.
    void placeMenuToLeftOfCharacter(Character *character);

    //Draws cursor.
    void drawCursor() const;

    //Adjust cursor to target.
    void moveCursorToTarget(Character *character);

    //Changes currentTarget to enemies.
    void targetEnemies();

    //Changes currentTarget to Players.
    void targetPlayers();

    //Changes currentTarget to no target.
    void setTargetToNoTarget();

    //Returns the enemies list.
    std::vector<Character*> getEnemiesList();  

    //Returns the plaers list.
    std::vector<Character*> getPlayersList();

    //Return current target.
    int getCurrentTarget();

    //Determines if the current target is the enemies.
    bool targettingEnemies();

    //Determines if the menu cursor should be moved.
    void moveMenuCursor();

    //Determines if the enemy cursor selector should be moved.
    void moveEnemyCursor();

    //Consume keyboard input from player for the battle.
    void consumePlayerInput();

    //Returns the list of Menu pointers.
    std::vector<Menu*>& getMenuList();   

    //Moves the currently selected enemy down.
    void moveEnemySelectionDown();  

    //Moves the currently selected enemy up.
    void moveEnemySelectionUp();  

    //Gets the currently selected enemy.
    Character* getCurrEnemy();   

    //Returns whether or not the currently selected enemy is dead.
    bool currEnemyDead();   

    //Deletes the currently selected enemy.
    void deleteCurrEnemy(); 

    //Delete's the current enemy if it is dead.
    bool deleteDeadCurrEnemy();

    //Determines if there are still enemies remaining.
    bool enemiesRemaining();    

    //Update turnTimers.
    void updateTurnTimers();

    //Returns the charList.
    virtual CharacterList* getList();

/////////////////////////////////////Enemy Creator/////////////////////////////
    
    //Determines if a battle will occur.
    bool checkForBattle();  

    //Generates the enemies for the battle.
    virtual void generateEnemies(int maxNumberOfEnemies); 

    //Generates the players for the battle.
    virtual void generatePlayers(CharacterList *characterList ,
        int maxNumberPlayers); 

//////////////////////////////////Battle Timing////////////////////////////////

    //End of the battle, players won.
    void playersVictory();

    //Pause battle so timers don't increase.
    void pauseBattle();

    //Unpause battle so timers start increasing.
    void unPauseBattle();
};