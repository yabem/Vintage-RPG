#include "ChangeCreatureImage.h"

//Constructor.
ChangeCreatureImage::ChangeCreatureImage(I_Creature *i_Creature ,
    ALLEGRO_BITMAP *image){

    this->i_Creature = i_Creature;
    this->image = image;
}

//Destructor.
ChangeCreatureImage::~ChangeCreatureImage(){

    //Default destructor is fine.
}

//Changes the I_Creature's image.
//Pre:  None.
//Post: The image is in .png format. Always returns true.
bool ChangeCreatureImage::play(){

    i_Creature->setImage(image);

    return true;
}