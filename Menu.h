#pragma once
#include "TextBox.h"
#include "Character.h"

const int SELECTOR_WIDTH = 20;  //Width for the cursor selector.
const int SELECTOR_HEIGHT = 18;  //Height for the cursor selector.
const int DEFAULT_SX = 200; //Starting x for formatMenu()
const int DEFAULT_SY = 200; //Starting y for formatMenu()

class Option;

class Menu: public TextBox {

private:

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

public:

    Menu();                         //Default constructor.
    Menu(std::string text);         //Constructor with string input.
    ~Menu();                        //Destructor.
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

    void formatMenu();  //Formats the text into the menu and submenus.

    void drawSelector();    //Draws the Selector.

    //Sets the Menu's start draw location to the prevMenu's selection midpoint
    //to create a cascading effect when traversing menus.
    void setDrawToPrevSelection(Menu *prevMenu);

    //Recursive function to populate menus.
    void formatTextHelper(std::string text , std::string::iterator &stringIter);

    //Returns true if the selection has a subMenu.
    bool currSelectionHasSubMenu(); 

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

    //Place Menu to left of the Character.
    void setMenuToLeftOfCharacter(Character *character);
};