#include "Dialogue.h"
    
Dialogue::Dialogue(GameManager *gameManager , ALLEGRO_FONT *introFont){

   frameCount = 0;
   this->gameManager = gameManager;
   this->r = 0;
   this->b = 0;
   this->g = 0;
   this->introFont = introFont;
}

Dialogue::~Dialogue(){

    delete textBox;
}

//Sets the text that will be displayed.
void Dialogue::setText(std::string message){

    this->textBox = new TextBox(message , introFont);
}

//Plays the cutscene. Returns false if not done playing, returns true
//when done playing.
bool Dialogue::play(const int pressedKey){

    //Animate player.
    gameManager->player->animate();
            
    //Animate the sceneries. 
    gameManager->currMap->animateSceneries();

    //Draw map.
    Draw::drawArea(*gameManager->currMap , *gameManager->player);

    textBox->draw();

    if(pressedKey == SPACE){
        return true;
    }

    else return false;
}