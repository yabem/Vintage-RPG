//Interface for tables that store information about Characters.

class I_CharacterValuesList{

private:

public:

    I_CharacterValuesList();
    virtual ~I_CharacterValuesList();
    virtual int getValue(int position) = 0;
};