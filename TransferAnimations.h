//Transfer images from one container to another.

#pragma once
#include <queue>
#include "I_Animation.h"

namespace TransferAnimations{

    //Transfers all the animations from the source to the destination.
    void transferAnimations(std::queue<I_Animation*> source , 
        std::queue<I_Animation*> destination);
};