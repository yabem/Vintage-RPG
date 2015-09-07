#include "NPCWithDialogueThenCutscene.h"

NPCWithDialogueThenCutscene::NPCWithDialogueThenCutscene(ALLEGRO_BITMAP *image , int sx , int sy ,
    DrawRepository *drawRepository , GameManager *gameManager , 
    std::string message , ALLEGRO_FONT *font) : 
    NPCWithDialogue(image , sx , sy , drawRepository , gameManager , message , font){

    this->font = font;
}

NPCWithDialogueThenCutscene::~NPCWithDialogueThenCutscene(){

}

void NPCWithDialogueThenCutscene::playCutscene(int pressedKey){

    Dialogue *cutscene = new Dialogue(gameManager , font);
    cutscene->setText(message);
    this->drawRepository->loadCutscene(cutscene);

    EndGameWithCredits *endGameWithCredits = new EndGameWithCredits(font , gameManager);
    this->drawRepository->loadCutscene(endGameWithCredits);

    gameManager->resetPressedKey();
}