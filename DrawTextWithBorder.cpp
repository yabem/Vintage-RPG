#include "DrawTextWithBorder.h"

void DrawTextWithBorder::drawTextWithBorder(
    ALLEGRO_FONT *font ,
    int red , int green , int blue ,
    float drawX ,
    float drawY ,
    std::string text){  
        
    //Background
    al_draw_textf(font, al_map_rgb(BLACK_R, BLACK_G, BLACK_B),  
        drawX - 1, drawY, 0, text.c_str());  

    al_draw_textf(font, al_map_rgb(BLACK_R, BLACK_G, BLACK_B),  
        drawX + 1, drawY, 0, text.c_str()); 

    al_draw_textf(font, al_map_rgb(BLACK_R, BLACK_G, BLACK_B),  
        drawX, drawY - 1, 0, text.c_str()); 

    al_draw_textf(font, al_map_rgb(BLACK_R, BLACK_G, BLACK_B),  
        drawX, drawY + 1, 0, text.c_str()); 

    //Foreground
    al_draw_textf(font, al_map_rgb(red, green, blue),
        drawX, drawY, 0, text.c_str());
}