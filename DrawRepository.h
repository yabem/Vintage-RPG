//Used for storing Animations and Cutscenes that will be 
//drawn to the screen.

#pragma once
#include <queue>
#include "Cutscene.h"
#include "Animation.h"

class DrawRepository{

private:

    //Stores the Cutscenes that will be played.
    std::queue<Cutscene*> cutscenes;    

    //Stores the animations to be played.
    std::queue<Animation*> animations; 

    //Used for getting the pressed key.
    I_Manager *gameManager;   

    //Used to delete enemies once animations are done.
    //I_Manager *battleManager;           

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

    //Loads a single Animation.
    bool loadAnimation(Animation *animation);

    //Plays all the loaded Animations.
    bool playAllAnimations();
};