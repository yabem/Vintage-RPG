#include "GenerateAction.h"

GenerateAction::GenerateAction(){



}

/*
void GenerateAction::genAction(std::string action){

    int key = hash(action);

    switch(hash(action)){

    //case hash("attack"):

    default:
    }
}
*/

void GenerateAction::genAction(int action){

    switch(action){

        case ATTACK:
            attack();
            break;

        case BLOCK:
            break;

        case MAGIC:
            break;

        default:
            break;
    }
}

//Preconditions:    The initiator and receiver are valid Characters.
//Postconditions:   The initiator attacks the receiver and the receiver's
//                  hit points are reduced. The animations are added to the
//                  animations vector.
void GenerateAction::attack(){
    
    //Need a way to pull in the BMAPs, maybe make a factory?
    /*
    action = imageStore(ATTACK);
    MovingImage *attack = new MovingImage(action , 34 , 34 , 30); 
    
    
    weaponAttack.initialize(SCREEN_W , 0 , (*gameManager.enemyIter)->getX() , (*gameManager.enemyIter)->getY());
    damage.initialize("10" , (*gameManager.enemyIter)->getX() , (*gameManager.enemyIter)->getY() , (*gameManager.enemyIter)->getX() , (*gameManager.enemyIter)->getY() - 50);
    damageStay.initialize("10" , (*gameManager.enemyIter)->getX() , (*gameManager.enemyIter)->getY() , (*gameManager.enemyIter)->getX() , (*gameManager.enemyIter)->getY());

    (*gameManager.enemyIter)->getStats()->addToCurrHP(-10);
                                    
    animations.push(&weaponAttack);
    animations.push(&damage);
    animations.push(&damageStay);
    */
}  
