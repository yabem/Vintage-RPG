//Used for battle. Increases with at the rate of the
//rate.

#pragma once;
#include "Enums.h"  //Used for FPS declaration.
#include <allegro5/allegro_primitives.h>

const int INNER_OFFSET = 3;
const float DEFAULT_BAR_AMOUNT = DEFAULT_BAR_WIDTH - (INNER_OFFSET * 2);

const float DEFAULT_SECONDS = 2;    //Time it takes for the bar to fill.
const float DEFAULT_FILL_RATE = DEFAULT_BAR_AMOUNT / (FPS * DEFAULT_SECONDS);
const int DEFAULT_DRAWX = 100;
const int DEFAULT_DRAWY = 100;

//White
const int DEFAULT_OUTTER_R = 255;
const int DEFAULT_OUTTER_G = 255;
const int DEFAULT_OUTTER_B = 255;

//Grey
const int DEFAULT_INNER_R = 155;
const int DEFAULT_INNER_G = 155;
const int DEFAULT_INNER_B = 155;

class TurnTimer{

private:

    int drawX;  //Draw to x coordinate;
    int drawY;  //Draw to y coordinate.
    int outterWidth;  //Width of the outter rectangle.
    float fillRate;   //The rate at which the timer increases.
    float totalFill;   //Total amount of the timer.
    float currentFill;  //Amount of the timer that is full.

    //Draw from and draw to coordinates for the inner rectangle.
    int upLeftOutterX;
    int upLeftOutterY;
    int lowRightOutterX;
    int lowRightOutterY;
   
    //Draw from and draw to coordinates for the inner rectangle.
    int upLeftInnerX;
    int upLeftInnerY;
    float lowRightInnerX;
    int lowRightInnerY;
    
    //Color for the background bar.
    int colorOutterR , colorOutterG , colorOutterB;

    //Color for the timer bar.
    int colorInnerR , colorInnerG , colorInnerB;

public:

    //Constructor.
    TurnTimer();

    //Destructor.
    ~TurnTimer();

    void setRate(int rate);
    void setDrawX(int drawX);
    void setDrawY(int drawY);
    int getOutterWidth() const;
    
    //Determines the draw points based on the drawX and drawY. 
    void calculateDrawPoints();

    //Draws the TurnTimer to the screen.
    void draw();

    //Increase the currentFill by the fillRate.
    void updateCurrentFill();

    //Checks if the fill bar is full.
    bool innerBarIsFull();

    //Resets currentFill.
    void resetCurrentFill();
};