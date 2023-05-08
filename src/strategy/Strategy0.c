#include "Strategy0.h"
#include "AStrategy.h"
#include <stdlib.h>
#include <time.h>

Strategy0 *newStrategy0()
{
    Strategy0 *this = (Strategy0 *)malloc(sizeof(Strategy0));
    this->super = newAStrategy();
    // attemt super's fight method which is abstract
    this->super->fight = &fightStrategy0;
    // local struct fight method points super's fight method. oop simulate
    this->fight = this->super->fight;

    this->destroy = &destroyStrategy0;
}

int fightStrategy0()
{
    srand(time(NULL));    // Seed the random number generator with the current time
    return rand() % 1001; // Generate a random number between 0 and 1000
}

void destroyStrategy0(Strategy0 *strategy)
{
    if (strategy == NULL)
        return;

    strategy->super->destroy(strategy->super);
    free(strategy);
}