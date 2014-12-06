#include "MovingText.h"

//Constructor.
MovingText::MovingText(ALLEGRO_FONT *font , int w , int h , float ttlFrames , bool rebound){
 
    this->font = font;
    this->w = w;
    this->h = h;
    this->sx = 0;
    this->sy = 0;
    this->dx = 0;
    this->dy = 0;
    this->ex = 0;
    this->ey = 0;
    this->xRate = 0;
    this->yRate = 0;
    this->ttlFrames = ttlFrames;
    this->currFrame = 0;
    this->initialized = false;
    this->rebound = rebound;
}  


//Destructor.
MovingText::~MovingText(){
    
    //Default is fine.
}

//Draws the text animation.
bool MovingText::play(){

    bool result = false;
    currFrame++;            //Increase the frame.
    float direction = 1;    //Direction the text moves.

    //Check if the animation is done.
    if(currFrame == ttlFrames){
        result = true;
        initialized = false;
        currFrame = 0;
    }
    
    else{

        //Switch text direction if the text is set to rebound.
        if(rebound && currFrame > ttlFrames / 2)
            direction *= -1;
        
        dx += xRate * direction;
        dy += yRate * direction;

        //Draw bitmap to the buffer.
        al_draw_textf(font, al_map_rgb(DEFR , DEFG , DEFB), dx , dy , 0, text.c_str());
    }

    return result;
}    

//Initialize the font, start, and end locations.
void MovingText::initialize(std::string text , int sx , int sy , int ex , int ey){

    //Used for ensuring the text goes all the way to the destination.
    float reboundMultiplier = 1;     

    this->text = text;
    this->sx = sx;
    this->sy = sy;
    this->dx = sx;
    this->dy = sy;
    this->ex = ex;
    this->ey = ey;

    //Multiply by two to ensure that the text goes 
    //all the way to the destination before rebounding.
    if(rebound)
        reboundMultiplier = 2;

    this->xRate = ((ex - sx) / ttlFrames) * reboundMultiplier;
    this->yRate = ((ey - sy) / ttlFrames) * reboundMultiplier;

    this->initialized = true;
}