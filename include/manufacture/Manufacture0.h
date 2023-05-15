#if !defined(MANUFACTURE0)
#define MANUFACTURE0
#include "AManufacture.h"

/*
Manufacture0 is a concrete implementation derived from the abstract class AManufacture that has the produce() and destroy() methods.
*/

#define M0PP 9 // manufature 0 produce power
typedef struct Manufacture0 Manufacture0;
struct Manufacture0
{
    AManufacture *super;
    int (*produce)();
    void (*destroy)(Manufacture0 *);
};

Manufacture0 *newManufacture0();
void destroyManufacture0(Manufacture0 *);
int produceManufacture0();
#endif // MANUFACTURE0
