#include "DrawRepository.h"


//Constructor.
DrawRepository::DrawRepository(){

    battleManager = NULL;
}

/*
//Loads a cutscene to the GameManager.
bool DrawRepository::loadCutscene(Cutscene *cutscene){

    //Error loading.
    if(cutscene == NULL)
        return false;
    
    else{ 
        cutscenes.push(cutscene);
        return true;
    }
}


void DrawRepository::playCutscenes(){

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
*/

//Loads the battleManager.
//Pre:  The BattleManager is not NULL.
//Post: The battleManager pointer is loaded.
void DrawRepository::loadBattleManager(BattleManager *battleManager){

    this->battleManager = battleManager;
}

//Checks if there are any remaining animations.
//Pre:  None.
//Post: Returns true if the queue is empty otherwise returns false.
bool DrawRepository::animationsEmpty(){

    return animations.empty();
}


//Loads a single Animation.
//Pre:  The Animation is not NULL.
//Post: Loads the Animation to the animations queue. Returns true
//      if the Animation was successfully loaded otherwise returns
//      false.
bool DrawRepository::loadAnimation(Animation *animation){

    if(animation == NULL)
        return false;
    
    else{
        animations.push(animation);
        return true;
    }
}



//Plays all the loaded Animations.
//Pre:  None.
//Post: Plays the Animations in the queue and
//      deletes the current enemy if it is dead.
void DrawRepository::playAllAnimations(){

    //Play all animations.
    if(!animations.empty()){

        //Pop off the animaton once it's done.
        if(animations.front()->play()){

            //Delete animation to reclaim memory.
            delete animations.front();  
            animations.pop();
        }
                         
        //Move cursor back once animations are done.
        if(animations.size() == 0){

            //Checks if the current enemy is dead and deletes it.
            battleManager->deleteDeadCurrEnemy();
        }
    }
}
