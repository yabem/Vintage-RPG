#include "TransferAnimations.h"


//Transfers all the animations from the source to the destination.
void TransferAnimations::transferAnimations(std::queue<I_Animation*> source , 
    std::queue<I_Animation*> destination){

    while(!source.empty()){
                                
        destination.push(source.front());
        source.pop();
    }
}
