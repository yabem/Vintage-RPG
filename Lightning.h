//Creates ligthing that flashes on teh screen

#pragma once
#include "Scenery.h"
#include "ImageStore.h"
#include "FlashingImage.h"
#include "GameConfig.h" //Used for FPS

class Lightning : public Scenery{

private:

    float transparencyLevel;
    float transparencyIncrementer;
    float redTransparency;
    float greenTransparency;
    float BlueTransparency;
    float minTransparency;
    float maxTransparency;
    bool drawToScreen;
    
    FlashingImage *whiteFlash;
    FlashingImage *lightning;
    ImageStore *imageStore;
    
    float percentChanceOfStrikePerCycle;
    int lengthOfCycleInFrames;
    int lengthOfCycleInSeconds;

public:

    Lightning(ImageStore *imageStore);

    virtual ~Lightning();
    virtual void animate(); 
    virtual void draw();    //Draws the Scenery to the buffer.
};