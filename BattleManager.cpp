#include "BattleManager.h"

//Default constructor.
BattleManager::BattleManager(){

    currentTarget = NO_TARGET;
    battleCursor = NULL;
    gameManager = NULL;
    isBattlePaused = false;

    enemyTurnTimerList.loadManager(this);

    playerTurnTimerList.loadManager(this);
    playerTurnTimerList.loadList(&playerMenuList);
}

//Destructor.
BattleManager::~BattleManager(){

    //Default is fine.
}

//Switches the turnToAct to the specified type.
//Pre:  The turn is a valid option.
//Post: The turnToAct is changed to turn.
void BattleManager::changeTarget(int currentTarget){

    switch(currentTarget){

        case NO_TARGET:
            this->currentTarget = currentTarget;
            break;

        case PLAYER:
            this->currentTarget = currentTarget;
            break;

        case ENEMY:
            this->currentTarget = currentTarget;
            break;

        default:
            this->currentTarget = NO_TARGET;
            break;
    }
}

//Loads a cursor.
//Pre:  The cursor is a valid cursor.
//Post: Changes the battleCursor pointer to match cursor.
void BattleManager::loadCursor(Cursor *cursor){

    this->battleCursor = cursor;
}

//Load GameManager.
//Pre:  The gameManager is not NULL.
//Post: Sets the gameManager pointer.
void BattleManager::loadGameManager(GameManager *gameManager){

    this->gameManager = gameManager;
}

//Load CharacterManipulation.
void BattleManager::loadCharacterManipulationStore(CharacterManipulationStore 
    *characterManipulationStore){

        this->characterManipulationStore = characterManipulationStore;
}

