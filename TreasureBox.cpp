#include "TreasureBox.h"

//Constructor.
TreasureBox::TreasureBox(){

}

//Destructor.
TreasureBox::~TreasureBox(){

    removeAllRewards();
}

//Adds an Reward to the back of the queue.
//Pre:  The pointer must point to a dynamically allocated Reward.
//Post: Permanently adds the I_Reward to the box.
void TreasureBox::addReward(I_Reward *i_Reward){

    rewards.push(i_Reward);

    addRewardToSummary(i_Reward);
}

//Adds the Reward to the summary.
//Pre:  None.
//Post: Adds all the quantities of the same rewards.
void TreasureBox::addRewardToSummary(I_Reward *i_Reward){

    //Find the Reward if it exists.
    std::map<std::string , int>::iterator summaryIter =
        summaryOfRewards.find(i_Reward->getName());
        
    //Reward does not exist in the summary so add it.
    if(summaryIter == summaryOfRewards.end()){

        summaryOfRewards.insert(std::pair<std::string , int>(
            i_Reward->getName() , i_Reward->getAmount()));
    }
        
    //Reward already exists so add the quantity.
    else (*summaryIter).second += i_Reward->getAmount();
}

//Gets the first reward's names.
//Pre:  None.
//Post: Returns the name of the first reward from the summary.
std::string TreasureBox::getFrontRewardName(){

    if(summaryOfRewards.empty())
        return NULL;

    std::map<std::string , int>::iterator summaryIter = summaryOfRewards.begin();

    return summaryIter->first;
}

//Gets the first reward's amount.
//Pre:  None.
//Post: Returns the amount of the first reward from the summary.
int TreasureBox::getFrontRewardAmount(){

    if(summaryOfRewards.empty())
        return NULL;

    //Find the Reward if it exists.
    std::map<std::string , int>::iterator summaryIter = summaryOfRewards.begin();

    return summaryIter->second;
}

//Removes the first 
void TreasureBox::removeReward(std::string rewardName){

    summaryOfRewards.erase(rewardName);
}

//Removes the oldest reward from the box.
//Pre:  Rewards is not empty.
//Post: Permanently removes the first reward from the queue.
void TreasureBox::removeFrontReward(){

    if(!rewards.empty()){
        
        delete rewards.front();
        rewards.front() = NULL;
        rewards.pop();
    }
}

//Removes all the Rewards in the treasure box.
//Pre:  None.
//Post: Permanently removes all the rewards.
void TreasureBox::removeAllRewards(){

    if(rewards.empty())
        return;

    while(!rewards.empty()){

        delete rewards.front();
        rewards.pop();
    }

    summaryOfRewards.clear();
}

//Returns the number of Rewards in the box.
//Pre:  None.
//Post: Returns the size of the summaryOfRewards.
int TreasureBox::getSize() const{

    return summaryOfRewards.size();
}

//Delivers all the rewards to the player.
void TreasureBox::deliverAllRewards(){

    //std::vector<
    while(!rewards.empty()){

        rewards.front()->deliverToPlayer();
        delete rewards.front();
        rewards.front() = NULL;
        rewards.pop();
    }
}