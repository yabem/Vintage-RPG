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

