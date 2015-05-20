//NPC says a message then a battle ensues.

#include "NPCWithDialogue.h"
#include "BattleManager.h"
#include "StartBattle.h"

class NPCWithDialogueThenBattle : public NPCWithDialogue{

private:

    BattleManager *battleManager;
    std::vector<int> enemyList;
    std::vector<int> enemyLevels;
    ALLEGRO_FONT *font;

public:

    NPCWithDialogueThenBattle(ALLEGRO_BITMAP *image , int sx , int sy ,
        DrawRepository *drawRepository , GameManager *gameManager , 
        std::string message , BattleManager *battleManager ,
        ALLEGRO_FONT *font);

    virtual ~NPCWithDialogueThenBattle();
    void loadEnemies(std::vector<int> enemyList , std::vector<int> enemyLevels);
    virtual void playCutscene(int pressedKey);
};