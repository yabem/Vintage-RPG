#include "BattleManager.h"

//Default constructor.
BattleManager::BattleManager(){

    currentTarget = NONE;
    battleCursor = NULL;
}

//Destructor.
BattleManager::~BattleManager(){

    //Default is fine.
}

//Switches the turnToAct to the specified type.
//Pre:  The turn is a valid option.
//Post: The turnToAct is changed to turn.
void BattleManager::changeTarget(int currentTarget){

    this->currentTarget = currentTarget;
}

//Loads a cursor.
//Pre:  The cursor is a valid cursor.
//Post: Changes the battleCursor pointer to match cursor.
void BattleManager::loadCursor(Cursor *cursor){

    this->battleCursor = cursor;
}

//Loads a Menu to the BattleManager.
//Pre:  None.
//Post: Returns false if the Menu is NULL.
//      Returns true if a Menu was added to the vector.
bool BattleManager::loadMenu(Menu *menu){

    //Error loading.
    if(menu == NULL)
        return false;
    
    else{ 
        menus.push_back(menu);
        return true;
    }
}

//Loads all the input model.
//Pre:  The model is not NULL.
//Post: Loads the model into the enemyModel vector.
void BattleManager::loadEnemyModel(ALLEGRO_BITMAP *model){

    enemyModels.push_back(model);
}

//Set menu draw location to character.
//Pre:  None.
//Post: Sets the draw location of the left of the character
//      location. The right side of the menu will meet the 
//      left side of the character.
void BattleManager::placeMenuToLeftOfCharacter(Character *character){

    menus.front()->setMenuToLeftOfCharacter(character);
}

//Draws cursor.
//Pre:  None.
//Post: The battleCursor  is drawn to the screen if it is the
//      enemies' turn.
void BattleManager::drawCursor() const{

   if(currentTarget == ENEMY)
        battleCursor->draw();
}

//Adjust cursor to target.
//Pre:  The Character* is not NULL and all the x and y coordinates
//      are defined.
//Post: Updates the battleCursor to point to the middle of the Character.
//      If the cursor is pointing to the LEFT then the cursor will be moved
//      to the right side of the Character. If the cursor is pointing to the
//      RIGHT the cursor will be moved to the left side of the Character.
void BattleManager::moveCursorToTarget(Character *character){

    //Midpoint of Character.
    int charX = 0;
    int charMidY = 0;

    switch(battleCursor->getPointingDirection()){

        //Sets to the middle of the left side of the Character.
        case RIGHT:
            charX = character->getX();

            charMidY = character->getUpperLeftY() 
                        + (character->getH()
                        / 2 );
            break;

        //Sets to the middle of the right side of the Character.
        case LEFT:
            charX = character->getX() +
                        character->getW();

            charMidY = character->getY() 
                        + (character->getH()
                        / 2);
            break;

        default:
            break;
    }

    //Moves the battleCursor to the Character.
    battleCursor->move(charX , charMidY);   
}

//Changes currentTarget to enemies.
//Pre:  None.
//Post: Changes currentTarget to ENEMY.
void BattleManager::targetEnemies(){

    currentTarget = ENEMY;
}

//Returns the enemies list.
//Pre:  None.
//Post: Returns the vector to the CharacterList.
std::vector<Character*> BattleManager::getEnemiesList(){

    return theEnemies.getList();
}

//Changes currentTarget to players.
//Pre:  None.
//Post: Changes currentTarget to PLAYER.
void BattleManager::targetPlayers(){

    currentTarget = PLAYER;
}

//Get current target.
//Pre:  None.
//Post: Returns the int value of currentTarget.
int BattleManager::getCurrentTarget(){

    return currentTarget;
}

//Determines if the current target is the enemies.
//Pre:  None.
//Post: Returns TRUE if the currentTarget is ENEMY.
//      Returns FALSE otherwise.
bool BattleManager::targettingEnemies(){

    if(currentTarget == ENEMY)
        return true;

    else return false;
}

