#include "PlayMusic.h"

PlayMusic::PlayMusic(GameManager *gameManager , std::string songName){

    this->gameManager = gameManager;
    this->songName = songName;
}

PlayMusic::~PlayMusic(){

    //Nothing to delete.
}

//Only executes once so always returns true.
bool PlayMusic::play(const int pressedKey){

    gameManager->getMusicBox()->playSong(songName);
    return true;
}