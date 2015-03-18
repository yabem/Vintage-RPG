#include "InitPlayers.h"


//Set the spacing so the enemies are drawn correctly on the screen.
void InitPlayers::initPlayersSpacing(vector<Character*> thePlayers){

    int totalWidth = BATTLE_START_X_PLAYERS;
    int totalHeight = BATTLE_START_Y_PLAYERS;

    //Loop through all enemies to get the total height.
    for(vector<Character*>::iterator it = thePlayers.begin() ;
        it != thePlayers.end() ; it++){
        
        //Set x and y start locations.
        (*it)->setX(totalWidth);
        (*it)->setY(totalHeight);
        (*it)->resetSequence();

        if((*it)->isDead())
            (*it)->makeDead();

        else (*it)->setFacing(LEFT);
        
        totalHeight += ((*it)->getH() + DEFAULT_BAR_HEIGHT);
    }
}