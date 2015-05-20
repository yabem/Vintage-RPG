#include "FontStore.h"

//Constructor.
FontStore::FontStore(){

}

//Destructor.
FontStore::~FontStore(){

    destroyFontStore();
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

    loadFont("default" , al_load_font("arial.ttf" , 18 , 0));
    loadFont("battleFont" , al_load_font("arial.ttf" , 18 , 0));
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

//Destroy font store.
void FontStore::destroyFontStore(){

    std::map<std::string , ALLEGRO_FONT*>::iterator iter = fonts.begin();

    while(iter != fonts.end()){

        //al_destroy_font(iter->second);
        fonts.erase(iter);
        iter = fonts.begin();
    }
}