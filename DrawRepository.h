//Used for storing Animations and Cutscenes that will be 
//drawn to the screen.

#pragma once
#include <queue>
#include "Cutscene.h"
#include "BattleManager.h"
class Animation;

class DrawRepository{

private:

    std::queue<Cutscene*> cutscenes;     //Stores the Cutscenes that will be played.
    std::queue<Animation*> animations;   //Stores the animations to be played.
    BattleManager *battleManager;       //Used to delete dead enemies.

public:

    //Constructor.
    DrawRepository();

    //Loads the battleManager.
    void loadBattleManager(BattleManager *battleManager);

    //Loads a single Cutscene.
    bool loadCutscene(Cutscene *cutscene);

    //Plays all the loaded Cutscenes.
    void playCutscenes();

    //Checks if there are any remaining animations.
    bool animationsEmpty();

    //Loads a single Animation.
    bool loadAnimation(Animation *animation);

    //Plays all the loaded Animations.
    void playAllAnimations();
};