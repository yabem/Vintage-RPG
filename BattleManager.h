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
#include "GameConfig.h"
#include "CharacterManipulationStore.h"
#include "CharacterList.h"
#include "TurnTimerList.h"
#include "FloatingTextList.h"
#include "SetTurnTimerListToCharacterList.h"
#include "SetMenuListToCharacterList.h"
#include "SetFloatingTextListToCharacterList.h"
#include "InitPlayers.h"
#include "I_Manager.h"
#include "MenuList.h"
#include "I_Event.h"
#include "BattleLoss.h"
#include "BattleVictory.h"
#include "BattleTrans.h"
#include "TreasureBox.h"
#include "FontStore.h"
#include "LevelUpCalculations.h"
#include "HealingActions.h"

class DrawRepository;

//Turn random battles off
#define NO_RANDOM_BATTLES

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

    //List of FloatingTexts for thePlayers.
    FloatingTextList playerFloatingTextList;

    //List of Menus for thePlayers.
    MenuList playerMenuList;
    
    //Vector of pointers to enemy bitmaps.
    vector<ALLEGRO_BITMAP*> enemyModels;    

    //Used to generate actions between Characters.
    CharacterManipulationStore *characterManipulationStore;

    //Used to get the current player.
    GameManager *gameManager;

    //Used for obtaining fonts for text.
    FontStore *fontStore;

    //Holds the treasure.
    TreasureBox treasureBox;

    //Determines if the battle is paused.
    bool isBattlePaused;

    //Holds the player's inventory.
    Backpack *backpack;

    //Initiator of an action.
    Character *initiator;

    //Target of the action.
    Character *receiver;

    //List of defeated enemies.
    std::vector<std::string> listOfDefeatedEnemies;

    //Movement counter for battle calculation.
    int movedSpaces;

    //Running length of the battle.
    float runningBattleTime;

    //Initiates the generated enemies for the battle.
    void generateEnemiesHelper();

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

    //Loads the FontStore.
    void loadFontStore(FontStore *fontStore);

    //Set fontStore for FloatingTextList.
    void setFontStoreForFloatingTextList();

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

    //Moves the target cursor.
    void moveTargetCursor();

    //Consume keyboard input from player for the battle.
    void consumePlayerInput();

    //Returns the list of Menu pointers.
    std::vector<Menu*>& getMenuList();   

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

    //Returns whether or not the currently selected player is dead.
    bool currPlayerDead();   

    //Deletes the currently selected enemy.
    virtual void deleteCurrEnemy(); 

    //Determines if there are still enemies remaining.
    bool enemiesRemaining();    

    //Updates and draws the turnTimers.
    void updateAndDrawTurnTimers();

    //Updates the FloatingTexts.
    virtual void updateFloatingTexts();
    
    //Draws the FloatingTexts.
    virtual void drawFloatingTexts();

    //Returns the charList.
    virtual CharacterList* getList();

    //Removes all the events.
    void removeAllEvents();

    //Load backpack.
    virtual void loadBackpack(Backpack *backpack);

    //Get backpack.
    virtual Backpack* getBackpack();

    //Adds to the defeated enemy list.
    void addToDefeatedEnemyList(std::string defeatedEnemy);

/////////////////////////////////////Enemy Creator/////////////////////////////
    
    //Determines if a battle will occur.
    bool checkForBattle();  

    //Initializes the variables to the beginning of a new battle.
    void initializeBattle();

    void initializeBattle(std::vector<int> enemyList , 
        std::vector<int> enemyLevels);

    //Generates the enemies for the battle.
    virtual void generateRandomEnemies(int maxNumberOfEnemies); 

    //Generates random enemies based off of the list of enemies and min/max 
    //possible levels for the enemies.
    void generateRandomEnemies(std::vector<int> listOfEnemies ,
        int minEnemyLevel , int maxEnemyLevel);

    //Generates the enemies for the battle.
    virtual void generateEnemies(std::vector<int> enemiesToFight ,
        std::vector<int> enemyLevels); 

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
    virtual bool isEventsEmpty();

    //Determines if there are Menus left.
    bool emptyMenus();

    //Executes the events.
    bool playCurrEvent();

    //Running length of the battle.
    virtual void incrementBattleTime();

    //Recalculate fill rates on CharacterTimers.
    void recalculateFillRatesOnTimers();

    //Checks each Character's Augments to see if any have expired.
    void updateAugments();

    //Removes each Character's Augments.
    void removeAugments();
};