#pragma once
#include <string>

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

    int baseDef;    //Character's base DEF before augments.
    int ttlDef;     //Character's total DEF after augments.

public:

    //Constructor.
    Stats();
    Stats(int level , int baseHP , int baseMP , int baseAtk , int baseDef);

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
    int getTtlAtk() const;     //Returns ttlAtk.

    int getBaseDef() const;    //Returns baseDef.
    int getTtlDef() const;     //Returns ttlDef.

    void addToCurrHP(int amount);        //Adds to currHP.
};