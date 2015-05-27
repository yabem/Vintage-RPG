//The Tangible class has objects that are independent from the map
//that the character can interact with. The Tangibles have their
//own collision calculations.

#include "Tangible.h"

//Constructor.
Tangible::Tangible(ALLEGRO_BITMAP *image , int sx , int sy){

    this->image = image;
    this->sx = sx;
    this->sy = sy;
    this->dx = sx;
    this->dy = sy;
    this->w = al_get_bitmap_width(image);
    this->h = al_get_bitmap_height(image);
    this->cx = 0;   //not used
    this->cy = 0;   //not used
    this->cw = w;
    this->ch = h;
    this->identifierName = "";
}

Tangible::~Tangible(){

}

//Return SX value.
int Tangible::getSX() const{

    return sx;
}

//Return SY value.
int Tangible::getSY() const{

    return sy;
}

//Return DX value.
int Tangible::getDX() const{

    return dx;
}

//Return DY value.
int Tangible::getDY() const{

    return dy;
}

//Return CX value.
int Tangible::getCX() const{

    return cx;
}

//Return CY value.
int Tangible::getCY() const{

    return cy;
}

//Return CW value.
int Tangible::getCW() const{

    return cw;
}

//Return CH value.
int Tangible::getCH() const{

    return ch;
}

//Return the height.
int Tangible::getH() const{

    return h;
}

//Return the width.
int Tangible::getW() const{

    return w;
}

//Return the identifierName.
std::string Tangible::getIdentifierName(){

    return identifierName;
}

//Sets DX value.
bool Tangible::setDX(int dx){
    
    this->cx -= this->dx - dx;
    this->dx = dx;

    return true;
}

//Return DY value.
bool Tangible::setDY(int dy){

    this->cy -= this->dy - dy;
    this->dy = dy;

    return true;
}

//set the collision width.
void Tangible::setCW(int cw){

    this->cw = cw;
}

//Sets the collision height.
void Tangible::setCH(int ch){

    this->ch = ch;
}

//Add value to DX.
bool Tangible::addToDX(int add){

    this->dx += add;
    return true;
}

//Add value to DY.
bool Tangible::addToDY(int add){

    this->dy += add;
    return true;
}

//Sets the name identifier.
void Tangible::setIdentifierName(std::string identifierName){

    this->identifierName = identifierName;
}

//Draw to the buffer.
void Tangible::draw(){
    
    al_draw_bitmap_region(image , 
        0 , 0 ,             //X and y draw from on bitmap.
        w , h ,             //X and y draw to on bitmap.
        dx , dy , 0);       //X and y draw to on buffer.
}

void Tangible::playCutscene(int pressedKey){

}