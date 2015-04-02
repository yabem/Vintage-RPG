//The interface for creatures.

#pragma once
#include <string>

class Stats;
struct ALLEGRO_BITMAP;

class I_Creature{

private:

public:
    virtual ~I_Creature();
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual int getH() const = 0;
    virtual std::string getAbilities();
    virtual bool isPlayable() const; 
    virtual bool isDead();
    virtual Stats* getStats();
    virtual void makeDead();

    virtual void executeRandomAttack() = 0;

    virtual int getXPReward();
    virtual int getMoneyReward();
    virtual int getCurrHP();
    virtual int getTtlHP();
    virtual void setX(int x);   
    virtual void setY(int y);               
    virtual void setImage(ALLEGRO_BITMAP *image);
    virtual bool setFacing(int direction);
};