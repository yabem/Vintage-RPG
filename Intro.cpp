#include "Intro.h"

//Default constructor.
Intro::Intro(ALLEGRO_FONT *introFont){

    fade = 8;
    r = 0 , g = 0 , b = 0;
    frameCount = 0;
    this->introFont = introFont;
}

//Destructor.
Intro::~Intro(){

}

//Plays the cutscene. Returns false if not done playing, returns true
//when done playing.
bool Intro::play(const int pressedKey){

    r += fade ; g += fade ; b += fade;
    frameCount++;
    al_draw_textf(introFont , al_map_rgb(255, 255, 255), 250, SCREEN_H / 2, 0, "Vintage RPG");

    if(frameCount % 30 == 0)
        fade *= -1;

    al_draw_textf(introFont , al_map_rgb(r , g , b), 213, SCREEN_H / 2 + 30 , 0, "Press Space to Begin");

    if(pressedKey == SPACE)
        return true;

    else return false;
}
