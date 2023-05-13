#if !defined(MANUFACTURE2)
#define MANUFACTURE2
#define M2PP 4 // manufature 2 produce power
#include "AManufacture.h"

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
