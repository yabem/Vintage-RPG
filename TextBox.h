#pragma once
#include <allegro5\allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <string>
#include "Enums.h"
#include <allegro5/allegro_font.h>
#include <vector>

class TextBox{

protected:
    int sx , dx;        //X draw locations.
    int sy , dy;        //Y draw locations.
    int tr , tg , tb;   //Hues for the text color.
    int rr , rg , rb;   //Hues for rectactle color.
    int br , bg , bb;   //Hues for border color.
    int bWid;           //Width of the border.
    int rows;           //Number of text rows.
    std::string text;   //Unformatted text that will be displayed.
    vector<string> formattedText;   //One full box of text.
    vector<vector<string> > fullText;  //Vector of full boxes of text.
    ALLEGRO_FONT *font;             //Font for the text.

public:

    TextBox();                    //Default constructor.
    TextBox(std::string text);    //Constructor.
    virtual ~TextBox();
    virtual void loadText(std::string text);   //Loads text into the TextBox.
    virtual void formatText();     //Find number of rows based on length of text.
    virtual void draw();            //Draws that TextBox to the screen.
};