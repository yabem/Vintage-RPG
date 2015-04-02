//Changes the I_Creature's image.

#pragma once
#include "I_Animation.h"
#include "I_Creature.h"

class ChangeCreatureImage : public I_Animation{

private:

    I_Creature *i_Creature;
    ALLEGRO_BITMAP *image;

public:

    ChangeCreatureImage(I_Creature *i_Creature , ALLEGRO_BITMAP *image);
    virtual ~ChangeCreatureImage();
    virtual bool play();
};