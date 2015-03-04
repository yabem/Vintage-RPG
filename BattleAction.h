//A BattleAction is a sequence that includes an Animation/s and
//changes character stats.

#pragma once
//#include <vector>
#include "Animation.h"
#include "I_Manager.h"
#include "I_Creature.h"
#include "I_AI.h"

class BattleAction{

private:

    I_Manager *battleManager;   //Used to pause and load menus.
    I_Creature *i_Creature; //The creature.
    I_AI *i_AI; //The AI for the creature.


    /*xxx old
    //Maybe create a factory so that all i have to do is action(player1, enemy1, "attack")

    Character *initiator;   //The Character that starts the action.
    Character *receiver;    //The Character that receives the action.
    std::string action;     //The name of the action to execute.

    //CharacterManipulationStore *characterManipulationStore;    //Uses this to manipulate characters via an action.
    //ActionAnimationsStore *actionAnimationsStore; //Uses this to generate the appropriate animations.

    vector<Animation*> animations;  //List of the animations that will execute in order.
    
    void addAnimation(Animation *animation);    //Adds an Animation to the BattleAction.
    */

public:

    BattleAction(); //Default constructor.
    ~BattleAction();            //Destructor.
    void loadMenuToManager();

    //Parameter constructor
    /* BattleAction(Character *initiator , Character *receiver , std::string action);   

    void destroyAnimations();   //Deallocates all Animation objects.
    void execute();     //Processes the action and generates the string of animations.
    */
};