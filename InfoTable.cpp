#include "InfoTable.h"

//Constuctor.
InfoTable::InfoTable(std::string text , ALLEGRO_FONT *font) :
    Menu(text , font){

}

//Destructor.
InfoTable::~InfoTable(){

}

//Draws the InfoTable to the screen.
void InfoTable::draw(){

    //If there are no options in the Menu, don't draw anything.
    if(options.empty())
        return;

    //Draws the background and the border for the TextBox.
    al_draw_filled_rectangle(sx , sy , dx , dy , al_map_rgb(rr , rg , rb));
    al_draw_rectangle(sx , sy , dx , dy , al_map_rgb(br , bg , bb) , bWid);
    
    //Create iterator.
    vector<Option*>::iterator selecIter = options.begin();

    //Draw the text to the screen.
    for(int i = 0 ; selecIter != options.end() ; selecIter++ , i++){
        

        DrawTextWithBorder::drawTextWithBorder(
            font,                           //Font.
            tr , tg , tb,                   //Color.
            sx + HALF_MENU_WIDTH_BUFFER,    //X draw location.
            sy + FONT_HEIGHT * i ,          //Y draw location. 
            (*selecIter)->Name.c_str());    //Text.
    }
}