//Determines if the cursor menu should be moved.
//Pre:  None.
//Post: Checks if the player is navigating through the menu.
//      If it is, then UP and DOWN navigating through the list
//      and LEFT and RIGHT check for subMenus. If a subMenu is found
//      then the subMenu is added to the menus vector that will be drawn.
void BattleManager::checkForMenuCursorMovement(GameManager *gameManager){

    if(menus.empty())
        return;

    int pressedKey = gameManager->getPressedKey();

    vector<Menu*>::iterator menuIter = menus.begin();

    //Set iterator to the last element.
    menuIter = menus.end() - 1;

    //Move the selector on the highest menu.
    (*menuIter)->moveSelection(pressedKey);

    //Check if a Menu needs to be removed. Does not remove
    //the last Menu.
    if(pressedKey == LEFT && menus.size() > 1){

        //Resets key to ensure only one Menu is removed.
        if(pressedKey != -1)
            gameManager->updateKey(pressedKey);
        
        pressedKey = -1;

        //Resets the menu selection to the beginning of the list
        //then removes it from the vector.
        Draw::moveMenuSelectionToBegin(menus);
        menus.pop_back();
    }   

    else if(pressedKey == RIGHT && (*menuIter)->currSelectionHasSubMenu()){

        Menu *menuPtr = (*menuIter);
        Menu *subMenuPtr = (*menuIter)->getSelectionsSubMenu(); 
        
        subMenuPtr->setDrawToPrevSelection(menuPtr);
        loadMenu(subMenuPtr);
    }

    gameManager->resetPressedKey();
} 

//Returns the list of Menu pointers.
//Pre:  None.
//Post: Returns a reference to the menus vector.
std::vector<Menu*>& BattleManager::getMenuList(){

    return menus;
}

//Moves the currently selected enemy down.
//Pre:  None.
//Post: Moves the currently selected enemy down unless it is
//      already at the bottom.
void BattleManager::moveEnemySelectionDown(){

    theEnemies.moveSelectionDown();
}

//Moves the currently selected enemy up.
//Pre:  None.
//Post: Moves the currently selected enemy up unless it is
//      already at the top.
void BattleManager::moveEnemySelectionUp(){

    theEnemies.moveSelectionUp();
}

//Gets the currently selected enemy.
//Pre:  None.
//Post: Returns a pointer to the current enemy.
Character* BattleManager::getCurrEnemy(){

    return theEnemies.getCurrSelection();
}

//Returns whether or not the currently selected enemy is dead.
//Pre:  None.
//Post: Returns TRUE if the current selection has 0 HP. Returns
//      FALSE otherwise.
bool BattleManager::currEnemyDead(){

    return theEnemies.currSelectionIsDead();
}

//Deletes the currently selected enemy.
//Pre:  None.
//Post: Deletes the currently selected enemy.
void BattleManager::deleteCurrEnemy(){

    theEnemies.deleteCurrSelectedCharacter();
}

//Determines if there are still enemies remaining.
//Pre:  None.
//Post: Returns TRUE if there is an Character still in
//      theEnemies list. Returns FALSE of the list is empty.
bool BattleManager::enemiesRemaining(){

    return !theEnemies.isEmpty();
}

/////////////////////////////////////Enemy Creator/////////////////////////////

//Determines if a battle will occur.
bool BattleManager::checkForBattle(GameManager *gameManager){

    if(gameManager->gameTimer == BATTLE_TIMER && gameManager->battle == false){

        //Set battle flags to true.
        gameManager->battle = true;
        gameManager->firstTime = true;

        //Load battle transition cutscene.
        BattleTrans *theBattle = new BattleTrans(gameManager->cutSceneMap ,
            gameManager->currMap , gameManager->player);
        gameManager->loadCutscene(theBattle);

        //Create the enemies for the battle.
        generateEnemies(MAX_ENEMIES_PER_BATTLE);

        return true;
    }

    else return false;
}

//Generates the enemies for the battle.
void BattleManager::generateEnemies(int maxNumberOfEnemies){

    //Choose a random number of enemies.
    int numEnemies = rand() % maxNumberOfEnemies + 1;
    int randomEnemyType = 0;

    for(int i = 0 ; i < numEnemies ; i++){

        //Choose a random enemy.
        randomEnemyType = rand() % MAX_ENEMIES;

        //Get the enemy's level.
        int randomEnemyLevel = rand() % MAX_ENEMY_LEVEL + 1;      

        //Create and add the enemy to the battle.
        Character *addEnemy = enemyFactory.createChar(randomEnemyType);
        InitEnemies::init(addEnemy , randomEnemyType , randomEnemyLevel , enemyModels);
        theEnemies.loadChar(addEnemy);
    }

    //Set spacing.
    InitEnemies::initEnemiesSpacing(theEnemies.getList());

    //Reset iterator to the beginning.
    theEnemies.resetSelection();
}