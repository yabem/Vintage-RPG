#include "Intro.h"

//Default constructor.
Intro::Intro(ALLEGRO_FONT *introFont , ImageStore *imageStore){

    fade = 8;
    r = 0 , g = 0 , b = 0;
    frameCount = 0;
    this->introFont = introFont;
    this->imageStore = imageStore;
    this->character = NULL;
}

//Destructor.
Intro::~Intro(){

    delete background;
    delete midground;
    delete foreground;
    delete moon;
}

//Load backgound.
void Intro::loadBackground(){

    this->moon = new RightToLeftImage(
        imageStore->getBitMap("moon"),SCREEN_W,0,-0.1,0);

    this->background = new RightToLeftImage(
        imageStore->getBitMap("forestBackground"),0,0,-4,0);

    this->midground = new RightToLeftImage(
        imageStore->getBitMap("forestMidground"),0,0,-8,0);

    this->character = new Character(imageStore->getBitMap("introPlayer")
        , 32 , 32 , 10 , 5 , rate);
    character->setFacing(UP);
    character->setX(PixelConversion::convertTilesToPixels(9));
    character->setY(313);

    this->foreground = new RightToLeftImage(
        imageStore->getBitMap("forestForeground"),0,0,-16,0);
}

//Plays the cutscene. Returns false if not done playing, returns true
//when done playing.
bool Intro::play(const int pressedKey){

    moon->animate();
    background->animate();
    midground->animate();
    character->animate();
    foreground->animate();
    
    moon->draw();
    background->draw();
    midground->draw();
    character->draw();
    foreground->draw();

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
