#if !defined(MANUFACTURE1)
#define MANUFACTURE1
#define M1PP 6 // manufature 1 produce power

#include "AManufacture.h"

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
