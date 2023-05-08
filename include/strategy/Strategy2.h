#if !defined(STRATEGY2)
#define STRATEGY2

#include "AStrategy.h"
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
