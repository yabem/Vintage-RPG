#pragma once
#include "TextBox.h"

const int SELECTOR_WIDTH = 20;  //Width for the cursor selector.
const int SELECTOR_HEIGHT = 18;  //Height for the cursor selector.

class Option;

class Menu: public TextBox {

public:

    Menu();                     //Default constructor.
    Menu(std::string text);     //Constructor with string input.
    //Menu(vector<vector<std::string> > selections);     //Constructor with a
                                    //vector of vector of strings as input.
    ~Menu();                        //Destructor.
    void destroyMenu();             //Deallocate a Menu and all subMenus.
    void destroyMenuHelper();       //Deallocate a Menu.
    virtual void loadText(std::string text);   //Loads text into the TextBox.
    virtual void formatText();      //Find number of rows based on length of text.
    bool moveSelection(int key);    //Moves the option based on the input key.
    //std::string getSelection();     //Returns the current selection.
    Menu* getSelectionsSubMenu();    //Returns the subMenu of the currently selection Option.
    int getCurrSelX() const;        //Returns the X value for the middle of the selection.
    int getCurrSelY() const;        //Returns the Y value for the middle of the selection.
    virtual void draw();            //Draws the menu and the selector.

    void formatMenu();  //Formats the text into the menu and submenus.

//private:

    struct Option{

        std::string Name;
        Menu *subMenu;
    };

    vector<Option*> options;  //Vector of Options for the menu.

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
    void drawSelector();    //Draws the Selector.

    //Sets the Menu's start draw location to the prevMenu's selection midpoint
    //to create a cascading effect when traversing menus.
    void setDrawToPrevSelection(Menu *prevMenu);

    //Recursive function to populate menus.
    void formatTextHelper(std::string text , std::string::iterator &stringIter);

    bool currSelectionHasSubMenu(); //Returns true if the selection has a subMenu.

    void Menu::calculateSelectorCoords(); //Determines the selector draw 
                                          //locations based off of the 
                                          //current option.

    //vector<std::string>::iterator stringIter;    //Iterator for the options.   
    vector<Option*>::iterator optionIter;    //Iterator for the options.   

};