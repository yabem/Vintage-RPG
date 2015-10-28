#include "Instruct.h"

//Constructor.
Instruct::Instruct(ALLEGRO_FONT *font , GameManager *gameManager){

    this->introFont = font;
    this->gameManager = gameManager;
    currentText = 0;

    TextBox *textBox = NULL;
        
    textBox = new TextBox("After a harrowing battle with the giant tree god, Ent Man, "
        "you come across a strange town that you have never heard of before. It is in dire "
        "need of saving from an evil monster that is bent on devouring the town and then the entire "
        "world. Dun dun DUNNN!!! You find youself in a party with three other heroes which is fortuitous "
        "because you are going to fight lots of monsters whilst trying to figure out how to save this town. "
        "It's a good old fashioned riddle, wrapped in an enigma, that's nestled inside a conundrum. "
        "Start exploring, get some awesome abilities, and then save the town! ", introFont);
    listOfTexts.push_back(textBox);

    textBox = new TextBox("Tutorial: A few things first. Use the 'Up', 'Down', 'Left', and 'Right' "
        "arrows to move your character. Use 'Space' to interact with objects, people, "
        "and monsters. Use 'I' to access your inventory, 'O' to view completed quests, "
        "'L' to view open quests, and 'U' to view your players stats.", introFont);
    listOfTexts.push_back(textBox);

    textBox = new TextBox("Tutorial: In combat, you can use 'Space' to select actions "
        "and 'C' to reverse actions or selections.", introFont);
    listOfTexts.push_back(textBox);

    textBox = new TextBox("Tutorial: You cannot run from battle or save your progress. Some would "
        "call it ""Hardcore Mode"" while others might call it features the developer didn't implement. "
        "That's the important stuff, now on your way!", introFont);
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