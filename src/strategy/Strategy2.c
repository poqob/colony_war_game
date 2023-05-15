#include "Strategy2.h"

// constructor
Strategy2 *newStrategy2()
{
    Strategy2 *this = (Strategy2 *)malloc(sizeof(Strategy2));
    this->super = newAStrategy();
    // attemt super's fight method which is abstract
    this->super->fight = &fightStrategy2;
    // local struct fight method points super's fight method. oop simulate
    this->fight = this->super->fight;

    this->destroy = &destroyStrategy2;
    return this;
}

// the fight(combat) method of Strategy2
int fightStrategy2() { return S2FP; }

// destructor
void destroyStrategy2(Strategy2 *strategy)
{
    if (strategy == NULL)
        return;

    strategy->super->destroy(strategy->super);
    free(strategy);
}