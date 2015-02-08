//Creates animations for battles.

#pragma once
class Character;
#include "Animation.h"
//class Animation;
#include <vector>;

namespace CreateBattleAnimation{

    void CreateAction(Character *initiator , Character *receiver , vector<Animation*> animations);

}