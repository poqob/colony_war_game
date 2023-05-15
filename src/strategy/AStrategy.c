
#include "AStrategy.h"

// CONSTRUCTOR of AStrategy
AStrategy *newAStrategy()
{
    AStrategy *this = malloc(sizeof(AStrategy));
    this->destroy = &Adestroy;
    return this;
}

// Destructor
void Adestroy(AStrategy *strategy)
{
    free(strategy);
}