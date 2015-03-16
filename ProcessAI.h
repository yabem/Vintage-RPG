//Processes an enemy's AI.

#include "I_Event.h"
#include "I_AI.h"
#include "DrawRepository.h"

class ProcessAI : public I_Event{

private:

    //The AI to execute.
    I_AI *i_AI;

    //Determines the end of the event.
    DrawRepository *drawRepository;

    bool isExecuted;

public:

    //Constructor.
    ProcessAI(I_AI *i_AI , DrawRepository *drawRepository);

    //Destructor.
    ~ProcessAI();
    
    //Executes the AI.
    virtual bool execute();
};