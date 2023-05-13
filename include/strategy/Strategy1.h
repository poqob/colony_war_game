#if !defined(STRATEGY1)
#define STRATEGY1
#define S1FP 800 // strategy1 fight power

#include "AStrategy.h"
typedef struct Strategy1 Strategy1;

struct Strategy1
{

    AStrategy *super;
    void (*destroy)(Strategy1 *);
    int (*fight)();
};
Strategy1 *newStrategy1();
int fightStrategy1();
void destroyStrategy1(Strategy1 *strategy);

#endif // STRATEGY1
