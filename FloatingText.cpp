#include "FloatingText.h"

//Constructor.
FloatingText::FloatingText(ALLEGRO_FONT *font){

    this->font = font;

    this->drawX = 0;
    this->drawY = 0;      
    this->redColor = FLOATING_TEXT_R;
    this->greenColor = FLOATING_TEXT_G; 
    this->blueColor = FLOATING_TEXT_B;   
    this->font = font;     
    this->drawMessage = "";
}

//Destructor.
FloatingText::~FloatingText(){

}

//Set the drawX.
void FloatingText::setDrawX(int drawX){

    this->drawX = drawX;
}

//Set the drawY.
void FloatingText::setDrawY(int drawY){

    this->drawY = drawY;
}

//Set the drawMessage.
void FloatingText::setDrawMessage(std::string drawMessage){

    this->drawMessage = drawMessage;
}

//Puts the text below and in the to the right of the character.
//Pre:  The i_Creature is valid.
//Post: Sets the top left corner of the FloatingText to the bottome left corner
//      of the i_Creature.
void FloatingText::setFloatingTextToTopOfCreature(I_Creature *i_Creature){

    int xStartingPosition = 0;
    int yStartingPosition = 0;

    xStartingPosition = i_Creature->getX();
    yStartingPosition = i_Creature->getY() - DEFAULT_HEALTH_HEIGHT;

    this->setDrawX(xStartingPosition);
    this->setDrawY(yStartingPosition);
}

//Sets the drawMessage to display the I_Creature's current and max hitpoints.
//Pre:  The I_Creature is valid.
//Post: Puts the I_Creature's current hitpoints on the left, then a / then the
//      remaining health on the right.
void FloatingText::setFloatingTextToCreatureHealth(I_Creature *i_Creature){

    //Clear the current message.
    drawMessage.clear();

    char theHitpoints[10];
    
    _itoa_s(i_Creature->getCurrHP() , theHitpoints , 10);

    drawMessage += theHitpoints;
    drawMessage += "/";

    _itoa_s(i_Creature->getTtlHP() , theHitpoints , 10);
                    
    drawMessage += theHitpoints;
}

//Draws to the screen.
//Pre:  None.
//Post: The text is drawn to the screen at the drawX and
//      drawY locations.
void FloatingText::draw(){

    DrawTextWithBorder::drawTextWithBorder(
        font , redColor , greenColor , blueColor
        , drawX , drawY , drawMessage.c_str());
}