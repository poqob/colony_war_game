#if !defined(STRATEGY0)
#define STRATEGY0
#include "AStrategy.h"
typedef struct Strategy0 Strategy0;

struct Strategy0
{
    AStrategy *super;
    void (*destroy)(Strategy0 *);
    int (*fight)();
};
Strategy0 *newStrategy0();
int fight0();
void destroy0(Strategy0 *strategy);
#endif // STRATEGY0
