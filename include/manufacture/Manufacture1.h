#if !defined(MANUFACTURE1)
#define MANUFACTURE1

#include "AManufacture.h"

/*
Manufacture1 is a concrete implementation derived from the abstract class AManufacture that has the produce() and destroy() methods.
*/

#define M1PP 6 // manufature 1 produce power
typedef struct Manufacture1 Manufacture1;
struct Manufacture1
{
    AManufacture *super;
    int (*produce)();
    void (*destroy)(Manufacture1 *);
};

Manufacture1 *newManufacture1();
void destroyManufacture1(Manufacture1 *);
int produceManufacture1();
#endif // MANUFACTURE1
