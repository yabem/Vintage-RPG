#include "Menu.h"

//Defaut constructor.
Menu::Menu(ALLEGRO_FONT *font){

    numOptions = 0;
    longestOption = 0;
    currSelection = 0;
    this->font = font;
    
    this->sx = DEFAULT_SX;  //X draw location.
    this->sy = DEFAULT_SY;  //y draw location.
    this->dx = 0;
    this->dy = 0;

    tr = 255 ; tg = 255 ; tb = 255; //Hues for the text color.
    rr = 0 ; rg = 0 ; rb = 200;     //Hues for rectangle color.
    br = 255 ; bg = 255 ; bb = 255; //Hues for border color.
    bWid = 2;           //Width of the border around the text box.
}

//Constructor with string input.
Menu::Menu(std::string text , ALLEGRO_FONT *font){

    //Checks if input is empty.
    if(text == "")
        return;

    numOptions = 0;
    longestOption = 0;
    currSelection = 0;

    this->text = text;  
    this->font = font;

    w = 0;
    h = 0;

    this->sx = 0;           //X draw location.
    this->sy = 0;           //y draw location.
    this->dx = 0;
    this->dy = 0;

    tr = 255 ; tg = 255 ; tb = 255; //Hues for the text color.
    rr = 0 ; rg = 0 ; rb = 200;     //Hues for rectangle color.
    br = 255 ; bg = 255 ; bb = 255; //Hues for border color.
    bWid = 2;           //Width of the border around the text box.
}

//Loads text into the TextBox. The options are deliminated by a ;.
void Menu::loadText(std::string text){

    this->text = text;
    formatText();           //Put the text into vectors.
    this->dy = formattedText.size() * FONT_HEIGHT;
}

//Destructor.
Menu::~Menu(){

    //Deallocate options.
    destroyMenu();
}

//Deallocate the memory from the menu.
void Menu::destroyMenu(){

    vector<Option*>::iterator optionIter = options.begin();

    while(optionIter != options.end()){

        //Deallocate subMenu.
        if((*optionIter)->subMenu != NULL)
            (*optionIter)->subMenu->destroyMenu(); 

        optionIter++;
    }

    //Deallocate Menu.
    destroyMenuHelper();
}

//Deallocate the memory from the menu.
void Menu::destroyMenuHelper(){

    //Only delete if there's a menu.
    if(this != NULL){

        vector<Option*>::iterator optionIter = options.begin();

        while(optionIter != options.end()){

            delete *optionIter;
            optionIter++;
        }
    }

    this->options.clear();

    return;
}

//Find number of rows based on length of text.
void Menu::formatText(){

    std::string::iterator stringIter = text.begin();

    formatTextHelper(text , stringIter);
}

//Find number of rows based on length of text.
void Menu::formatTextHelper(std::string text , 
    std::string::iterator &stringIter){

    int countChars = 0;

    //Storage for strings until the , delimiter is reached.
    std::string tempText;    
    bool done = false;

    //Stopping point check.
    if(*stringIter == ';' || text == "")
        return;

    else{

        currSelection = 0;

        while(!done){

            //End of the option.
            if(*stringIter == ',' || *stringIter == ';' || *stringIter == '|'){

                numOptions++;

                //Create Option and add it to the options vector.
                Option *option = new Option;
                option->Name = tempText;
                option->subMenu = NULL;
                options.push_back(option);

                int lengthOfNewOption = al_get_text_width(font ,
                    (char*)tempText.c_str());

                //Replace longest option as necessary.
                if(lengthOfNewOption > longestOption)
                    longestOption = lengthOfNewOption;

                tempText.clear();
                countChars = 0;
   
                //End of current menu's options.
                if(*stringIter == ';'){
                    done = true;
                    stringIter++;
                }

                //Create a subMenu.
                else if(*stringIter == '|'){

                    stringIter++;
                    
                    Menu *additionalSubMenu = new Menu(font);
                    option->subMenu = additionalSubMenu;

                    additionalSubMenu->formatTextHelper(text , stringIter);
                }

                else stringIter++;
            }

            else{
                //Increase number of chars for this line.
                countChars++;

                //Add the char to the temp line.
                tempText.push_back(*stringIter);

                //Increment string iterator.
                stringIter++;
            }
        }
    }

    formatMenu();
}

//Use the text and format the menu.
void Menu::formatMenu(){

    w = longestOption;// * FONT_WIDTH;
    h = options.size() * FONT_HEIGHT;

    recalculateMenuEndCoordinates();

    calculateSelectorCoords();
    optionIter = options.begin();
}

//Calculates end coords based off of start coords.
void Menu::recalculateMenuEndCoordinates(){

    this->dx = sx + w + MENU_WIDTH_BUFFER;
    this->dy = sy + h;
}

//Returns true if the selection has a subMenu. Returns false if
//there isn't a subMenu.
bool Menu::currSelectionHasSubMenu(){

    if((*optionIter)->subMenu == NULL)
        return false;

    else return true;
}

//Moves the option based on the input key.
bool Menu::moveSelection(int key){

    bool returnValue = false;

    //Checks if the input is UP and the iterator is not already at 
    //the beginning of the list.
    if(key == UP && optionIter != options.begin()){
        optionIter--;
        returnValue = true;
        currSelection--;
        calculateSelectorCoords();
    }

    //Checks if the input is DOWN and the iterator is not already
    //at the end of the list.
    else if(key == DOWN && (optionIter + 1) != options.end()){
        optionIter++;
        returnValue = true;
        currSelection++;
        calculateSelectorCoords();
    }

    return false;
}

