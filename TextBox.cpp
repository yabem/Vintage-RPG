#include"TextBox.h"

//Default text box initializer. Makes a text box in the upper 1/2 of the screen.
TextBox::TextBox(ALLEGRO_FONT *font){

    this->text = text;  
    this->font = font;

    this->sx = 1;           //X draw location.
    this->sy = 1;           //y draw location.
    this->dx = SCREEN_W - 1;
    this->dy = 0;

    tr = 255 ; tg = 255 ; tb = 255;  //Hues for the text color.
    rr = 0 ; rg = 0 ; rb = 200;  //Hues for rectactle color.
    br = 255 ; bg = 255 ; bb = 255;  //Hues for border color.
    bWid = 2;               //Width of the border around the text box.
}

//Default text box initializer. Makes a text box in the upper 1/2 of the screen.
TextBox::TextBox(std::string text , ALLEGRO_FONT *font){

    this->text = text;  
    this->font = font;
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
    this->dy = formattedText.size() * FONT_HEIGHT;
}

//Destructor.
TextBox::~TextBox(){

}

//Find the number of rows based on the length of the text.
void TextBox::formatText(){

    std::string textLine = "";
    std::string nextWord = "";

    if(text == ""){

        return;
    }

    else{

        std::string::iterator it = text.begin();

        for(int i = 0 ; it != text.end() ; it++){

            //Add next character to the word.
            nextWord.push_back(*it);

            //End of word or end of passage.
            if(*it == ' ' || (it + 1) == text.end()){

                //Check to see if the next word added will make the text line wider than the allowable on the screen.
                if(((al_get_text_width(font , (char*)textLine.c_str()) + al_get_text_width(font , (char*)nextWord.c_str())) > (SCREEN_W - FONT_WIDTH))){

                    //No more room on the line so add the line to formattedText.
                    formattedText.push_back(textLine);
                    textLine.clear();
                }

                //Add the next word to the line.
                std::string::iterator wordIter = nextWord.begin();
                
                while(wordIter != nextWord.end()){

                    textLine.push_back(*wordIter);
                    wordIter++;
                }

                nextWord.clear();

                //Add the remaining text if it's the end of the passage.
                if((it + 1) == text.end()){

                    formattedText.push_back(textLine);
                    textLine.clear();
                }
            }
        }
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
    
        DrawTextWithBorder::drawTextWithBorder(font, tr , tg , tb ,
            sx + FONT_SIZE , sy + FONT_HEIGHT * i , it->c_str());
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