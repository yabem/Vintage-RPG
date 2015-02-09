#include"TextBox.h"

//Default text box initializer. Makes a text box in the upper 1/2 of the screen.
TextBox::TextBox(){

    this->text = text;  
    font = al_load_font("arial.ttf" , FONT_SIZE , 0);

    this->sx = 1;           //X draw location.
    this->sy = 1;           //y draw location.
    this->dx = SCREEN_W - 1;
    this->dy = 0;//formattedText.size() * FONTHEIGHT;//SCREEN_H / 2;//

    tr = 255 ; tg = 255 ; tb = 255;  //Hues for the text color.
    rr = 0 ; rg = 0 ; rb = 200;  //Hues for rectactle color.
    br = 255 ; bg = 255 ; bb = 255;  //Hues for border color.
    bWid = 2;               //Width of the border around the text box.
}

//Default text box initializer. Makes a text box in the upper 1/2 of the screen.
TextBox::TextBox(std::string text){

    this->text = text;  
    font = al_load_font("arial.ttf" , FONT_SIZE , 0);
    formatText();           //Put the text into vectors.
    this->sx = 1;           //X draw location.
    this->sy = 1;           //y draw location.
    this->dx = SCREEN_W - 1;
    this->dy = formattedText.size() * FONT_HEIGHT;//SCREEN_H / 2;//

    tr = 255 ; tg = 255 ; tb = 255;  //Hues for the text color.
    rr = 0 ; rg = 0 ; rb = 200;  //Hues for rectactle color.
    br = 255 ; bg = 255 ; bb = 255;  //Hues for border color.
    bWid = 2;   //Width of the border around the text box.
}

//Loads text into a TextBox.
void TextBox::loadText(std::string text){

    this->text = text;
    formatText();           //Put the text into vectors.
    this->dy = formattedText.size() * FONT_HEIGHT;//SCREEN_H / 2;//
}

//Destructor.
TextBox::~TextBox(){

}

//Find the number of rows based on the length of the text.
void TextBox::formatText(){

    int countRows = -1;
    int countChars = 0;
    std::string partial;

    if(text == "")
        return;

    else{

        std::string::iterator it = text.begin();

        for(int i = 0 ; it != text.end() ; it++){
            
            countChars++;
            partial.push_back(*it);

            //Insert full row of text.
            if(countChars > MAXTEXTLENGTH && *it == ' '){
                formattedText.push_back(partial);
                partial.clear();
                countChars = 0;
            }
        }

        //Insert remaining row of text.
        formattedText.push_back(partial);
        partial.clear();

        //Add part to put in an another vector so when there's multiple 
        //screens of text it will cycle through.
    }
}

//Draws the text box to the screen.
void TextBox::draw(){

    //Draws the background and the border for the TextBox.
    al_draw_filled_rectangle(sx , sy , dx , dy , al_map_rgb(rr , rg , rb));
    al_draw_rectangle(sx , sy , dx , dy , al_map_rgb(br , bg , bb) , bWid);

    //Create iterator.
    vector<string>::iterator it = formattedText.begin();
    
    for(int i = 0 ; it != formattedText.end() ; it++ , i++){
        
        al_draw_textf(font,             //Font.
            al_map_rgb(tr , tg , tb),   //Color.
            sx + FONT_SIZE ,             //X draw location.
            sy + FONT_HEIGHT * i ,       //Y draw location.
            0,                          //Flag. 
            it->c_str());               //Text.
    }
}

//Sets sx.
//Pre:  None.
//Post: Sets sx to the passed in value.
void TextBox::setSX(int sx){

    this->sx = sx;
}

//Sets sy.
//Pre:  None.
//Post: Sets sy to the passed in value.
void TextBox::setSY(int sy){

    this->sy = sy;
}

//Sets dx.
//Pre:  None.
//Post: Sets dx to the passed in value.
void TextBox::setDX(int dx){
    
    this->dx = dx;
}

//Sets dy.
//Pre:  None.
//Post: Sets dy to the passed in value.
void TextBox::setDY(int dy){
    
    this->dy = dy;
}