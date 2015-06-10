//Displays dialogue to the player.

#pragma once
#include "Cutscene.h"
#include "GameManager.h"

class Dialogue : public Cutscene{

protected:
    int fade;
    int r , g , b;  //Red, green, and blue values for fading.
    ALLEGRO_FONT *introFont;
    TextBox *textBox;
    GameManager *gameManager;

public:

    Dialogue(GameManager *gameManager , ALLEGRO_FONT *introFont);
    ~Dialogue();
    void setText(std::string message);
    bool play(const int pressedKey);
};