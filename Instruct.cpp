#include "Instruct.h"

//Constructor.
Instruct::Instruct(ALLEGRO_FONT *font , GameManager *gameManager){

    this->introFont = font;
    this->gameManager = gameManager;
    currentText = 0;

    TextBox *textBox = NULL;
        
    textBox = new TextBox("You awaken in a strange town that you have never seen before."
        "You don't know where you are and how you got here. "
        "Oddly enough you are in a party with three other people. Good thing because you are "
        "going to fight lots of monsters whilst trying to understand this riddle, "
        "which is wrapped in an enigma, that's nestled inside a "
        "conundrum. Find some clues and figure out what happened. Dun dun DUNNN!!! ", introFont);
    listOfTexts.push_back(textBox);

    textBox = new TextBox("Brief Tutorial: A few things first. Use the 'Up', 'Down', 'Left', and 'Right' "
        "arrows to move your character. Use 'Space' to interact with objects, people, "
        "and monsters. Use 'I' to access your inventory, 'O' to view completed quests, "
        "'L' to view open quests, and 'U' to view your players stats.", introFont);
    listOfTexts.push_back(textBox);

    textBox = new TextBox("Brief Tutorial: In combat, you can use 'Space' to select actions "
        "and 'C' to reverse actions or selections. Now you're prepared and "
        "on your way! Enjoy!", introFont);
    listOfTexts.push_back(textBox);
}

//Destructor.
Instruct::~Instruct(){

    std::vector<TextBox*>::iterator textIter = listOfTexts.begin();

    while(textIter != listOfTexts.end()){

        delete *textIter;
        textIter++;
    }
}

//Plays the cutscene. Returns false if not done playing, returns true
//when done playing.
bool Instruct::play(const int pressedKey){

    listOfTexts[currentText]->draw();

    if(pressedKey == SPACE && (currentText + 1) == listOfTexts.size()){
     
        gameManager->getMusicBox()->playSong("Enchanted Valley");
        return true;
    }

    else if(pressedKey == SPACE){

        currentText++;
        gameManager->resetPressedKey();
    }

    else return false;
}