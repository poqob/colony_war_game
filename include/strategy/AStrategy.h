#if !defined(ASTRATEGY)
#define ASTRATEGY
#include <stdlib.h>
typedef struct AStrategy AStrategy;

struct AStrategy
{
    int (*fight)();
    void (*destroy)(AStrategy *);
};
AStrategy *newAStrategy();
void Adestroy(AStrategy *Astrategy);
#endif // ASTRATEGY
