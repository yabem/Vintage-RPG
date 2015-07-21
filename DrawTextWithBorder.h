//Draws text and adds a black border background.

#pragma once
#include <allegro5\allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <string>
#include "FontColorSettings.h"

namespace DrawTextWithBorder{

    void drawTextWithBorder(ALLEGRO_FONT *font ,  //Font.
            int red , int green , int blue ,   //Color.
            float drawX ,             //X draw location.
            float drawY ,       //Y draw location.
            std::string text);               //Text.);
};