#include "../../include/manufacture/AManufacture.h"

// Constructor of AManufacture structure
AManufacture *newAManufacture()
{
    AManufacture *this = (AManufacture *)malloc(sizeof(AManufacture));
    this->destroy = &destroyAManufacture;
    return this;
}

// Destructor of AManufacture structure
void destroyAManufacture(AManufacture *this)
{
    free(this);
}