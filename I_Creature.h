//The interface for creatures.

#pragma once
#include <string>

class I_Creature{

private:

public:
    virtual ~I_Creature();
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual int getH() const = 0;
    virtual std::string getAbilities();
    virtual bool isPlayable() const; 

    virtual void executeRandomAttack() = 0;
};