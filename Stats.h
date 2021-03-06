#pragma once
#include <string>
#include <vector>
#include "Conversion.h"
#include "StatAugment.h"

//Forward declarations.
class string;

class Stats{

protected:

    std::string role;   //Name of the class/job

    int level;      //Character's level.

    int baseHP;     //Character's base HP before augments.
    int ttlHP;      //Character's total HP after augments.
    int currHP;     //Character's remaining HP.

    int baseMP;     //Character's base MP before augments.
    int ttlMP;      //Character's total MP after augments.
    int currMP;     //Character's remaining MP.

    int baseAtk;    //Character's base ATK before augments.
    int ttlAtk;     //Character's total ATK after augments.

    int baseMgc;    //Character's base MGC before augments.
    int ttlMgc;     //Character's total MGC after augments.

    int baseDef;    //Character's base DEF before augments.
    int ttlDef;     //Character's total DEF after augments.

    float speed;    //Character's speed for battle in seconds.

    bool dead;     //Character's status of being alive or dead.

    std::vector<StatAugment*> augments; 

public:

    //Constructor.
    Stats();
    Stats(int level , int baseHP , int baseMP , int baseAtk , int baseMgc , int baseDef ,
        float speed);

    //Destructor.
    virtual ~Stats();

    int getLevel() const;      //Returns character's level.

    int getBaseHP() const;     //Returns BaseHP.
    int getTtlHP() const;      //Returns ttlHP.
    int getCurrHP() const;     //Returns currHP.

    int getBaseMP() const;     //Returns baseMP.
    int getTtlMP() const;      //Returns ttlMP.
    int getCurrMP() const;     //Returns currMP.

    int getBaseAtk() const;    //Returns baseAtk.
    int virtual getTtlAtk() const;     //Returns ttlAtk.

    int getBaseMgc() const;    //Returns baseMgc.
    int virtual getTtlMgc() const;     //Returns ttlMgc.

    int getBaseDef() const;    //Returns baseDef.
    int virtual getTtlDef() const;     //Returns ttlDef.

    float getSpeed() const;     //Returns the speed.
    float getTtlSpeed();  //Returns ttlSpeed.

    void setLevel(int level);
    void setBaseHP(int baseHP);
    void setCurrHP(int currHP);
    void setBaseMP(int baseMP);
    void setBaseAtk(int baseAtk);
    void setBaseMgc(int baseMgc);
    void setBaseDef(int baseDef);
    void setSpeed(float speed);
    virtual void setTtlXPGained(int ttlXPGained) = 0;
    virtual void setToLvlXP(int toLvlXP) = 0;

    virtual int getXPRewardForSlaying() const = 0;
    virtual int getMoneyRewardForSlaying() const = 0;
    virtual std::vector<std::string> getRewards() const = 0;
    virtual void addReward(std::string reward) = 0;

    void setRole(std::string role); //Set's the player's role.
    void addToCurrHP(int amount);        //Adds to currHP.
    virtual void addToTtlXP(int amount) = 0;    //Adds to the Character's total XP.
    virtual bool hasLeveledUp() = 0;    //Checks if the character has leveled up.
    virtual std::string getRole();

    bool isDead();        //Determines if currHP are all gone.
    void makeDead();            //Sets the dead status to true.
    void makeAlive();            //Sets the dead status to false.

    //Retrieves a summary of the pertinent stats to display.
    virtual std::string getSummary();  

    //Loads an augment.
    void loadAugment(
        std::string nameOfAugment , 
        std::string statToAugment ,
        float augmentAmount , 
        float totalDuration);

    void updateAugments();     //Updates Augments.

    //Remove all Augments.
    void removeAugments();
};