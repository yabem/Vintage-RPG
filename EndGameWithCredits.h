#pragma once
#include "Cutscene.h"
#include "TextBox.h"
#include <allegro5/allegro_font.h>
#include <vector>
#include "GameManager.h"

class EndGameWithCredits : public Cutscene{

private:

    int currentText;
    ALLEGRO_FONT *introFont;
    GameManager *gameManager;
    std::vector<TextBox*> listOfTexts;

public:
    EndGameWithCredits(ALLEGRO_FONT *font , GameManager *gameManager);
    virtual ~EndGameWithCredits();
    virtual bool play(const int pressedKey);
};