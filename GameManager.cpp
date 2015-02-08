#include "GameManager.h"

GameManager::GameManager(){

    keys.resize(MAX_NUM_KEYS);

    for(vector<bool>::iterator it = keys.begin() ; it != keys.end() ; it++)
        *it = false;

    pressedKey = 0;
    test = false;   //Used to set start location.
    battle = false;
    firstTime = true;
    cutscenebool = true;
    cutSwitch = 1;  //Switches between map and white background
    intro = true;   //start screen
    battleCutscene = false , battleVictory = false , startingInstructions = true;
    selectEnemy = 1 , enemyChoice = 0;
    gameTimer = 0;
    brow = 0 , bcol = 0 , charOnMapX = 0 , charOnMapY = 0;
    charOnMapFacing = 0;
    cutsceneFrameCount = 0 , miniCount = 0;
    r = 0 , g = 0 , b = 0 , fade = 8;
    menuChoice = 0;
    prevMap = NULL;
    currMap = NULL;
    battleMap = NULL;
    cutSceneMap = NULL;
    player = NULL;
    //srand (time(NULL));  //Seed random
    //al_start_timer(timer);
    numEnemies = 0;
    //CharFactory charFactory;
    
    enemyIter = enemies.begin();
}

void GameManager::updateKey(int key){

    pressedKey = key;

    if(pressedKey == -1)
        return;

    else{
        
        keys[key] = true;
    }
}


//Loads a cutscene to the GameManager.
bool GameManager::loadCutscene(Cutscene *cutscene){

    //Error loading.
    if(cutscene == NULL)
        return false;
    
    else{ 
        cutscenes.push(cutscene);
        return true;
    }
}

//Loads a Menu to the GameManager. Returns false
//if the Menu is NULL. Returns true if a Menu was added
//to the vector.
bool GameManager::loadMenu(Menu *menu){

    //Error loading.
    if(menu == NULL)
        return false;
    
    else{ 
        menus.push_back(menu);
        return true;
    }
}


void GameManager::playCutscenes(){

    if(cutscenes.empty())
        return;

    else if(cutscenes.front()->play(pressedKey) == true){

        //intro = false;
        if(pressedKey != -1)
            keys[pressedKey] = false;
        
        pressedKey = -1;
        if(cutscenes.front() != NULL){
            delete cutscenes.front();
        }

        cutscenes.pop();
    }
}

//Draws all menus in the vector in LIFO order.
void GameManager::drawMenus(){

    if(menus.empty())
        return;

    /*
    //Only draw current Menu.
    vector<Menu*>::iterator menuIter = menus.end() - 1;

    (*menuIter)->draw();
    */

    vector<Menu*>::iterator menuIter = menus.begin();
   
    //Draw all Menus in the vector.
    while(menuIter != menus.end()){

        (*menuIter)->draw();
        menuIter++;
    }

    //Set iterator to the last element.
    menuIter = menus.end() - 1;

    //Move the selector on the highest menu.
    (*menuIter)->moveSelection(pressedKey);

    //Check if a Menu needs to be removed. Does not remove
    //the last Menu.
    if(pressedKey == LEFT && menus.size() > 1){

        //Resets key to ensure only 1 Menu is removed.
        if(pressedKey != -1)
            keys[pressedKey] = false;
        
        pressedKey = -1;

        menus.pop_back();
        /*
        if(cutscenes.front() != NULL)
            delete cutscenes.front();

        cutscenes.pop();
        */
    }   

    else if(pressedKey == RIGHT && (*menuIter)->currSelectionHasSubMenu()){

        Menu *menuPtr = (*menuIter);
        Menu *subMenuPtr = (*menuIter)->getSelectionsSubMenu(); 
        
        subMenuPtr->setDrawToPrevSelection(menuPtr);
        loadMenu(subMenuPtr);
    }

    resetPressedKey();
}

//Removes all the submenus objects from menus leaving the first
//Menu in the vector.
//Pre:  None.
//Post: Removes all of the Menu objects from the
//      vector in LIFO order until it reaches the beginning.
void GameManager::removeAllSubMenus(){

    vector<Menu*>::iterator menuIter = menus.end();
    //BROKEN!!!
    while(menuIter != menus.begin()){
        menus.pop_back();
        menuIter--;
    }
}

//Save the variables before switching to the battleMap.
void GameManager::saveAreaMapVariables(){

    charOnMapX = player->getUpperLeftX();
    charOnMapY = player->getUpperLeftY();
    charOnMapFacing = player->getFacing();
    prevMap = currMap;
    currMap = battleMap;

    firstTime = false;
}

