//NPC with a dialogue box that the player can read.

#pragma once
#include "Tangible.h"
#include "DrawRepository.h"
#include "GameConfig.h" //Used for KEY enums.
#include "Dialogue.h"
#include "Intro.h"
#include "Character.h"
#include "AreaMap.h"

class NPCWithDialogue : public Tangible{

protected:

    DrawRepository *drawRepository;
    GameManager *gameManager;
    std::string message;
    int currentFrame;
    int segmentOfImage;
    int facingDirection;
    int framesPerSequence;
    int numSequence;
    Character *character;
    ALLEGRO_FONT *font;

public:

    NPCWithDialogue(ALLEGRO_BITMAP *image , int sx , int sy ,
        DrawRepository *drawRepository , GameManager *gameManager , 
        std::string message , ALLEGRO_FONT *font);
    virtual ~NPCWithDialogue();
    void createCharacter(int w , int h , int framesPerSequence ,
        int numSequence , int moveRate , AreaMap *areaMap);
    void setCharacterFacing(int direction);
    virtual void draw();
    virtual void playCutscene(int pressedKey);  
};