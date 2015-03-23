//Holds a list of Rewards that the player has gained after winning
//a battle or completing a quest. The rewards are added and removed in FIFO
//order.

#pragma once
#include <queue>
#include "I_Reward.h"
#include <map>

class TreasureBox{

private:

    //Stores all the rewards.
    std::queue<I_Reward*> rewards;

    //Collection of images.
    std::map<std::string , int> summaryOfRewards;

    //Combines any rewards that are the same.
    void addRewardToSummary(I_Reward *i_Reward);

    //Removes the front reward from rewards.
    void removeFrontReward();

public:

    TreasureBox();
    ~TreasureBox();
    void addReward(I_Reward *i_Reward);

    std::string getFrontRewardName();

    int getFrontRewardAmount();

    void removeReward(std::string rewardName);

    void removeAllRewards();
    int getSize() const;

    //Delivers all the rewards to the player.
    void deliverAllRewards();
};