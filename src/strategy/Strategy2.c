#include "Strategy2.h"
#include <stdlib.h>
#include <time.h>

Strategy2 *newStrategy2()
{
    Strategy2 *this = (Strategy2 *)malloc(sizeof(Strategy2));
    this->super = newAStrategy();
    // attemt super's fight method which is abstract
    this->super->fight = &fightStrategy2;
    // local struct fight method points super's fight method. oop simulate
    this->fight = this->super->fight;

    this->destroy = &destroyStrategy2;
}

int fightStrategy2()
{
    srand(time(NULL)); // Seed the random number generator with the current time
    return 900;        // rand() % 1001; // Generate a random number between 0 and 1000
}

void destroyStrategy2(Strategy2 *strategy)
{
    if (strategy == NULL)
        return;

    strategy->super->destroy(strategy->super);
    free(strategy);
}