#include "GameManager.h"

GameManager::GameManager(){

    keys.resize(MAX_NUM_KEYS);

    for(vector<bool>::iterator it = keys.begin() ; it != keys.end() ; it++)
        *it = false;

    pressedKey = 0;
    battle = false;
    gameTimer = 0;
    charOnMapX = 0 , charOnMapY = 0;
    charOnMapFacing = 0;
    prevMap = NULL;
    currMap = NULL;
    battleMap = NULL;
    cutSceneMap = NULL;
    player = NULL;
    numEnemies = 0;
    endOfGameLoop = false; 
}

//Destructor.
GameManager::~GameManager(){

    //Default is fine.
}

//Sets the endOfGameLoop to exit.
//Pre:  None.
//Post: Sets endOfGameLoop to true.
void GameManager::setEndOfGameLoopToEnd(){

    endOfGameLoop = true;
}

//Gets the value of endOfGameLoop.
//Pre:  None.
//Post: Returns the value of isEndOfGameLoop.
bool GameManager::isEndOfGameLoop(){

    return endOfGameLoop;
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

//Returns the charList.
//Pre:  None.
//Post: Returns a pointer to the players CharacterList.
CharacterList* GameManager::getList(){

    return thePlayers;
}

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


//Save the variables before switching to the battleMap.
void GameManager::saveAreaMapVariables(){

    charOnMapX = player->getUpperLeftX();
    charOnMapY = player->getUpperLeftY();
    charOnMapFacing = player->getFacing();
    prevMap = currMap;
    currMap = battleMap;
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

//Loads the DrawRepository
//Pre:  The DrawRepository is valid.
//Post: Loads the DrawRespository to the GameManager.
void GameManager::loadDrawRepository(DrawRepository *drawRepository){

    this->drawRepository = drawRepository;
}

//Loads the list of players.
void GameManager::loadPlayers(CharacterList *characterList){

    this->thePlayers = characterList;
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

//Removes a tangible from the current area map.
//Pre:  None.
//Post: Removes the Tangible that has the same identifierName as
//      the input identifierName.
bool GameManager::removeTangibleFromCurrMap(std::string identifierName){

    return currMap->removeTangible(identifierName);
}