//Used for storing Animations and Cutscenes that will be 
//drawn to the screen.

#pragma once
#include <queue>
#include "Cutscene.h"
#include "I_Animation.h"
#include "Cursor.h"
#include "I_InfoBox.h"

class DrawRepository{

private:

    //Stores the Cutscenes that will be played.
    std::queue<Cutscene*> cutscenes;    

    //Stores the animations to be played.
    std::queue<I_Animation*> animations; 

    //Used for getting the pressed key.
    I_Manager *gameManager;   

    //Stores the Cursors that are drawn to the screen.
    std::queue<Cursor*> cursors;        

    //Stores I_InfoBoxes to draw to the screen.
    //std::queue<I_InfoBox*> infoBoxes;

public:

    //Constructor.
    DrawRepository();

    //Destructor.
    ~DrawRepository();

    //Loads the GameManager.
    void loadGameManager(I_Manager *gameManager);

    //Loads a single Cutscene.
    bool loadCutscene(Cutscene *cutscene);

    //Plays all the loaded Cutscenes.
    void playCutscenes();

    //Checks if there are any remaining animations.
    bool animationsEmpty();

    //Checks if there are any cutscenes remaining.
    bool cutscenesEmpty();

    //Loads a Cursor.
    void loadCursor(Cursor *cursor);

    //Draws the top cursor.
    void drawTopCursor();

    //Remove the top cursor.
    void removeTopCursor();

    //Loads a single Animation.
    bool loadAnimation(I_Animation *animation);

    //Plays all the loaded Animations.
    bool playAllAnimations();

    /*
    //Loads an InfoBox.
    void loadInfoBox(I_InfoBox *infoBox);

    //Draws the top InfoBox.
    void drawTopInfoBox();
    */
};