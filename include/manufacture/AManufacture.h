#if !defined(AMANUFACTURE)
#define AMANUFACTURE
#include <stdlib.h>

/*
Within the AManufacture abstract class, there are two defined functions: "produce()" and "destroy()".
The "produce()" function is an abstract representation and is assigned by child structures (class representations).
*/

typedef struct AManufacture AManufacture;
struct AManufacture
{
    int (*produce)();
    void (*destroy)(AManufacture *);
};

AManufacture *newAManufacture();
void destroyAManufacture();

#endif // AMANUFACTURE
