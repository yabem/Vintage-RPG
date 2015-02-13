//Transfer images from one container to another.

#pragma once
#include <queue>
#include "Animation.h"

namespace TransferAnimations{

    //Transfers all the animations from the source to the destination.
    void transferAnimations(std::queue<Animation*> source , 
        std::queue<Animation*> destination);


};