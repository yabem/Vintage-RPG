//Stores all the information about the battle including players,
//enemies, and variables.

#pragma once
#include <vector>
#include <queue>
#include "Cursor.h"
#include "Character.h"
#include "Menu.h"
#include "Draw.h"
#include "GameManager.h"
#include "CharacterList.h"
#include "GameConfig.h"
#include "CharacterManipulationStore.h"
#include "TurnTimerList.h"
#include "SetTurnTimerListToCharacterList.h"
#include "SetMenuListToCharacterList.h"
#include "InitPlayers.h"
#include "I_Manager.h"
#include "MenuList.h"
#include "I_Event.h"
#include "BattleLoss.h"
#include "TreasureBox.h"
class DrawRepository;

class BattleManager: public I_Manager{

private:

    enum turnTypes{NO_TARGET , PLAYER , ENEMY};
    
    //The enemies' or players' turn.
    int currentTarget;          

    //Cursor for the enemies.
    Cursor *battleCursor;

    //List of menus.
    vector<Menu*> menus;     

    //Queue of events.
    queue<I_Event*> events;
    
    //Passed through to TurnTimerLists.
    DrawRepository *drawRepository;

    //List of players for the battle.
    CharacterList thePlayers;

    //List of enemies for the battle.
    CharacterList theEnemies;

    //List of TurnTimers for theEnemies.
    TurnTimerList enemyTurnTimerList;

    //List of TurnTimers for thePlayers.
    TurnTimerList playerTurnTimerList;

    //List of Menus for thePlayers.
    MenuList playerMenuList;

    //Factory for the enemies.
    CharFactory enemyFactory;   
    
    //Vector of pointers to enemy bitmaps.
    vector<ALLEGRO_BITMAP*> enemyModels;    

    //Used to generate actions between Characters.
    CharacterManipulationStore *characterManipulationStore;

    //Used to get the current player.
    GameManager *gameManager;

    //Holds the treasure.
    TreasureBox treasureBox;

    //Determines if the battle is paused.
    bool isBattlePaused;

    //Holds the player's inventory.
    Backpack *backpack;
    
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

    //Load DrawRepository.
    void loadDrawRepository(DrawRepository *drawRepository);

    //Loads an Event.
    void loadEvent(I_Event *i_Event);

    //Loads a Reward to the TreasureBox.
    void loadReward(I_Reward *i_Reward);

    //Delivers all the rewards to the player.
    void distributeAllRewards();

    //Set menu draw location to character.
    void placeMenuToLeftOfCharacter(Character *character);

    //Adjust cursor to target.
    void moveCursorToTarget(Character *character);

    //Changes currentTarget to enemies.
    void targetEnemies();

    //Changes currentTarget to Players.
    void targetPlayers();

    //Changes currentTarget to no target.
    void setTargetToNoTarget();

    //Returns the enemies list.
    virtual CharacterList* getEnemiesList();

    //Returns the plaers list.
    virtual I_List* getPlayersList();

    //Retrieves a pointer to the DrawRepository.
    DrawRepository* getDrawRepository();

    //Retrieves a pointer to the CharacterManipulationStore.
    CharacterManipulationStore* getCharManipStore();

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

    //Sets the current enemy to the position.
    void setCurrEnemy(int position);

    //Gets the currently selected enemy.
    virtual Character* getCurrEnemy();   

    //Sets the current target to the position.
    void setCurrPlayer(int position);

    //Gets the currently selected player.
    virtual Character* getCurrPlayer();

    //Returns whether or not the currently selected enemy is dead.
    bool currEnemyDead();   

    //Deletes the currently selected enemy.
    virtual void deleteCurrEnemy(); 

    //Delete's the current enemy if it is dead.
    bool deleteCurrEnemyIfDead();

    //Determines if there are still enemies remaining.
    bool enemiesRemaining();    

    //Update turnTimers.
    void updateTurnTimers();

    //Returns the charList.
    virtual CharacterList* getList();

    //Removes all the events.
    void removeAllEvents();

    //Load backpack.
    virtual void loadBackpack(Backpack *backpack);

    //Get backpack.
    virtual Backpack* getBackpack();

/////////////////////////////////////Enemy Creator/////////////////////////////
    
    //Determines if a battle will occur.
    bool checkForBattle();  

    //Initializes the variables to the beginning of a new battle.
    void initializeBattle();

    //Generates the enemies for the battle.
    virtual void generateEnemies(int maxNumberOfEnemies); 

    //Generates the players for the battle.
    virtual void generatePlayers(CharacterList *characterList ,
        int maxNumberPlayers); 

//////////////////////////////////Battle Timing////////////////////////////////

    //Check for end of battle.
    bool isEndOfBattle();

    //End of the battle, players won.
    void playersVictory();

    //End of the battle, the enemies won.
    void enemiesVictory();

    //Pause battle so timers don't increase.
    void pauseBattle();

    //Unpause battle so timers start increasing.
    void unPauseBattle();

    //Determines if the battle is active.
    bool battlePaused();

    //Determines if there are Events left.
    bool emptyEvents();

    //Determines if there are Menus left.
    bool emptyMenus();

    //Executes the events.
    bool playCurrEvent();
};