//Text without a border or background.

#pragma once
#include <string>
#include <allegro5/allegro_font.h>
#include "I_InfoBox.h"
#include "I_Creature.h"
#include "Stats.h"
#include "GameConfig.h"

class FloatingText : public I_InfoBox{

private:

    int drawX , drawY;      //Draw locations.
    int redColor, greenColor , blueColor;   
    ALLEGRO_FONT *font;     //Font style.
    std::string drawMessage;

public:

    FloatingText(ALLEGRO_FONT *font);
    ~FloatingText();
    void setDrawX(int drawX);
    void setDrawY(int drawY);
    void setDrawMessage(std::string drawMessage);
    void setFloatingTextToTopOfCreature(I_Creature *i_Creature);
    void setFloatingTextToCreatureHealth(I_Creature *i_Creature);
    void draw();
};