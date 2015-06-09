//NPC says a message then a battle ensues.

#pragma once
#include "NPCWithDialogueAndGift.h"
#include "RewardAbility.h"
#include "PlayerEntity.h"
#include "Cutscene.h"

class ItemLocationWithGift : public NPCWithDialogueAndGift{

private:

public:

    ItemLocationWithGift(ALLEGRO_BITMAP *image , int sx , int sy ,
        DrawRepository *drawRepository , GameManager *gameManager ,
        ALLEGRO_FONT *font , PlayerEntity *playerEntity);

    virtual ~ItemLocationWithGift();
    virtual void playCutscene(int pressedKey);
    virtual void draw();
};