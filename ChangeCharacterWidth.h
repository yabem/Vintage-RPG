//Changes the Character's width.

#pragma once
#include "I_Animation.h"
#include "Character.h"

class ChangeCharacterWidth : public I_Animation{

private:

    Character *character;
    int width;

public:

    ChangeCharacterWidth(Character *character, int width);
    virtual ~ChangeCharacterWidth();
    virtual bool play();
};