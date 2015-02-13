#include "GameManager.h"

GameManager::GameManager(){

    keys.resize(MAX_NUM_KEYS);

    for(vector<bool>::iterator it = keys.begin() ; it != keys.end() ; it++)
        *it = false;

    pressedKey = 0;
    battle = false;
    firstTime = true;
    gameTimer = 0;
    charOnMapX = 0 , charOnMapY = 0;
    charOnMapFacing = 0;
    menuChoice = 0;
    prevMap = NULL;
    currMap = NULL;
    battleMap = NULL;
    cutSceneMap = NULL;
    player = NULL;
    numEnemies = 0;
}

void GameManager::updateKey(int key){

    pressedKey = key;

    if(pressedKey == NO_KEY)
        return;

    else{
        
        keys[key] = true;
    }
}

//Returns a pointer to the player at the front of the list.
Character* GameManager::getFrontPlayer(){

    return player;
}

//Returns the enemies list.
//Pre:  None.
//Post: Returns a reference to the Animations queue.
//xstd::queue<Animation*>& GameManager::getAnimations(){

   //x return animations;
//x}

//Determines if the key is pressed.
//Pre:  The key is within the range of the vector.
//Post: Returns the value of the value of the key. TRUE
//      is returned if the key is active, FALSE otherwise.
bool GameManager::isKeyActive(int key){

    if(key >= keys.size() || key < 0)
        return false;

    else return keys[key];
}


//Makes a key inactive.
//Pre:  The key is within the range of the vector.
//Post: Sets the key to inactive in the keys vector.
//      Does nothing if the key is out of range.
void GameManager::makeKeyInactive(int key){

    if(key >= keys.size() || key < 0)
        return;

    else keys[key] = false;
}

//x
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

//x
void GameManager::playCutscenes(){

    if(cutscenes.empty())
        return;

    else if(cutscenes.front()->play(pressedKey) == true){

        if(pressedKey != NO_KEY)
            keys[pressedKey] = false;
        
        pressedKey = NO_KEY;
        if(cutscenes.front() != NULL){
            delete cutscenes.front();
        }

        cutscenes.pop();
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

//Loads all the input model.
void GameManager::loadEnemyModel(ALLEGRO_BITMAP *model){

    enemyModels.push_back(model);
}

//Sets the current pressed key to unpressed.
void GameManager::resetPressedKey(){

    if(pressedKey == NO_KEY)
        return;
    
    else{
        keys[pressedKey] = false;
        pressedKey = NO_KEY;
    }
}

//Creates the victory CutScene.
void GameManager::generateVictoryCutScene(){

    BattleVictory *battleVictory = new BattleVictory(currMap , *player);
    loadCutscene(battleVictory);
}

//Determines if there are remaining cutscenes.
//Pre:  None.
//Post: Returns true if the cutscenes vector is empty.
//      Returns false otherwise.
bool GameManager::cutscenesEmpty() const{
    
    return cutscenes.empty();
}      

//Returns the pressedKey
//Pre:  None.
//Post: Returns the pressedKey.
int GameManager::getPressedKey() const{

    return pressedKey;
}

//Sets the pressedKey to inactive.
//Pre:  The key is within the range of the vector.
//Post: Sets the pressedKey to inactive and updates
//      the pressedKey to NO_KEY.
void GameManager::setPressedKeyToInactive(){

    makeKeyInactive(pressedKey);

    pressedKey = NO_KEY;
}