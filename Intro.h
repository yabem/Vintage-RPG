//Intro for the start screen.

#pragma once
#include "Cutscene.h"
#include "TextBox.h"
#include <allegro5/allegro_font.h>

struct ALLEGRO_FONT;

class Intro: public Cutscene{

private:
    int fade;
    int r , g , b;  //Red, green, and blue values for fading.
    ALLEGRO_FONT *introFont;

public:
    Intro(ALLEGRO_FONT *introfont);
    virtual ~Intro();
    virtual bool play(const int pressedKey);  
};