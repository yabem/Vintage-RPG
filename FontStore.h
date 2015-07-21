//Stores all the text fonts. The fonts can be retrieved by using the
//the font string name.

#pragma once
#include <map>
#include <string>
#include <allegro5/allegro_font.h>

class FontStore{

private:

    //Map that holds all of the ALLEGRO_FONTs.
    std::map<std::string , ALLEGRO_FONT*> fonts;
    std::map<std::string , ALLEGRO_COLOR*> colors;

public:

    //Constructor.
    FontStore();

    //Destructor.
    ~FontStore();

    //Destroy font store.
    void destroyFontStore();

    //Loads a single font.
    void loadFont(std::string name , ALLEGRO_FONT *font);

    //Loads all the predetermined fonts.
    void loadAllDefaultFonts();

    //Returns the desired font.
    ALLEGRO_FONT* getFont(std::string fontName);

    //Loads a single color.
    void loadColor(std::string name , ALLEGRO_COLOR *color);
    
    //Loads all the predetermined colors.
    void loadAllDefaultColors();

    //Returns the desired color.
    ALLEGRO_COLOR* getColor(std::string colorName);
};