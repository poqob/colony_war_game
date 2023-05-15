#if !defined(STRATEGY2)
#define STRATEGY2

#include "AStrategy.h"
#include <stdlib.h>
#include <time.h>
/*
Strategy2 is a concrete implementation derived from the abstract class AStrategy that has the fight() and destroy() methods.
*/
#define S2FP 900
typedef struct Strategy2 Strategy2;

struct Strategy2
{

    AStrategy *super;
    void (*destroy)(Strategy2 *);
    int (*fight)();
};
Strategy2 *newStrategy2();
int fightStrategy2();
void destroyStrategy2(Strategy2 *strategy);

#endif // STRATEGY1
