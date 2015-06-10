#pragma once
#include "TextBox.h"
#include "Character.h"
#include "I_Creature.h"
#include "I_InfoBox.h"

const int MENU_WIDTH_BUFFER = 20;
const int HALF_MENU_WIDTH_BUFFER = MENU_WIDTH_BUFFER / 2;
const int SELECTOR_WIDTH = 20;  //Width for the cursor selector.
const int SELECTOR_HEIGHT = 18;  //Height for the cursor selector.
const int DEFAULT_SX = 200; //Starting x for formatMenu()
const int DEFAULT_SY = 200; //Starting y for formatMenu()

class Option;

class Menu: public I_InfoBox {

protected:

    struct Option{

        std::string Name;
        Menu *subMenu;
    };

    std::vector<Option*> options;  //Vector of Options for the menu.
    std::vector<Option*>::iterator optionIter;    //Iterator for the options. 

    int numOptions;     //Number options in the menu.
    int longestOption;  //Number of characters in the longest option.
    int h;              //Height of the menu.
    int w;              //Width of the menu.
    int currSelection;  //Location value of the selected option.

    //Selector information.
    int upLeftX;            //Upper corner.
    int upLeftY;            //Upper corner.
    int lowLeftX;           //Lower corner.
    int lowLeftY;           //Lower corner.
    int midRightX;          //Middle.
    int midRightY;          //Middle.

    std::string text;   //Unformatted text that will be displayed.
    std::vector<std::string> formattedText;   //One full box of text.
    ALLEGRO_FONT *font;             //Font for the text.
    int sx , dx;        //X draw locations.
    int sy , dy;        //Y draw locations.
    int tr , tg , tb;   //Hues for the text color.
    int rr , rg , rb;   //Hues for rectactle color.
    int br , bg , bb;   //Hues for border color.
    int bWid;           //Width of the border.

    void formatMenu();  //Formats the text into the menu and submenus.

public:

    Menu(ALLEGRO_FONT *font);                       //Default constructor.
    Menu(std::string text , ALLEGRO_FONT *font);    //Constructor with string input.
    virtual ~Menu();                //Destructor.
    void destroyMenu();             //Deallocate a Menu and all subMenus.
    void destroyMenuHelper();       //Deallocate a Menu.
    virtual void loadText(std::string text);   //Loads text into the TextBox.
    virtual void formatText();      //Find number of rows based on length of text.

    bool moveSelection(int key);    //Moves the option based on the input key.

    //Moves the current selection to the beginning of the list.
    void moveCurrSelectionToBegin();

    //Move optionIter to the beginning of the list.
    void moveOptionIterToBegin();

    Menu* getSelectionsSubMenu();   //Returns the subMenu of the currently selection Option.
    int getCurrSelX() const;        //Returns the X value for the middle of the selection.
    int getCurrSelY() const;        //Returns the Y value for the middle of the selection.
    virtual void draw();            //Draws the menu and the selector.

    void drawSelector();    //Draws the Selector.

    //Sets the Menu's start draw location to the prevMenu's selection midpoint
    //to create a cascading effect when traversing menus.
    void setDrawToPrevSelection(Menu *prevMenu);

    //Recursive function to populate menus.
    void formatTextHelper(std::string text , std::string::iterator &stringIter);

    //Returns true if the selection has a subMenu.
    bool currSelectionHasSubMenu(); 

    //Calculates end coords based off of start coords.
    void calculateMenuEndCoordinates(); 

    //Determines the selector draw locations based off of the current option.
    void calculateSelectorCoords(); 

    //Returns the name of the selected Option.
    std::string getSelectionName() const;

    //Returns the name of the selected Option.
    std::string getCurrSelectionName() const;

    //Returns the width of the menu.
    int getW() const;

    //Returns the height of the menu.
    int getH() const;

    //Returns the start x for the menu.
    int getSX() const;

    //Returns the destination x for the menu.
    int getDX() const;

    //Place Menu to left of the Character.
    void setMenuToLeftOfCharacter(I_Creature *i_Creature);

    void setSX(int sx);     //Sets sx.
    void setSY(int sy);     //Sets sy.
    void setDX(int dx);     //Sets dx.
    void setDY(int dy);     //Sets dy.
};