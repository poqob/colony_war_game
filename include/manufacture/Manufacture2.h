#if !defined(MANUFACTURE2)
#define MANUFACTURE2

#include "AManufacture.h"

/*
Manufacture2 is a concrete implementation derived from the abstract class AManufacture that has the produce() and destroy() methods.
*/

#define M2PP 4 // manufature 2 produce power
typedef struct Manufacture2 Manufacture2;
struct Manufacture2
{
    AManufacture *super;
    int (*produce)();
    void (*destroy)(Manufacture2 *);
};

Manufacture2 *newManufacture2();
void destroyManufacture2(Manufacture2 *);
int produceManufacture2();
#endif // MANUFACTURE2
