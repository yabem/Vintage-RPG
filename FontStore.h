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

public:

    //Constructor.
    FontStore();

    //Destructor.
    ~FontStore();

    //Loads a single font.
    void loadFont(std::string name , ALLEGRO_FONT *font);

    //Loads all the predetermined fonts.
    void loadAllDefaultFonts();

    //Returns the desired font.
    ALLEGRO_FONT* getFont(std::string fontName);

    //Destroy font store.
    void destroyFontStore();
};