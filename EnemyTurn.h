#include "I_Event.h"
#include "I_AI.h"
#include "DrawRepository.h"

class EnemyTurn : public I_Event{

private:
    
    I_AI *i_AI;
    DrawRepository *drawRepository;
    bool isExecuted;    //Flag if the logic has been executed.

public:

    EnemyTurn(I_AI *i_AI , DrawRepository *drawRepository);
    virtual ~EnemyTurn();
    virtual bool execute();
};