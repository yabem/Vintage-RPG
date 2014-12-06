#include "Animation.h"
#include <allegro5/allegro_font.h>

//Forward declarations.
struct ALLEGRO_FONT;
//al_draw_textf(font, al_map_rgb(tr , tg , tb), sx + FONTSIZE , sy + FONTHEIGHT * i , 0, it->c_str());


class MovingText: public Animation{

private:

    std::string text;       //Text to draw.
    ALLEGRO_FONT *font;     //
    bool rebound;           //Flag for determining if you want the text to move to the end and back.
                            //True means the text will rebound. False means it will only go one direction.

public:
    
    MovingText(ALLEGRO_FONT *font , int w , int h , float ttlFrames , bool rebound);  //Constructor.
    virtual ~MovingText();  //Destructor.

    virtual bool play();    //Draws the text animation.

    //Initialize the font, start, and end locations.
    virtual void initialize(std::string text , int sx , int sy , int ex , int ey);     
};