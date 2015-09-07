#include "NPCWithDialogue.h"

NPCWithDialogue::NPCWithDialogue( ALLEGRO_BITMAP *image , int sx , int sy ,
    DrawRepository *drawRepository , GameManager *gameManager ,
    std::string message , ALLEGRO_FONT *font) : Tangible(image , sx , sy){

    this->gameManager = gameManager;
    this->drawRepository = drawRepository;
    this->nameOfSongForMusicChange = "";
    this->message = message;
    this->character = NULL;

    this->currentFrame = 0;
    this->segmentOfImage = 0;
    this->facingDirection = 0;
    this->framesPerSequence = 0;
    this->numSequence = 0;
    this->font = font;
}

NPCWithDialogue::~NPCWithDialogue(){

    delete character;
}

void NPCWithDialogue::createCharacter(int w , int h , 
    int framesPerSequence , int numSequence , int moveRate , AreaMap *areaMap){

    this->character = new Character(image , w , h , framesPerSequence ,
        numSequence , moveRate);

    this->framesPerSequence = framesPerSequence;
    this->numSequence = numSequence;
}

void NPCWithDialogue::setCharacterFacing(int direction){

    character->setFacing(direction);
}

void NPCWithDialogue::setMusic(std::string songName){

    this->nameOfSongForMusicChange = songName;
}

void NPCWithDialogue::draw(){

    this->character->setX(dx);
    this->character->setY(dy);
    character->animate();
    character->draw();
}

void NPCWithDialogue::playCutscene(int pressedKey){

    Dialogue *cutscene = new Dialogue(gameManager , font);
    cutscene->setText(message);
    this->drawRepository->loadCutscene(cutscene);
    gameManager->resetPressedKey();
    gameManager->getMusicBox()->playSong(nameOfSongForMusicChange);
}