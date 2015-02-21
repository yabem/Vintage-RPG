#include "TurnTimer.h"


//Constructor.
TurnTimer::TurnTimer(){

    fillRate = DEFAULT_FILL_RATE;
    drawX = DEFAULT_DRAWX; 
    drawY = DEFAULT_DRAWY;

    totalFill = DEFAULT_BAR_AMOUNT;
    currentFill = 0;

    outterWidth = DEFAULT_BAR_WIDTH;
    
    colorOutterR = DEFAULT_OUTTER_R;
    colorOutterG = DEFAULT_OUTTER_G;
    colorOutterB = DEFAULT_OUTTER_B;

    colorInnerR = DEFAULT_INNER_R;
    colorInnerG = DEFAULT_INNER_G;
    colorInnerB = DEFAULT_INNER_B;

    upLeftOutterX = 0;
    upLeftOutterY = 0;
    lowRightOutterX = 0;
    lowRightOutterY = 0;
   
    upLeftInnerX = 0;
    upLeftInnerY = 0;
    lowRightInnerX = 0;
    lowRightInnerY = 0;
}

//Destructor.
TurnTimer::~TurnTimer(){

    //Default is fine.
}

//Sets the rate.
//Pre:  None.
//Post: Sets the rate.
void TurnTimer::setRate(int fillRate){

    this->fillRate = fillRate;
}

//Sets the X draw coordinate.
//Pre:  None.
//Post: None.
void TurnTimer::setDrawX(int drawX){

    this->drawX = drawX;
}

//Sets the Y draw coordinate.
//Pre:  None.
//Post: None.
void TurnTimer::setDrawY(int drawY){

    this->drawY = drawY;
}

//Returns outterWidth.
int TurnTimer::getOutterWidth() const{

    return outterWidth;
}

//Determines the draw points based on the drawX and drawY. 
//Pre:  None.
//Post: Calculates the inner and outter rectangles based on the 
//      initial drawX and drawY.
void TurnTimer::calculateDrawPoints(){

    upLeftOutterX = drawX;
    upLeftOutterY = drawY;
    lowRightOutterX = drawX + DEFAULT_BAR_WIDTH;
    lowRightOutterY = drawY + DEFAULT_BAR_HEIGHT;
   
    upLeftInnerX = upLeftOutterX + INNER_OFFSET;
    upLeftInnerY = upLeftOutterY + INNER_OFFSET;
    lowRightInnerX = upLeftInnerX;
    lowRightInnerY = lowRightOutterY - INNER_OFFSET;
}

//Draws the TurnTimer to the screen.
//Pre:  None.
//Post: Draws the inner and the outter ractangle to the screen.
void TurnTimer::draw(){

    //Outter rectangle.
    al_draw_filled_rectangle(
        upLeftOutterX , upLeftOutterY ,         //Upper left point.
        lowRightOutterX , lowRightOutterY ,     //Lower right point.
        al_map_rgb(colorOutterR, colorOutterG, colorOutterB));

    //Inner rectangle
    al_draw_filled_rectangle(
        upLeftInnerX , upLeftInnerY ,                     //Upper left point.
        (lowRightInnerX + currentFill) , lowRightInnerY , //Lower right point.
        al_map_rgb( colorInnerR , colorInnerG , colorInnerB ));
}

//Increase the current fill by the fillRate.
//Pre:  None.
//Post: Increases the currentFill by the fillRate.
void TurnTimer::updateCurrentFill(){

    currentFill += fillRate;
}

//Checks if the fill bar is full.
//Pre:  None.
//Post: Checks if currentFill is greater than or equal to totalFill.
//      Returns true if they are equal otherwise returns false.
bool TurnTimer::innerBarIsFull(){

    if(currentFill >= totalFill)
        return true;

    else return false;
}

//Resets currentFill.
//Pre:  None.
//Post: Sets currentFill to 0.
void TurnTimer::resetCurrentFill(){

    currentFill = 0;
}