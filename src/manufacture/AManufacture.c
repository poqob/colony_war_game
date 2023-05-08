#include "../../include/manufacture/AManufacture.h"

AManufacture *newAManufacture()
{
    AManufacture *this;
    this->destroy = destroyAManufacture;
}
void *destroyAManufacture(AManufacture *this)
{
    free(this);
}