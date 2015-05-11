#include "Lightning.h"

//Constructor.
Lightning::Lightning(ImageStore *imageStore){

    this->bmap = NULL;
    this->transparencyLevel = .05;
    this->transparencyIncrementer = .01;
    this->redTransparency = .5;
    this->greenTransparency = .5;
    this->BlueTransparency = .5;
    this->minTransparency = 0.1;
    this->maxTransparency = .99;
    this->crFrame = 0;
    this->drawToScreen = false;
    this->percentChanceOfStrikePerCycle = 20;

    this->lengthOfCycleInSeconds = 1;
    this->lengthOfCycleInFrames = FPS * lengthOfCycleInSeconds;

    this->imageStore = imageStore;
    this->lightning = new FlashingImage(imageStore->getBitMap
        ("lightning") , 0 , 0 , 0 , 0);
    this->whiteFlash = new FlashingImage(imageStore->getBitMap
        ("whiteFlash") , 0 , 0 , 0 , 0);
}

//Destructor.
Lightning::~Lightning(){

    delete lightning;
    delete whiteFlash;
}

//Increases the frame count and moves through the animation sequence.
void Lightning::animate(){

    if(crFrame == lengthOfCycleInFrames){

        if(rand() % 100 < percentChanceOfStrikePerCycle){
            whiteFlash->setDrawToScreenTrue();
            lightning->setDrawToScreenTrue();

            int randomNum = rand() % (al_get_bitmap_width
                (imageStore->getBitMap("lightning")));
            lightning->setDX(randomNum);
        }

        crFrame = 0;
    }

    crFrame++;
}

//Draws the Scenery to the buffer.
void Lightning::draw(){

    whiteFlash->animate();
    whiteFlash->draw();
    lightning->animate();
    lightning->draw();
}