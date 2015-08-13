#include "BattleManager.h"

//Default constructor.
BattleManager::BattleManager(){

    currentTarget = NO_TARGET;
    battleCursor = NULL;
    gameManager = NULL;
    drawRepository = NULL;
    isBattlePaused = false;
    initiator = NULL;
    receiver = NULL;

    enemyTurnTimerList.loadManager(this);

    playerTurnTimerList.loadManager(this);
    playerTurnTimerList.loadList(&playerMenuList);

    movedSpaces = 0;
    runningBattleTime = 0;
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

//Load DrawRepository.
//Pre:  The DrawRepository is not NULL.
//Post: The DrawRepository pointer is loaded to the BattleManager.
void BattleManager::loadDrawRepository(DrawRepository *drawRepository){

    this->drawRepository = drawRepository;
}

//Loads an I_Event.
//Pre:  The I_Event is valid.
//Post: The I_Event is loaded to the back of the events queue.
void BattleManager::loadEvent(I_Event *i_Event){

    events.push(i_Event);
}

//Loads a Reward to the TreasureBox.
//Pre:  The Reward is valid.
//Post: The Reward is permanetly added to the TreasureBox.
void BattleManager::loadReward(I_Reward *i_Reward){

    treasureBox.addReward(i_Reward);
}

//Loads the FontStore.
void BattleManager::loadFontStore(FontStore *fontStore){

    this->fontStore = fontStore;
    setFontStoreForFloatingTextList();
}

//Set fontStore for FloatingTextList.
void BattleManager::setFontStoreForFloatingTextList(){

    playerFloatingTextList.loadFontStore(fontStore);
}

//Delivers all the rewards to the player.
//Pre:  None.
//Post: Delivers all the rewards and empty's the TreasureBox.
void BattleManager::distributeAllRewards(){

    treasureBox.deliverAllRewards();
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

    if(this->battleCursor == NULL)
        return;

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
    //drawRepository->loadCursor(battleCursor);
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
CharacterList* BattleManager::getEnemiesList(){

    return &theEnemies;
}

//Returns the players list.
//Pre:  None.
//Post: Returns the vector to the CharacterList.
I_List* BattleManager::getPlayersList(){

    return &thePlayers;
}

//Retrieves a pointer to the CharacterManipulationStore.
CharacterManipulationStore* BattleManager::getCharManipStore(){

    return characterManipulationStore;
}

//Retrieves a pointer to the DrawRepository.
DrawRepository* BattleManager::getDrawRepository(){

    return drawRepository;
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
    else if(pressedKey == C && menus.size() > 1){

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

    else if(pressedKey == SPACE && (*menuIter)->currSelectionHasSubMenu()){

        Menu *menuPtr = (*menuIter);
        Menu *subMenuPtr = (*menuIter)->getSelectionsSubMenu(); 
        
        subMenuPtr->setDrawToPrevSelection(menuPtr);
        loadMenu(subMenuPtr);
        gameManager->resetPressedKey();
    }
} 

//Moves the target cursor.
//Pre:  None.
//Post: Checks if the player is navigating through the enemy or player list.
//      If the player is, then UP and DOWN navigating through the list.
void BattleManager::moveTargetCursor(){

    if(menus.empty())
        return;

    //Only move if the enemy or players aren't selected.
    if(currentTarget == ENEMY){
    
        switch (gameManager->getPressedKey()){

            case UP:
                theEnemies.moveSelectionUp();
                receiver = this->getCurrEnemy();
                break;

            case DOWN:
                theEnemies.moveSelectionDown();
                receiver = this->getCurrEnemy();
                break;

            default:
                //Do nothing.
                break;
        }
    }

    else if(currentTarget == PLAYER){
    
        switch (gameManager->getPressedKey()){

            case UP:
                thePlayers.moveSelectionUp();
                receiver = this->getCurrPlayer();
                break;

            case DOWN:
                thePlayers.moveSelectionDown();
                receiver = this->getCurrPlayer();
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

            moveTargetCursor();
            moveMenuCursor();
            moveCursorToTarget(receiver);
            break;

        case DOWN:

            moveTargetCursor();
            moveMenuCursor();
            moveCursorToTarget(receiver);
            break;

        case RIGHT:

            moveMenuCursor();
            break;

        case LEFT:

            moveMenuCursor();
            break;

        //Undo target selection.
        case C:

            //Not players turn.
            if(menus.empty())
                break;

            else if(this->currentTarget == NO_TARGET){
                this->moveMenuCursor();
                break;
            }

            else{   

                drawRepository->removeTopCursor();
                battleCursor = NULL;
                setTargetToNoTarget();
                break;
            }

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
                    moveMenuCursor();

                else if(targettingEnemies() || this->currentTarget == PLAYER){

                    //Execute selection.
                    characterManipulationStore->executeManipulation(
                        initiator , receiver ,
                        selection);
                    
                    //Turn over, reset values.
                    targetPlayers();
                    Draw::removeAllMenus(getMenuList());
                    drawRepository->removeTopCursor();
                    setTargetToNoTarget();
                    this->initiator = NULL;
                    this->receiver = NULL;
                    this->battleCursor = NULL;
                }
    
                //Sets target to enemies.
                else{   
                    
                    this->initiator = this->getCurrPlayer();

                    //Healing item.
                    //if(selection == "Recover" || selection == "Potion"){
                    if(HealingActions::isHealingAction(selection)){
                    
                        this->receiver = this->getCurrPlayer();
                        this->currentTarget = PLAYER;
                    }

                    //Attack on enemy.
                    else{
                        this->receiver = this->getCurrEnemy();
                        this->currentTarget = ENEMY;
                    }
                    
                    this->battleCursor = new Cursor();
                    this->battleCursor->move(50 , 50);
                    this->battleCursor->reverseDirection();
                    drawRepository->loadCursor(this->battleCursor);
                    moveCursorToTarget(receiver);
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

//Sets the current enemy to the position.
//Pre:  None.
//Post: Iterates through the list until it reaches the position.
//      Sets the current target of the CharacterList to that Character.
void BattleManager::setCurrEnemy(int position){

    if(position > theEnemies.getSize())
        return;

    theEnemies.resetSelection();

    for(int i = 0 ; i < position ; i++)
        theEnemies.moveSelectionDown();
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

    for(int i = 0 ; i < position ; i++)
        thePlayers.moveSelectionDown();
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

//Returns whether or not the currently selected enemy is dead.
//Pre:  None.
//Post: Returns TRUE if the current selection has 0 HP. Returns
//      FALSE otherwise.
bool BattleManager::currPlayerDead(){

    return thePlayers.currSelectionIsDead();
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

//Update turnTimers.
//Pre:  None.
//Post: Updates all the turnTimers if the battle is not paused. 
//      If the turnTimers are full then the turnTimers are reset.
//      Always draws the turnTimers.
void BattleManager::updateAndDrawTurnTimers(){

    if(!isBattlePaused){
       playerTurnTimerList.updateTurnTimers(); 
    }

    if(!isBattlePaused){
        enemyTurnTimerList.updateTurnTimers();  
    }

    enemyTurnTimerList.drawTurnTimers();
    playerTurnTimerList.drawTurnTimers();
}

//Updates the FloatingTexts.
void BattleManager::updateFloatingTexts(){

    playerFloatingTextList.updateFloatingTexts();
}

//Draws the FloatingTexts to the screen
void BattleManager::drawFloatingTexts(){

    playerFloatingTextList.drawFloatingTexts();
}

/////////////////////////////////////Enemy Creator/////////////////////////////

//Determines if a battle will occur.
bool BattleManager::checkForBattle(){
    
    if(!gameManager->currMap->mapHasBattles()){
        
        return false;
    }

    else if(!gameManager->player->hasCollision()){

        movedSpaces += PLAYER_MOVE_RATE;
    }
    
    if(movedSpaces >= 32){

        if(rand() % 100 < 0){

            initializeBattle();
            movedSpaces = 0;
            return true;
        }

        movedSpaces = 0;
    }
    
    else return false;
}

//Initializes the variables to the beginning of a new battle.
//Pre:  None.
//Post: Sets the variables so that the battle will be like a new battle.
void BattleManager::initializeBattle(){

    //Set battle flags to true.
    gameManager->battle = true;

    //Set battleTime to 0.
    runningBattleTime = 0;

    //Sets battle to unpause.
    unPauseBattle();

    //Load battle transition cutscene.
    BattleTrans *theBattle = new BattleTrans(
        gameManager->cutSceneMap ,
        gameManager->currMap , 
        gameManager->player , 
        gameManager , this);
    
    drawRepository->loadCutscene(theBattle);

    //Create the enemies for the battle.
    generateRandomEnemies(
        gameManager->currMap->getListOfEnemies() ,
        gameManager->currMap->getMinEnemyLevel() , 
        gameManager->currMap->getMaxEnemyLevel()); 
}

//Initializes the variables to the beginning of a new battle.
//Pre:  None.
//Post: Sets the variables so that the battle will be like a new battle.
//      The inputs determine which enemies will populate the battle.
void BattleManager::initializeBattle(std::vector<int> enemyList , 
    std::vector<int> enemyLevels){

    //Set battle flags to true.
    gameManager->battle = true;

    //Sets battle to unpause.
    unPauseBattle();

    //Load battle transition cutscene.
    BattleTrans *theBattle = new BattleTrans(gameManager->cutSceneMap ,
        gameManager->currMap , gameManager->player , gameManager , this);
    drawRepository->loadCutscene(theBattle);

    //Create the enemies for the battle.
    generateEnemies(enemyList , enemyLevels);
}

//Generates the enemies for the battle.
void BattleManager::generateRandomEnemies(int maxNumberOfEnemies){

    //Choose a random number of enemies.
    int numEnemies = rand() % maxNumberOfEnemies + 1;
    int randomEnemyType = 0;

    for(int i = 0 ; i < numEnemies ; i++){

        //Choose a random enemy.
        randomEnemyType = rand() % MAX_ENEMIES;

        //Get the enemy's level.
        int randomEnemyLevel = rand() % MAX_ENEMY_LEVEL + 1;      

        //Create and add the enemy to the battle.
        Character *addEnemy = new Character();
        InitEnemies::init(addEnemy , randomEnemyType , randomEnemyLevel , enemyModels);
        theEnemies.loadChar(addEnemy);
    }

    //Sets the spacing of the enemies, resets the enemies iterator, and
    //adds the TurnTimers
    generateEnemiesHelper();
}

//Generates random enemies based off of the list of enemies and min/max 
//possible levels for the enemies.
//Pre:  The minEnemyLevel and maxEnemyLevel must both be above 0 and the 
//      minEnemyLevel must be lower than the maxEnemyLevel.
//Post: Generates a list of enemies that the player will fight.
void BattleManager::generateRandomEnemies(std::vector<int> listOfEnemies ,
    int minEnemyLevel , int maxEnemyLevel){

    //Choose a random number of enemies.
    int numEnemies = rand() % MAX_ENEMIES_PER_BATTLE + 1;
    int randomEnemyType = 0;

    for(int i = 0 ; i < numEnemies ; i++){

        //Choose a random enemy from the list.
        randomEnemyType = listOfEnemies[rand() % listOfEnemies.size()];

        //Get the enemy's level within the level range.
        int levelRange = maxEnemyLevel - minEnemyLevel;
        int randomEnemyLevel = rand() % levelRange + minEnemyLevel;      

        //Create and add the enemy to the battle.
        Character *addEnemy = new Character();
        InitEnemies::init(addEnemy , randomEnemyType , randomEnemyLevel , enemyModels);
        theEnemies.loadChar(addEnemy);
    }

    //Sets the spacing of the enemies, resets the enemies iterator, and
    //adds the TurnTimers
    generateEnemiesHelper();
}

//Generates the enemies for the battle.
void BattleManager::generateEnemies(std::vector<int> enemiesToFight ,
    std::vector<int> enemyLevels){

    std::vector<int>::iterator enemyIter;
    std::vector<int>::iterator enemyLevelsIter;

    for(enemyIter = enemiesToFight.begin() , enemyLevelsIter = enemyLevels.begin();
        enemyIter != enemiesToFight.end() && enemyLevelsIter != enemyLevels.end();
        enemyIter++ , enemyLevelsIter++){

        //Create and add the enemy to the battle.
        Character *addEnemy = new Character();
        InitEnemies::init(addEnemy , (*enemyIter) , (*enemyLevelsIter) , enemyModels);
        theEnemies.loadChar(addEnemy);
    }

    //Sets the spacing of the enemies, resets the enemies iterator, and
    //adds the TurnTimers
    generateEnemiesHelper();
}

//Initiates the generated enemies for the battle.
void BattleManager::generateEnemiesHelper(){

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

    for(int i = 0 ; i < maxNumberPlayers 
        && i < characterList->getSize() ; i++){

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
        &thePlayers , &playerMenuList , fontStore->getFont("default"));

    //Adds floatingTextList to the players.
    thePlayers.loadList(&playerFloatingTextList);
    SetFloatingTextListToCharacterList::SetFloatingTextListToCharacterList(
        &thePlayers , &playerFloatingTextList);
    playerFloatingTextList.updateFloatingTexts();
}

//Returns the charList.
//Pre:  None.
//Post: Returns a pointer to the players CharacterList.
CharacterList* BattleManager::getList(){

    return &thePlayers;
}

//Removes all the remaining events in the list.
//Pre:  None.
//Pro:  Cycles through the events queue and deletes all of the remaining
//      events.
void BattleManager::removeAllEvents(){

    while(!events.empty()){

      delete events.front();
        events.pop();
    }
}

//Load backpack.
void BattleManager::loadBackpack(Backpack *backpack){

    this->backpack = backpack;
}

//Get backpack.
Backpack* BattleManager::getBackpack(){

    return backpack;
}

//Adds to the defeated enemy list.
void BattleManager::addToDefeatedEnemyList(std::string defeatedEnemy){

    this->listOfDefeatedEnemies.push_back(defeatedEnemy);
}
/////////////////////////////////////Battle End////////////////////////////////

//Check for end of battle.
//Pre:  None.
//Post: Returns true if the players win or if the enemies win.
//      Returns false if the battle continues.
bool BattleManager::isEndOfBattle(){

    //If all the enemies are dead. End the battle.
    if(!enemiesRemaining()){

        playersVictory();
        return true;
    }

    int playersAlive = 0;

    //Count number of players still alive.
    for(int i = 0 ; i < thePlayers.getSize() ; i ++){

        if(!thePlayers.getCharacterSelection(i)->isDead())
            playersAlive++;
    }

    //If all the players are dead and the animations are done
    //the battle is over.
    if(playersAlive == 0 && drawRepository->animationsEmpty() 
        && this->events.size() == 0 ){

        enemiesVictory();
        return true;
    }

    //If at least one player is alive continue the battle.
    else return false;
}

//End of the battle, players won.
//Pre:  None.
//Post: Cleans up after the battle and ensures all memory is reclaimed.
void BattleManager::playersVictory(){

    treasureBox.deliverAllRewards();

    //Levels up all the characters if they meet the requirements.
    std::vector<std::string> levelUpSummary = 
        LevelUpCalculations::levelUpListOfCharacters( 
        &thePlayers , 
        gameManager->getStatsByLevelStore() ,
        drawRepository);

    //Update the quest log with the enemies that were killed in battle.
    gameManager->getPlayerEntity()->updateQuestLog(listOfDefeatedEnemies);
    listOfDefeatedEnemies.clear();

    //Create victory cutscene.
    BattleVictory *battleVictory = new BattleVictory(gameManager->currMap , 
        &thePlayers , gameManager , &treasureBox , fontStore->getFont("default") ,
        levelUpSummary);

    drawRepository->loadCutscene(battleVictory);

    //Reset battle menus.
    Draw::removeAllMenus(getMenuList());

    //Draw final battle frame.
    Draw::drawArea(*gameManager->currMap);
    Draw::drawList(&thePlayers);
    Draw::drawList(&theEnemies);

    removeAllEvents();
    removeAugments();

    theEnemies.deleteList();
    thePlayers.deleteList();

    gameManager->resetPressedKey();

}

//End of the battle, enemies won.
//Pre:  None.
//Post: Cleans up after the battle and ensures all memory is reclaimed.
void BattleManager::enemiesVictory(){

    //Create loss cutscene.
    BattleLoss *battleLoss = new BattleLoss(gameManager->currMap , 
        &thePlayers , &theEnemies , gameManager , fontStore->getFont("default"));

    drawRepository->loadCutscene(battleLoss);

    //Reset battle menus.
    Draw::removeAllMenus(getMenuList());

    //Draw final battle frame.
    Draw::drawArea(*gameManager->currMap , *gameManager->player);

    removeAugments();
    removeAllEvents();

    listOfDefeatedEnemies.clear();

    theEnemies.deleteList();
    thePlayers.deleteList();

    treasureBox.removeAllRewards();
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

//Determines if there are Events.
//Pre:  None.
//Post: Returns true if there are no events left.
//      Returns false if there are events left..
bool BattleManager::isEventsEmpty(){

    return events.empty();
}

//Determines if there are Menus left.
//Pre:  None.
//Post: Returns true if there are no Menus in the menus vector.
//      Returns fase if there are Menus remaining.
bool BattleManager::emptyMenus(){

    return menus.empty();
}

//Plays all the I_Events in the I_Events queue.
//Pre:  None.
//Post: The I_Event at the front of the queue is played.
//      Returns true if there are more events left to play.
//      Returns false if there are no longer Events to play.
bool BattleManager::playCurrEvent(){

    //Only play an event when the events queue is full and when
    //no other events are playing.
    if(events.empty() || !drawRepository->animationsEmpty())
        return false;

    else{
        
        //Pop off the event if it is complete.
        if(events.front()->execute()){
            delete events.front();
            events.pop();
        }
        
        return true;
    }
}

//Running length of the battle.
//Pre:  None.
//Post: Adds the amount of one frame to runningBattleTime by 
//      the equivalent of 1 frame.
void BattleManager::incrementBattleTime(){

    runningBattleTime += Conversion::getBattleTimeIncrement();
}

//Recalculate fill rates on CharacterTimers.
//Pre:  None.
//Post: Updates each of the CharacterTimers with the current speed.
void BattleManager::recalculateFillRatesOnTimers(){

    playerTurnTimerList.recalculateAllFillRates();
    enemyTurnTimerList.recalculateAllFillRates();
}

//Updates each Character's Augments.
//Pre:  None.
//Post: Cycles through the augments for each character and updates the
//      augments.
void BattleManager::updateAugments(){

    //Update players
    thePlayers.resetSelection();

    for(int i = 0 ; i < thePlayers.getSize() ; i++){

        thePlayers.getCurrSelection()->getStats()->updateAugments();
        thePlayers.moveSelectionDown();
    }

    thePlayers.resetSelection();

    //Update enemies.
    theEnemies.resetSelection();

    for(int i = 0 ; i < theEnemies.getSize() ; i++){

        theEnemies.getCurrSelection()->getStats()->updateAugments();
        theEnemies.moveSelectionDown();
    }

    theEnemies.resetSelection();
}

//Removes each Character's Augments.
//Pre:  None.
//Post: Cycles through each Character and empties their list of augments.
void BattleManager::removeAugments(){

    //Update players
    thePlayers.resetSelection();

    for(int i = 0 ; i < thePlayers.getSize() ; i++){

        thePlayers.getCurrSelection()->getStats()->removeAugments();
        thePlayers.moveSelectionDown();
    }

    //Update enemies.
    theEnemies.resetSelection();

    for(int i = 0 ; i < theEnemies.getSize() ; i++){

        theEnemies.getCurrSelection()->getStats()->removeAugments();
        theEnemies.moveSelectionDown();
    }
}