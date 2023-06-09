#if !defined(STRATEGY0)
#define STRATEGY0
#include "AStrategy.h"
#include "AStrategy.h"
#include <stdlib.h>

/*
Strategy0 is a concrete implementation derived from the abstract class AStrategy that has the fight() and destroy() methods.
*/

#define S0FP 600 // strategy0 fight power
typedef struct Strategy0 Strategy0;

struct Strategy0
{

    AStrategy *super;
    void (*destroy)(Strategy0 *);
    int (*fight)();
};
Strategy0 *newStrategy0();
int fightStrategy0();
void destroyStrategy0(Strategy0 *strategy);
#endif // STRATEGY0
