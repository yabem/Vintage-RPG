#include "Instruct.h"

//Constructor.
Instruct::Instruct(){

   frameCount = 0;

   textBox.loadText("You awaken in a strange town that you have never seen before. "
       "You don't know where you are and why you are there. "
       "Your first task is to find some clues and figure out what happened. " 
       "Go forth and start your quest.");
}

//Destructor.
Instruct::~Instruct(){

}

//Plays the cutscene. Returns false if not done playing, returns true
//when done playing.
bool Instruct::play(const int pressedKey){

    textBox.draw();

    if(pressedKey == SPACE)
        return true;

    else return false;
}