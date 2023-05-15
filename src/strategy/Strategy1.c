#include "Strategy1.h"
#include "AStrategy.h"
#include <stdlib.h>

// constructor
Strategy1 *newStrategy1()
{
    Strategy1 *this = (Strategy1 *)malloc(sizeof(Strategy1));
    this->super = newAStrategy();
    // attemt super's fight method which is abstract
    this->super->fight = &fightStrategy1;
    // local struct fight method points super's fight method. oop simulate
    this->fight = this->super->fight;

    this->destroy = &destroyStrategy1;
    return this;
}

// the fight(combat) method of Strategy1
int fightStrategy1() { return S1FP; }

// destructor
void destroyStrategy1(Strategy1 *strategy)
{
    if (strategy == NULL)
        return;

    strategy->super->destroy(strategy->super);
    free(strategy);
}