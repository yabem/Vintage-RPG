#include "EndGameWithCredits.h"

//Constructor.
EndGameWithCredits::EndGameWithCredits(ALLEGRO_FONT *font , GameManager *gameManager){

    this->introFont = font;
    this->gameManager = gameManager;
    currentText = 0;

    TextBox *textBox = NULL;
        
    textBox = new TextBox("Congratulations, you've finished One Hour RPG. Hopefully it didn't "
        "take longer than an hour to beat. Well a few credits...", introFont);
    listOfTexts.push_back(textBox);

    textBox = new TextBox("Credits: I finished this over the course of a year and a half in Allegro 5. "
        "It was a labor of love and I'm glad I completed it. Thanks to those who helped me by playing "
        "my first two games and willing to still play this one. A special shout out to Joanna my soon "
        "to be bride for putting up with my obsession and late night typing!"
        , introFont);

    listOfTexts.push_back(textBox);

    textBox = new TextBox(
        "Here is a list of all the websites I used stuff from."
        "Tile editor http://tilestudio.sourceforge.net/"
        "Tiles taken from http://opengameart.org/content/tiled-terrains"
        "More tiles taken from http://opengameart.org/content/lpc-tile-atlas"
        "Characters taken from http://rpg.hamsterrepublic.com/ohrrpgce/Free_Sprites"
        "Fireblast taken from http://opengameart.org/content/fire-blast"
        "Lightning http://opengameart.org/content/painterly-spell-icons-part-2"
        "Music http://incompetech.com/music/royalty-free/index.html?collection=045&Search=Search"
        "Music Metaphysik http://incompetech.com/music/royalty-free/index.html?collection=035&Search=Search"
        "Music Split Synapse, Mistake the Gateway, Alchemists Tower http://incompetech.com/music/royalty-free/index.html?collection=033&page=1"
        , introFont);
    listOfTexts.push_back(textBox);

    textBox = new TextBox(
        "I hope you enjoyed it. I'll create another game soon... so be on the lookout!"
        , introFont);
    listOfTexts.push_back(textBox);
}

//Destructor.
EndGameWithCredits::~EndGameWithCredits(){

    std::vector<TextBox*>::iterator textIter = listOfTexts.begin();

    while(textIter != listOfTexts.end()){

        delete *textIter;
        textIter++;
    }
}

//Plays the cutscene. Returns false if not done playing, returns true
//when done playing.
bool EndGameWithCredits::play(const int pressedKey){

    gameManager->getMusicBox()->playSong("Moonlight Hall");

    listOfTexts[currentText]->draw();

    if(pressedKey == SPACE && (currentText + 1) == listOfTexts.size()){
     
        gameManager->setEndOfGameLoopToEnd();
        return true;
    }

    else if(pressedKey == SPACE){

        currentText++;
        gameManager->resetPressedKey();
    }

    else return false;
}