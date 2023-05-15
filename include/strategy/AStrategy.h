#if !defined(ASTRATEGY)
#define ASTRATEGY
#include <stdlib.h>

/*
Within the AStrategy abstract class, there are two defined functions: "fight()" and "destroy()".
The "fight()" function is an abstract representation and is assigned by child structures (class representations).
*/

typedef struct AStrategy AStrategy;
struct AStrategy
{
    int (*fight)();
    void (*destroy)(AStrategy *);
};
AStrategy *newAStrategy();
void Adestroy(AStrategy *Astrategy);
#endif // ASTRATEGY
