#include "Strategy0.h"

// constructor
Strategy0 *newStrategy0()
{
    Strategy0 *this = (Strategy0 *)malloc(sizeof(Strategy0));
    this->super = newAStrategy();
    // attemt super's fight method which is abstract
    this->super->fight = &fightStrategy0;
    // local struct fight method points super's fight method. oop simulate
    this->fight = this->super->fight;
    this->destroy = &destroyStrategy0;
    return this;
}

// the fight(combat) method of Strategy0
int fightStrategy0() { return S0FP; }

// destructor
void destroyStrategy0(Strategy0 *strategy)
{
    if (strategy == NULL)
        return;

    strategy->super->destroy(strategy->super);
    free(strategy);
}