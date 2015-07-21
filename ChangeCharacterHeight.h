//Changes the Character's height.

#pragma once
#include "I_Animation.h"
#include "Character.h"

class ChangeCharacterHeight : public I_Animation{

private:

    Character *character;
    int height;

public:

    ChangeCharacterHeight(Character *character, int height);
    virtual ~ChangeCharacterHeight();
    virtual bool play();
};