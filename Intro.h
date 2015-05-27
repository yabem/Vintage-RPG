//Intro for the start screen.

#pragma once
#include "Cutscene.h"
#include "TextBox.h"
#include <allegro5/allegro_font.h>
#include "ImageStore.h"
#include "RightToLeftImage.h"
#include "Character.h"

struct ALLEGRO_FONT;

class Intro: public Cutscene{

private:
    int fade;
    int r , g , b;  //Red, green, and blue values for fading.
    ALLEGRO_FONT *introFont;
    ImageStore *imageStore;
    Scenery *background;
    Scenery *midground;
    Scenery *foreground;
    Scenery *moon;
    Character *character;

public:
    Intro(ALLEGRO_FONT *introfont , ImageStore *imageStore);
    virtual ~Intro();
    void loadBackground();
    virtual bool play(const int pressedKey);  
};