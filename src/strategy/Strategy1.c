#include "Strategy1.h"
#include "AStrategy.h"
#include <stdlib.h>
#include <time.h>

Strategy1 *newStrategy1()
{
    Strategy1 *this = (Strategy1 *)malloc(sizeof(Strategy1));
    this->super = newAStrategy();
    // attemt super's fight method which is abstract
    this->super->fight = &fightStrategy1;
    // local struct fight method points super's fight method. oop simulate
    this->fight = this->super->fight;

    this->destroy = &destroyStrategy1;
}

int fightStrategy1()
{
    srand(time(NULL));    // Seed the random number generator with the current time
    return rand() % 1001; // Generate a random number between 0 and 1000
}

void destroyStrategy1(Strategy1 *strategy)
{
    if (strategy == NULL)
        return;

    strategy->super->destroy(strategy->super);
    free(strategy);
}