//Moves the current selection to the beginning of the list.
//Pre:  None.
//Post: Moves the currentSelection and the optionIter to the
//      beginning of the list.
void Menu::moveCurrSelectionToBegin(){

    currSelection = 0;
    moveOptionIterToBegin();
}

//Move optionIter to the beginning of the list.
//Pre:  None.
//Post: Moves the optionIter to the beginning of the list.
void Menu::moveOptionIterToBegin(){

    optionIter = options.begin();
}

//Returns the current selection. If options is empty returns "".
//Unused at the moment.
Menu* Menu::getSelectionsSubMenu(){
    
    if(currSelection < 0)
        return NULL;

    else{

        return (*optionIter)->subMenu;
    }
}

//Returns the X value for the middle of the selection.
int Menu::getCurrSelX() const{

    return sx;
}

//Returns the Y value for the middle of the selection.
int Menu::getCurrSelY() const{

    return sy + (FONT_HEIGHT) + (FONT_HEIGHT * currSelection)
        - (FONT_HEIGHT / 2);
}

//Draws the text box to the screen. Draws nothing if there aren't
//any options in the menu.
void Menu::draw(){

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
        
        al_draw_textf(font,                 //Font.
            al_map_rgb(tr , tg , tb),       //Color.
            sx + HALF_MENU_WIDTH_BUFFER,                //X draw location.
            sy + FONT_HEIGHT * i ,          //Y draw location.
            0,                              //Flag. 
            (*selecIter)->Name.c_str());    //Text.
    }
    
    //Calculate then draw the selector.
    calculateSelectorCoords();
    drawSelector();
}

//Determines the selector draw locations based off of the currently
//selected option.
void Menu::calculateSelectorCoords(){

    midRightX = getCurrSelX();                      //Middle.
    midRightY = getCurrSelY();                      //Middle.
    upLeftX = midRightX - SELECTOR_WIDTH;           //Upper corner.
    upLeftY = midRightY - (SELECTOR_HEIGHT / 2);    //Upper corner.
    lowLeftX = midRightX - SELECTOR_WIDTH;          //Lower corner.
    lowLeftY = midRightY + (SELECTOR_HEIGHT / 2);   //Lower corner.
}

//Draws the selector to the screen. Draws nothing if there aren't
//any options in the menu.
void Menu::drawSelector(){

    if(options.empty())
        return;

    al_draw_filled_triangle(
        upLeftX , upLeftY,          //Upper left point
        midRightX , midRightY,      //Middle right point
        lowLeftX , lowLeftY,        //Lower left point
        al_map_rgb(150, 150, 150));
                       
    al_draw_triangle(
        upLeftX , upLeftY,          //Upper left point
        midRightX , midRightY,      //Middle right point
        lowLeftX , lowLeftY,        //Lower left point
        al_map_rgb(255, 255, 255) , 2);
}

//Sets subMenus draw location to start at the menu's selection midpoint
//to create a cascading effect when traversing menus.
void Menu::setDrawToPrevSelection(Menu *prevMenu){

    this->sx = prevMenu->midRightX;           //X draw location.
    this->sy = prevMenu->midRightY;           //y draw location.

    recalculateMenuEndCoordinates();
    calculateSelectorCoords();
}

//Returns the name of the selected Option.
//Pre:  None.
//Post: Returns the name of the Option that is selected.
//      The name is returned as a std::string. The function is
//      recursive because it continues down the Menu checking every
//      subMenu until it reaches NULL. Once it reaches a subMenu that
//      is NULL, name of the Menu item is returned.
std::string Menu::getSelectionName() const{

    if(this->options[currSelection]->subMenu == NULL)
        return options[currSelection]->Name;

    else return this->options[currSelection]->subMenu->getSelectionName();
}

//Returns the name of the selected Option.
//Post: Returns the name of the current menu's selection.
std::string Menu::getCurrSelectionName() const{

    if(this == NULL)
        return "Error, the Menu is empty.";

    else return this->options[currSelection]->Name;
}

//Returns the width of the menu.
//Pre:  None.
//Post: Returns w.
int Menu::getW() const{

    return w;
}

//Returns the height of the menu.
//Pre:  None.
//Post: Returns w.
int Menu::getH() const{

    return h;
}

//Set menu draw location to character.
//Pre:  None.
//Post: Sets the draw location of the left of the character
//      location. The right side of the menu will meet the 
//      left side of the character.
void Menu::setMenuToLeftOfCharacter(I_Creature *i_Creature){

    //Max width of the base menu.
    int maxMenuWidth = w + MENU_WIDTH_BUFFER;

    //The character's x and y coordinate.
    int charX = i_Creature->getX();
    int charY = i_Creature->getY();
    
    //New start and end coordinates for the menu.
    setSX(charX - maxMenuWidth);
    setSY(charY);
    recalculateMenuEndCoordinates();
}

//Sets sx.
//Pre:  None.
//Post: Sets sx to the passed in value.
void Menu::setSX(int sx){

    this->sx = sx;
}

//Sets sy.
//Pre:  None.
//Post: Sets sy to the passed in value.
void Menu::setSY(int sy){

    this->sy = sy;
}

//Sets dx.
//Pre:  None.
//Post: Sets dx to the passed in value.
void Menu::setDX(int dx){
    
    this->dx = dx;
}

//Sets dy.
//Pre:  None.
//Post: Sets dy to the passed in value.
void Menu::setDY(int dy){
    
    this->dy = dy;
}