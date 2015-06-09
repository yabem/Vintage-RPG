#include "Instruct.h"

//Constructor.
Instruct::Instruct(ALLEGRO_FONT *font){

   frameCount = 0;

   this->textBox = new TextBox("You awaken in a strange town that you have never seen before."
       "You don't know where you are and how you got here."
       "The last thing you remember was running away from something in the woods."
       "Find some clues and figure out what happened. " , font);
}

//Destructor.
Instruct::~Instruct(){

    delete textBox;
}

//Plays the cutscene. Returns false if not done playing, returns true
//when done playing.
bool Instruct::play(const int pressedKey){

    textBox->draw();

    if(pressedKey == SPACE)
        return true;

    else return false;
}