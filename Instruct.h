//Instructions for when the player starts the game.

#pragma once
#include "Cutscene.h"
#include "TextBox.h"
#include <allegro5/allegro_font.h>
#include <vector>
#include "GameManager.h"
struct ALLEGRO_FONT;

class Instruct: public Cutscene{

private:

    int currentText;
    ALLEGRO_FONT *introFont;
    GameManager *gameManager;
    std::vector<TextBox*> listOfTexts;

public:

    Instruct(ALLEGRO_FONT *font , GameManager *gameManager);
    virtual ~Instruct();
    virtual bool play(const int pressedKey);
};