//Sets the starting location of the player on the battle map.
void GameManager::initializeBattle(){

    //Set start location on the battle map.
    Movement::setStart(*player , *battleMap , 17 , 7);
    
    player->setFacing(LEFT);
}

//Increments the game timer by 1.
void GameManager::increaseGameTimer(){

    //Increase ingame timer.
    gameTimer++;

    //Reset in game timer once it hits 2000.
    if(gameTimer == RESET_TIMER)
        gameTimer = 0;
}

//Returns true if there is a battle going on. Returns false
//if there isn't a battle going on.
bool GameManager::isBattle(){

    if(battle == true)
        return true;

    else return false;
}

//Switch variables bak to the player moving on the map.
void GameManager::switchVariablesToMap(){

    currMap = prevMap;
    Movement::setStartCoords(*player , *currMap , charOnMapX , charOnMapY);
    player->setFacing(charOnMapFacing);
    gameTimer = 0;
    battle = false;
}

//Reset game timer to 0.
void GameManager::resetGameTimer(){

    gameTimer = 0;
}

//Generates the enemies for the battle.
void GameManager::generateEnemies(int maxNumberOfEnemies){

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
        //enemies.push_back(addEnemy);
        theEnemies.loadChar(addEnemy);
    }

    //Set spacing.
    //InitEnemies::initEnemiesSpacing(enemies);
    InitEnemies::initEnemiesSpacing(theEnemies.getList());

    //Reset iterator to the beginning.
    //enemyIter = enemies.begin();  Might need later. For now using iterator in main.
    theEnemies.resetSelection();
}

//Loads all the input model.
void GameManager::loadEnemyModel(ALLEGRO_BITMAP *model){

    enemyModels.push_back(model);
}

//Determines if a battle will occur.
bool GameManager::checkForBattle(){

    if(gameTimer == BATTLE_TIMER && battle == false){

        //Set battle flags to true.
        battle = true;
        firstTime = true;

        //Load battle transition cutscene.
        BattleTrans *theBattle = new BattleTrans(cutSceneMap , currMap , player);
        loadCutscene(theBattle);

        //Create the enemies for the battle.
        generateEnemies(MAX_ENEMIES_PER_BATTLE);

        enemyIter = enemies.begin();

        return true;
    }

    else return false;
}

//Reset enemy iterator to the beginning.
void GameManager::resetEnemyIter(){

    enemyIter = enemies.begin();
}

//Sets the current pressed key to unpressed.
void GameManager::resetPressedKey(){

    if(pressedKey == -1)
        return;
    
    else{
        keys[pressedKey] = false;
        pressedKey = -1;
    }
}

//Creates the victory CutScene.
void GameManager::generateVictoryCutScene(){

    BattleVictory *battleVictory = new BattleVictory(currMap , *player);
    loadCutscene(battleVictory);
}

//Get's the curr menu selection's name.
//Post: Returns the name of the current selection of the back element
//      in the Menus vector. This is the Menu that is currently selected.
std::string GameManager::getMenuSelectionName(){

    return menus.back()->getCurrSelectionName();
}

//Determines if there are still enemies remaining.
//Pre:  None.
//Post: Returns TRUE if there is an Character still in
//      theEnemies list. Returns FALSE of the list is empty.
bool GameManager::enemiesRemaining(){

    return !theEnemies.isEmpty();
}

//Returns the enemies list.
//Pre:  None.
//Post: Returns the vector to the CharacterList.
std::vector<Character*> GameManager::getEnemiesList(){

    return theEnemies.getList();
}

//Gets the currently selected enemy.
//Pre:  None.
//Post: Returns a pointer to the current enemy.
Character* GameManager::getCurrEnemy(){

    return theEnemies.getCurrSelection();
}

//Returns whether or not the currently selected enemy is dead.
//Pre:  None.
//Post: Returns TRUE if the current selection has 0 HP. Returns
//      FALSE otherwise.
bool GameManager::currEnemyDead(){

    return theEnemies.currSelectionIsDead();
}

//Deletes the currently selected enemy.
//Pre:  None.
//Post: Deletes the currently selected enemy.
void GameManager::deleteCurrEnemy(){

    theEnemies.deleteCurrSelectedCharacter();
}

//Moves the currently selected enemy down.
//Pre:  None.
//Post: Moves the currently selected enemy down unless it is
//      already at the bottom.
void GameManager::moveEnemySelectionDown(){

    theEnemies.moveSelectionDown();
}

//Moves the currently selected enemy up.
//Pre:  None.
//Post: Moves the currently selected enemy up unless it is
//      already at the top.
void GameManager::moveEnemySelectionUp(){

    theEnemies.moveSelectionUp();
}