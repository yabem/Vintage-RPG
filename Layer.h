//The Layer class holds information to draw a map based off of a bitmap
//and a layout. The layer is drawn using the values in the layout in
//combination with the bitmap.

#pragma once
#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "mappy_A5.h"
#include "Enums.h"
#include <vector>

class Layer{

private:

    ALLEGRO_BITMAP *bmap;   //Bitmap for the tiles.
    int tw , th;            //Tile width and height.
    int dx , dy;            //Bitmap's drawing starting location.
    int bMapRows ,  bMapCols;   //Bitmap rows and columns.
    int numRows , numCols;  //Total dimensions of map.
    int *layout;            //The map layout expressed as an array of ints.

public:

    //Constructor.
    Layer(ALLEGRO_BITMAP *bmap , int bMapCols , int bMapRows , int tw , int th ,
        int numRows , int numCols , int *layout , int laySize);

    ~Layer();                                           //Destructor.
    Layer(const Layer &rhs);                            //Copy constructor.
    const Layer& Layer::operator=(const Layer &rhs);    //Operator= overload.

    void draw();            //Draw the layer to the buffer.
    void addToDX(int amt);  //Add amount to DX.
    void addToDY(int amt);  //Add amount to DY.
    void setDX(int x);      //Set DX to input.
    void setDY(int y);      //Set DY to input.
    
    int getDX() const;  //Return DX value.
    int getDY()const;   //Return DY value.
    int getW() const;   //Return total width in pixels.
    int getH() const;   //Return total height in pixels.
    int getTW() const;  //Return TW value.
    int getTH() const;  //Return TH value.
    int getLayoutVal(int index) const; //Return the value for index within the layout.
    int getNumRows() const; //Return the number of rows.
    int getNumCols() const; //Return the number of cols.
};