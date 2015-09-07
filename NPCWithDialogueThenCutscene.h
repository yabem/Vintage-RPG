//NPC says a message then a battle ensues.

#pragma once
#include "NPCWithDialogue.h"
#include "EndGameWithCredits.h"

class NPCWithDialogueThenCutscene : public NPCWithDialogue{

protected:

public:

    NPCWithDialogueThenCutscene(ALLEGRO_BITMAP *image , int sx , int sy ,
        DrawRepository *drawRepository , GameManager *gameManager , 
        std::string message , ALLEGRO_FONT *font);

    virtual ~NPCWithDialogueThenCutscene();
    virtual void playCutscene(int pressedKey);
};