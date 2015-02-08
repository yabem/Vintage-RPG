#pragma once

#include <string>
#include "BattleAction.h"
#include "MovingImage.h"
#include "MovingText.h"

class GenerateAction{

    GenerateAction();   //Default constructor.
    void genAction(int action);

private:
    
    //void hash(int action);      //String used for hasing.
    BattleAction *battleAction; //Components of the action to be generated.

    void attack();  //The initiator attacks the receiver.
};