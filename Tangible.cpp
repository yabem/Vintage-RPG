//The Tangible class has objects that are independent from the map
//that the character can interact with. The Tangibles have their
//own collision calculations.

#include "Tangible.h"

//Constructor.
Tangible::Tangible(ALLEGRO_BITMAP *bmap , int sx , int sy , int w , int h , int cx , int cy , int cw , int ch){

    this->bmap = bmap;
    this->sx = sx;
    this->sy = sy;
    this->dx = sx;
    this->dy = sy;
    this->w = w;
    this->h = h;
    this->cx = cx;
    this->cy = cy;
    this->cw = cw;
    this->ch = ch;
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

//Return DX value.
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

//Draw to the buffer.
void Tangible::draw(){
    
    al_draw_bitmap_region(bmap , 
        0 , 0 ,             //X and y draw from on bitmap.
        w , h ,             //X and y draw to on bitmap.
        dx , dy , 0);       //X and y draw to on buffer.
}