//Loads a Menu to the BattleManager.
//Pre:  None.
//Post: Loads the menu to the Menu vector and pauses the battle.
void BattleManager::loadMenu(Menu *menu){

    //Error loading.
    if(menu == NULL)
        return;
    
    else{ 

        menus.push_back(menu);
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

    if(menus.empty())
        return;

    else menus.front()->setMenuToLeftOfCharacter(character);
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

//Changes currentTarget to players.
//Pre:  None.
//Post: Changes currentTarget to PLAYER.
void BattleManager::targetPlayers(){

    currentTarget = PLAYER;
}

//Changes currentTarget to no target.
//Pre:  None.
//Post: Changes currentTarget to NO_TARGET.
void BattleManager::setTargetToNoTarget(){

    currentTarget = NO_TARGET;
}

//Returns the enemies list.
//Pre:  None.
//Post: Returns the vector to the CharacterList.
std::vector<Character*> BattleManager::getEnemiesList(){

    return theEnemies.getList();
}

//Returns the players list.
//Pre:  None.
//Post: Returns the vector to the CharacterList.
std::vector<Character*> BattleManager::getPlayersList(){

    return thePlayers.getList();
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
//      If it is, then UP and DOWN navigate through the list
//      and LEFT and RIGHT check for subMenus. If a subMenu is found
//      then the subMenu is added to the menus vector that will be drawn.
void BattleManager::moveMenuCursor(){

    if(menus.empty())
        return;

    //Only move if the enemy or players aren't selected.
    if(currentTarget != NO_TARGET)
        return;

    int pressedKey = gameManager->getPressedKey();

    vector<Menu*>::iterator menuIter = menus.begin();

    //Set iterator to the last element.
    menuIter = menus.end() - 1;

    //Move the selector on the highest menu.
    if(pressedKey == UP || pressedKey == DOWN){
        (*menuIter)->moveSelection(pressedKey);
        gameManager->resetPressedKey();
    }

    //Check if a Menu needs to be removed. Does not remove the last Menu.
    else if(pressedKey == LEFT && menus.size() > 1){

        //Resets key to ensure only one Menu is removed.
        if(pressedKey != NO_KEY)
            gameManager->updateKey(pressedKey);
        
        pressedKey = NO_KEY;

        //Resets the menu selection to the beginning of the list
        //then removes it from the vector.
        Draw::moveMenuSelectionToBegin(menus);
        menus.pop_back();
        gameManager->resetPressedKey();
    }   

    else if(pressedKey == RIGHT && (*menuIter)->currSelectionHasSubMenu()){

        Menu *menuPtr = (*menuIter);
        Menu *subMenuPtr = (*menuIter)->getSelectionsSubMenu(); 
        
        subMenuPtr->setDrawToPrevSelection(menuPtr);
        loadMenu(subMenuPtr);
        gameManager->resetPressedKey();
    }
} 

//Determines if the enemy cursor selector should be moved.
//Pre:  None.
//Post: Checks if the player is navigating through the enemy list.
//      If the player is, then UP and DOWN navigating through the list.
void BattleManager::moveEnemyCursor(){

    if(menus.empty())
        return;

    //Only move if the enemy or players aren't selected.
    if(currentTarget == ENEMY){
    
        switch (gameManager->getPressedKey()){

            case UP:
                moveEnemySelectionUp();  
                break;

            case DOWN:
                moveEnemySelectionDown();
                break;

            default:
                //Do nothing.
                break;
        }
    }
}

//Consume keyboard input from player for the battle.
//Pre:  The key input is within the range of the keyboard vector.
//Post: If the player has the menu selected, the key is consumed by the
//      menu operations. If the player has targetted the enemies, then
//      the key is consumed by the menu enemy movement operations.
void BattleManager::consumePlayerInput(){

    switch(gameManager->getPressedKey()){

        case UP:

            moveEnemyCursor();
            moveMenuCursor();
            moveCursorToTarget(getCurrEnemy());
            break;

        case DOWN:

            moveEnemyCursor();
            moveMenuCursor();
            moveCursorToTarget(getCurrEnemy());               
            break;

        case RIGHT:

            moveMenuCursor();
            break;

        case LEFT:

            moveMenuCursor();
            break;

        case SPACE:

            //Not players turn.
            if(menus.empty())  
                break;

            //Players turn.
            else{   

                //Execution selection.
                std::string selection = menus.back()->getCurrSelectionName(); 

                //Invalid selection, disregard input.
                if(!characterManipulationStore->isValidManipulation(selection))
                    break;

                else if(targettingEnemies()){

                    //Execute selection.
                    characterManipulationStore->executeManipulation(
                        thePlayers.getCurrSelection() , getCurrEnemy() ,
                        selection);
                    
                    targetPlayers();
                    Draw::removeAllMenus(getMenuList());
                    setTargetToNoTarget();
                }
    
                //Sets target to enemies.
                else{   
                    
                    targetEnemies();
                    moveCursorToTarget(getCurrEnemy());
                    
                }
            }

            break;
    }

    gameManager->setPressedKeyToInactive();
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

//Sets the current player to the position.
//Pre:  None.
//Post: Iterates through the list until it reaches the position.
//      Sets the current target of the CharacterList to that Character.
void BattleManager::setCurrPlayer(int position){

    if(position > thePlayers.getSize())
        return;

    thePlayers.resetSelection();

    for(int i = 0 ; i < position ; i++){

        thePlayers.moveSelectionDown();
    }
}

//Gets the currently selected enemy.
//Pre:  None.
//Post: Returns a pointer to the current enemy.
Character* BattleManager::getCurrPlayer(){

    return thePlayers.getCurrSelection();
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

//Delete's the current enemy if it is dead.
//Pre:  None.
//Post: Checks if the currentSelected enemy is dead. If
//      dead, the enemy is deleted and returns true. If
//      not dead, the enemy is not deleted and returns false.
bool BattleManager::deleteCurrEnemyIfDead(){

    //Check if enemy is dead.
    if(currEnemyDead()){
        deleteCurrEnemy();
        return true;
    }

    else return false;
}

//Determines if there are still enemies remaining.
//Pre:  None.
//Post: Returns TRUE if there is an Character still in
//      theEnemies list. Returns FALSE of the list is empty.
bool BattleManager::enemiesRemaining(){

    return !theEnemies.isEmpty();
}

//Update turnTimers.
//Pre:  None.
//Post: Updates all the turnTimers if the battle is not paused. 
//      If the turnTimers are full then the turnTimers are reset.
void BattleManager::updateTurnTimers(){

    if(!isBattlePaused){

        enemyTurnTimerList.updateTurnTimers();
        playerTurnTimerList.updateTurnTimers();
    }

    enemyTurnTimerList.drawTurnTimers();
    playerTurnTimerList.drawTurnTimers();
}

/////////////////////////////////////Enemy Creator/////////////////////////////

//Determines if a battle will occur.
bool BattleManager::checkForBattle(){

    if(gameManager->gameTimer == BATTLE_TIMER && gameManager->battle == false){

        //Set battle flags to true.
        gameManager->battle = true;

        //Load battle transition cutscene.
        BattleTrans *theBattle = new BattleTrans(gameManager->cutSceneMap ,
            gameManager->currMap , gameManager->player , gameManager , this);
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

    //Adds the turnTimers to the enemies.
    theEnemies.loadList(&enemyTurnTimerList);
    SetTurnTimerListToCharacterList::setTurnTimerListToCharacterList(
        &theEnemies , &enemyTurnTimerList);
}

//Generates the players for the battle.
void BattleManager::generatePlayers(CharacterList *characterList , 
    int maxNumberPlayers){

    characterList->resetSelection();

    for(int i = 0 ; i < maxNumberPlayers ; i++){

        //Character *insertChar = new Character;
        //Character temp = characterList->getCurrSelection();
        //*insertChar = *characterList->getCurrSelection();
        //thePlayers.loadChar(insertChar);
        thePlayers.loadChar(characterList->getCurrSelection());
        characterList->moveSelectionDown();
    }

    //Set spacing.
    InitPlayers::initPlayersSpacing(thePlayers.getList());

    //Reset iterator to the beginning.
    thePlayers.resetSelection();

    //Adds the turnTimers to the players.
    thePlayers.loadList(&playerTurnTimerList);
    SetTurnTimerListToCharacterList::setTurnTimerListToCharacterList(
        &thePlayers , &playerTurnTimerList);

    //Adds menuList to the players.
    thePlayers.loadList(&playerMenuList);
    SetMenuListToCharacterList::setMenuListToCharacterList(
        &thePlayers , &playerMenuList);
}

//Returns the charList.
//Pre:  None.
//Post: Returns a pointer to the players CharacterList.
CharacterList* BattleManager::getList(){

    return &thePlayers;
}

/////////////////////////////////////Battle End////////////////////////////////

//End of the battle, players won.
//Pre:  None.
//Post: Cleans up after the battle and ensures all memory is reclaimed.
void BattleManager::playersVictory(){

    //Create victory cutscene.
    gameManager->generateVictoryCutScene();

    //Reset battle menus.
    Draw::removeAllSubMenus(getMenuList());

    //Draw final battle frame.
    Draw::drawArea(*gameManager->currMap , *gameManager->player);

    //Switch to map variables.
    //gameManager->switchVariablesToMap();

    theEnemies.deleteList();
    thePlayers.deleteList();
}

//Pause battle so timers don't increase.
void BattleManager::pauseBattle(){

    isBattlePaused = true;
}

//Unpause battle so timers start increasing.
void BattleManager::unPauseBattle(){

    isBattlePaused = false;
}

//Determines if the battle is active.
//Pre:  None.
//Post: Returns isBattlePaused.
bool BattleManager::battlePaused(){

    return isBattlePaused;
}