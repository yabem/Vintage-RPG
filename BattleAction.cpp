#include "BattleAction.h"

//Default constructor.
BattleAction::BattleAction(){


}

void BattleAction::loadMenuToManager(){

    //battleManager->pau
    //battleManager->loadMenu(i_Creature->createMenu());
}

            /*xxx old
            //Default constructor.
            BattleAction::BattleAction(){

                this->initiator = NULL;
                this->receiver = NULL;
                this->action = "";
            }

            //Parameter constructor.
            BattleAction::BattleAction(Character *initiator , Character *receiver ,
                std::string action){

                this->initiator = initiator;
                this->receiver = receiver;
                this->action = action;
            }

            //Destructor.
            BattleAction::~BattleAction(){

                //Only call destroy animations if the vector has elements.
                if(!animations.empty())
                    destroyAnimations();
            }

            //Adds an Animation to the BattleAction.
            void BattleAction::addAnimation(Animation *animation){

                animations.push_back(animation);
            }

            //Deallocates all Animation objects.
            void BattleAction::destroyAnimations(){

                vector<Animation*>::iterator iter;

                //Delete the allocated memory for the animations.
                while(iter != animations.end()){

                    delete *iter;
                    iter++;
                }

                //Delete all the animations.
                animations.clear();
            }
            */