#include "TransferAnimations.h"


//Transfers all the animations from the source to the destination.
void TransferAnimations::transferAnimations(std::queue<Animation*> source , 
    std::queue<Animation*> destination){

    while(!source.empty()){
                                
        destination.push(source.front());
        source.pop();
    }
}
