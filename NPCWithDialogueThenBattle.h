//NPC says a message then a battle ensues.

#pragma once
#include "NPCWithDialogue.h"
#include "BattleManager.h"
#include "StartBattle.h"
#include "RemoveTangible.h"

class NPCWithDialogueThenBattle : public NPCWithDialogue{

private:

    BattleManager *battleManager;
    std::vector<int> enemyList;
    std::vector<int> enemyLevels;
    ALLEGRO_FONT *font;
    std::string nameOfNPC;

public:

    NPCWithDialogueThenBattle(ALLEGRO_BITMAP *image , int sx , int sy ,
        DrawRepository *drawRepository , GameManager *gameManager , 
        std::string message , BattleManager *battleManager ,
        ALLEGRO_FONT *font , std::string nameOfNPC);

    virtual ~NPCWithDialogueThenBattle();
    void loadEnemies(std::vector<int> enemyList , std::vector<int> enemyLevels);
    virtual void playCutscene(int pressedKey);
};