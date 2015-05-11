//Falling rain.

#pragma once
#include "FallingImage.h"
#include "ImageStore.h"
#include "FallingImage.h"

class Rain : public FallingImage{

private:

public:

    Rain(ALLEGRO_BITMAP *bmap , float sx , float sy,
        float moveRateX , float moveRateY);

    virtual ~Rain();
    virtual void draw();
};