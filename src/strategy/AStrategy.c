
#include "AStrategy.h"

AStrategy *newAStrategy()
{
    AStrategy *this = malloc(sizeof(AStrategy));
    this->destroy = &Adestroy;
}

void Adestroy(AStrategy *strategy)
{
    free(strategy);
}