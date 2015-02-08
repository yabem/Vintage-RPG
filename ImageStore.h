//Stores all the bitmaps. The user can query and retrieve
//an image from the store and use it.

#pragma once
#include <vector>
#include <map>
#include "Enums.h"
#include <string>
#include <allegro5/allegro_font.h>  //Used for al_load_bitmap().

class ALLEGRO_BITMAP;

class ImageStore{

private:

    //Collection of images.
    std::map<std::string , ALLEGRO_BITMAP*> images;

public:

    ImageStore();       //Default constructor.
    ~ImageStore();      //Destructor.

    //Load a single bitmap to the store.
    void loadBitMap(std::string name , ALLEGRO_BITMAP *bmap); 
    
    //Loads all of the default bitmaps.
    void loadAllDefaultImages();    

    //Retrieves a pointer to the Bitmap.
    ALLEGRO_BITMAP* getBitMap(std::string bitMapName);  
};