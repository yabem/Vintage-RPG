//The Layer class holds information to draw a map based off of a bitmap
//and a layout. The layer is drawn using the values in the layout in
//combination with the bitmap.

#include "Layer.h"

//Constructor.
Layer::Layer(ALLEGRO_BITMAP *bmap ,
    int numRows , int numCols , int *layout , int laySize){

    this->bmap = bmap; 
    this->bMapRows = al_get_bitmap_height(bmap) / TILE_SIZE;
    this->bMapCols = al_get_bitmap_width(bmap) / TILE_SIZE;
    this->tw = TILE_SIZE;
    this->th = TILE_SIZE;
    this->dx = 0;
    this->dy = 0;
    this->numRows = numRows;
    this->numCols = numCols;
    this->layout = layout;
}

//Destructor.
Layer::~Layer(){

    //Default destructor is fine.
}

//Copy constructor.
Layer::Layer(const Layer &rhs){

    //Default copy is fine.
}

//Operator= overload.
const Layer& Layer::operator=(const Layer &rhs){

    //Shallow copy is fine.
    return *this;   
}

//Draw the layer to the buffer.
void Layer::draw(){

    int row = 0 , col = 0;

    //Loop through each value in the layout.
    for(int r = 0 , loc = 0 ; r < numRows ; r++){
        for(int c = 0 ; c < numCols ; c++ , loc++){

            //Only print if a positive integer.
            if(layout[loc] > 0){
             
                //Column is the remainder after dividing by the bMap columns.
                col = (layout[loc] - 1) % bMapCols; 

                //Row is the number of times the layout value is divisible by the column.
                row = (layout[loc] - 1) / bMapCols; 
                
                //Draw to the buffer.
                al_draw_bitmap_region(
                    bmap , col * tw, row * th,    //Location from on bitmap.
                    tw , th ,                         //Width and height of tile.
                    (c * tw) + dx, (r * th) + dy , 0); //Draw to location.
            }        
        }
    }  
}

//Add amount to DX.
void Layer::addToDX(int amt){

    dx += amt;
}

//Add amount to DY.
void Layer::addToDY(int amt){

    dy += amt;
}

//Set DX to input.
void Layer::setDX(int x){

    this->dx = x;
}

//Set DY to input.
void Layer::setDY(int y){

    this->dy = y;
}

//Return DX value.
int Layer::getDX() const{

    return dx;
}

//Return DY value.
int Layer::getDY() const{

    return dy;
}

//Return total width in pixels.
int Layer::getW() const{

    return numCols * tw;
}

//Return total height in pixels.
int Layer::getH() const{

    return numRows * th;
}

//Return TW value.
int Layer::getTW() const{

    return tw;
}

//Return TH value.
int Layer::getTH() const{

    return th;
}

//Return the value for index within the layout.
int Layer::getLayoutVal(int index) const{
    
    if(index < 0)
        return -99;

    else return layout[index];
}

//Return the number of rows.
int Layer::getNumRows() const{

    return numRows;
}

//Return the number of cols.
int Layer::getNumCols() const{

    return numCols;
}