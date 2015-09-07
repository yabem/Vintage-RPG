#include "NPCWithDialogueThenBattle.h"

NPCWithDialogueThenBattle::NPCWithDialogueThenBattle(ALLEGRO_BITMAP *image , int sx , int sy ,
    DrawRepository *drawRepository , GameManager *gameManager , 
    std::string message , BattleManager *battleManager , ALLEGRO_FONT *font ,
    std::string nameOfNPC ) : 
    NPCWithDialogue(image , sx , sy , drawRepository , gameManager , message , font){

    this->battleManager = battleManager;
    this->font = font;
    this->nameOfNPC = nameOfNPC;
}

NPCWithDialogueThenBattle::~NPCWithDialogueThenBattle(){

}

void NPCWithDialogueThenBattle::loadEnemies(std::vector<int> enemyList ,
    std::vector<int> enemyLevels){

    this->enemyList = enemyList;
    this->enemyLevels = enemyLevels;
}

void NPCWithDialogueThenBattle::playCutscene(int pressedKey){

    Dialogue *cutscene = new Dialogue(gameManager , font);
    cutscene->setText(message);
    this->drawRepository->loadCutscene(cutscene);

    StartBattle *startBattle = new StartBattle(this->battleManager ,
        enemyList , enemyLevels);
    this->drawRepository->loadCutscene(startBattle);

    RemoveTangible *removeTangible = new RemoveTangible(this->gameManager ,
        this->nameOfNPC);
    this->drawRepository->loadCutscene(removeTangible);

    PlayMusic *playMusic = new PlayMusic(gameManager , 
        this->nameOfSongForMusicChange);
    this->drawRepository->loadCutscene(playMusic);

    gameManager->resetPressedKey();
}