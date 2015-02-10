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

class BattleManager{

private:
    
    enum turnTypes{NONE , PLAYER , ENEMY};
    
    //The enemies' or players' turn.
    int currentTarget;          
    Cursor *battleCursor;

    //List of menus.
    vector<Menu*> menus;      
    CharacterList theEnemies;

    //Factory for the enemies.
    CharFactory enemyFactory;   
    
    //Vector of pointers to enemy bitmaps.
    vector<ALLEGRO_BITMAP*> enemyModels;    
    
public:
    
    //Default constructor.
    BattleManager();

    //Destructor.
    ~BattleManager();

    //Switches the turnToAct to the specified type.
    void changeTarget(int currentTarget);

    //Loads a cursor.
    void loadCursor(Cursor *cursor);

    //Loads a menu.
    bool loadMenu(Menu *menu);

    //Loads all the input model.
    void loadEnemyModel(ALLEGRO_BITMAP *model);

    //Set menu draw location to character.
    void placeMenuToLeftOfCharacter(Character *character);

    //Draws cursor.
    void drawCursor() const;

    //Adjust cursor to target.
    void moveCursorToTarget(Character *character);

    //Changes currentTarget to enemies.
    void targetEnemies();

    //Returns the enemies list.
    std::vector<Character*> getEnemiesList();  

    //Changes currentTarget to Players.
    void targetPlayers();

    //Return current target.
    int getCurrentTarget();

    //Determines if the current target is the enemies.
    bool targettingEnemies();

    //Determines if the cursor menu should be moved.
    void checkForMenuCursorMovement(GameManager *gameManager);

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

    //Determines if there are still enemies remaining.
    bool enemiesRemaining();    

/////////////////////////////////////Enemy Creator/////////////////////////////
    
    //Determines if a battle will occur.
    bool checkForBattle(GameManager *gameManager);  

    //Generates the enemies for the battle.
    void generateEnemies(int maxNumberOfEnemies); 

};