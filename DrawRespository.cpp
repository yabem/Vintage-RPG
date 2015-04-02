#include "DrawRepository.h"


//Constructor.
DrawRepository::DrawRepository(){

}

//Destructor.
DrawRepository::~DrawRepository(){

    //Deallocate cutscenes remaining in queue.
    while(!cutscenes.empty()){

        delete cutscenes.front();
        cutscenes.pop();
    }

    //Deallocate animations remaining in queue.
    while(!animations.empty()){

        delete animations.front();
        animations.pop();
    }
}

//Loads the GameManager.
void DrawRepository::loadGameManager(I_Manager *gameManager){

    this->gameManager = gameManager;
}

//Loads a Cutscene to the cutscenes queue.
bool DrawRepository::loadCutscene(Cutscene *cutscene){

    //Error loading.
    if(cutscene == NULL)
        return false;
    
    else{ 
        cutscenes.push(cutscene);
        return true;
    }
}

//Draws all the cutscenes.
//Pre:  None.
//Post: Continually draws the cutscene until the cutscene is done
//      or the correct key is pressed by the player.
void DrawRepository::playCutscenes(){

    int pressedKey = gameManager->getPressedKey();

    if(cutscenes.empty())
        return;

    else if(cutscenes.front()->play(pressedKey) == true){

        if(pressedKey != NO_KEY)
            gameManager->setPressedKeyToInactive();

        if(cutscenes.front() != NULL){
            delete cutscenes.front();
        }

        cutscenes.pop();
    }
}

//Checks if there are any remaining animations.
//Pre:  None.
//Post: Returns true if the queue is empty otherwise returns false.
bool DrawRepository::animationsEmpty(){

    return animations.empty();
}

//Checks if there are any remaining Cutscenes.
//Pre:  None.
//Post: Returns true if the queue is empty otherwise returns false.
bool DrawRepository::cutscenesEmpty(){

    return cutscenes.empty();
}


//Loads a single Animation.
//Pre:  The Animation is not NULL.
//Post: Loads the Animation to the animations queue. Returns true
//      if the Animation was successfully loaded otherwise returns
//      false.
bool DrawRepository::loadAnimation(I_Animation *animation){

    if(animation == NULL)
        return false;
    
    else{
        animations.push(animation);
        return true;
    }
}

//Loads a cursor.
//Pre:  The Cursor is not NULL.
//Post: A Cursor is loaded to the vector.
void DrawRepository::loadCursor(Cursor *cursor){

    if(cursor == NULL)
        return;

    else cursors.push(cursor);
}

//Draws the top cursor.
//Pre:  None.
//Post: Draws the top cursor to the screen.
void DrawRepository::drawTopCursor(){

    if(!cursors.empty())
        cursors.front()->draw();
}

//Remove the top cursor.
//Pre:  None.
//Post: Removes the top cursor from the list.
void DrawRepository::removeTopCursor(){

    cursors.pop();
}

//Plays all the loaded Animations.
//Pre:  None.
//Post: Plays each Animation and pops it off the queue once it's done.
//      Returns true if there are animations to play. Returns false
//      otherwise.
bool DrawRepository::playAllAnimations(){

    if(animations.empty())
        return false;

    //Play all animations.
    else{

        //Pop off the animaton once it's done.
        if(animations.front()->play()){

            //Delete animation to reclaim memory.
            delete animations.front();  
            animations.pop();
        }

        return true;
    }
}