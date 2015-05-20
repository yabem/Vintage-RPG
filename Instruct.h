//Instructions for when the player starts the game.

#pragma once
#include "Cutscene.h"
#include "TextBox.h"
#include <allegro5/allegro_font.h>
struct ALLEGRO_FONT;

class Instruct: public Cutscene{

private:
    int fade;
    int r , g , b;  //Red, green, and blue values for fading.
    ALLEGRO_FONT *introFont;
    TextBox *textBox;

public:
    Instruct(ALLEGRO_FONT *font);
    virtual ~Instruct();
    virtual bool play(const int pressedKey);
};
