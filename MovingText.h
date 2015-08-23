#pragma once
#include "I_Animation.h"
#include "FontColorSettings.h"
#include "DrawTextWithBorder.h"
#include <allegro5/allegro_font.h>

struct ALLEGRO_FONT;

class MovingText: public I_Animation{

private:

    int w , h;              //Width and height of the bitmap.
    int sx , sy;            //Start location.
    float dx , dy;            //Draw location.
    int ex , ey;            //Destination location.
    float xRate , yRate;      //Rate at which x and y increase in order to get from sx and sy to
                            //dx and dy within the number of frames.
    int currFrame;          //Frame the animation is currently on.
    float ttlFrames;          //Total number of frames the animation lasts.
    bool initialized;       //Keeps track of whether or not the animation has been set.

    std::string text;       //Text to draw.
    ALLEGRO_FONT *font;     //
    bool rebound;           //Flag for determining if you want the text to move to the end and back.
                            //True means the text will rebound. False means it will only go one direction.

public:
    
    MovingText(ALLEGRO_FONT *font , int w , int h , float ttlFrames , bool rebound);  //Constructor.
    virtual ~MovingText();  //Destructor.

    virtual bool play();    //Draws the text animation.

    //Initialize the font, start, and end locations.
    virtual void initialize(std::string text , int sx , int sy , int ex , int ey);     
};