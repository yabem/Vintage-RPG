#include "FontStore.h"

//Constructor.
FontStore::FontStore(){

}

//Destructor.
FontStore::~FontStore(){

    destroyFontStore();
}

//Destroy font store.
void FontStore::destroyFontStore(){

    std::map<std::string , ALLEGRO_FONT*>::iterator fontIter = fonts.begin();

    while(fontIter != fonts.end()){

        al_destroy_font(fontIter->second);
        fonts.erase(fontIter);
        fontIter = fonts.begin();
    }

    std::map<std::string , ALLEGRO_COLOR*>::iterator colorIter = colors.begin();

    while(colorIter != colors.end()){

        //al_destroy_font(iter->second);
        delete (*colorIter).second;
        colors.erase(colorIter);
        colorIter = colors.begin();
    }
}

//Loads a single font.
//Pre:  None.
//Post: Loads a single font to the fonts map.
void FontStore::loadFont(std::string name , ALLEGRO_FONT *font){

    //Don't add anything if pointer is NULL.
    if(font == NULL || name == "")
        return;

    else fonts.insert(std::pair<std::string , ALLEGRO_FONT*>(name , font));
}

//Loads all the predetermined fonts.
//Pre:  None.
//Post: Loads all the fonts to the fonts map.
void FontStore::loadAllDefaultFonts(){

    loadFont("default" , al_load_font("TTF/arial.ttf" , 18 , 0));
    loadFont("battleFont" , al_load_font("TTF/arial.ttf" , 18 , 0));
    loadFont("shadowFont" , al_load_font("TTF/arial.ttf" , 19 , 0));
}

//Returns the desired font.
//Pre:  None.
//Post: Returns the font based on the string.
ALLEGRO_FONT* FontStore::getFont(std::string fontName){

    if(fontName == "")
        return NULL;

    //Create iterator for testing if the element exists.
    std::map<std::string , ALLEGRO_FONT*>::iterator iter = fonts.begin();

    iter = fonts.find(fontName);

    if(iter == fonts.end()){

        //Element not found, return default image.
        return getFont("default");    
    }

    else return iter->second;
}

//Loads a single color.
//Pre:  None.
//Post: Loads the color to colors.
void FontStore::loadColor(std::string name , ALLEGRO_COLOR *color){

    //Don't add anything if pointer is NULL.
    if(color == NULL || name == "")
        return;

    else colors.insert(std::pair<std::string , ALLEGRO_COLOR*>(name , color));
}

//Loads all the predetermined colors.
void FontStore::loadAllDefaultColors(){

    ALLEGRO_COLOR *magenta = new ALLEGRO_COLOR();
    magenta->r = 255;
    magenta->g = 0;
    magenta->b = 255;

    ALLEGRO_COLOR *white = new ALLEGRO_COLOR();
    white->r = 0;
    white->g = 0;
    white->b = 0;

    ALLEGRO_COLOR *blue = new ALLEGRO_COLOR();
    blue->r = 0;
    blue->g = 0;
    blue->b = 255;

    loadColor("default" , magenta);
    loadColor("white" , white);
    loadColor("blue" , blue);
}

//Returns the desired color.
//Pre:  None.
//Post: Returns the color based off of the string.
ALLEGRO_COLOR* FontStore::getColor(std::string colorName){

    if(colorName == "")
        return NULL;

    //Create iterator for testing if the element exists.
    std::map<std::string , ALLEGRO_COLOR*>::iterator iter = colors.begin();

    iter = colors.find(colorName);

    if(iter == colors.end()){

        //Element not found, return default image.
        return getColor("default");    
    }

    else return iter->second;

}