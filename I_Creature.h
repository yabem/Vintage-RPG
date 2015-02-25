//The interface for creatures.

#pragma once

class I_Creature{

private:

public:
    virtual ~I_Creature();
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual int getH() const = 0;

    virtual void executeRandomAttack() = 0;
};