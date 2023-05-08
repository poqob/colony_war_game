#include "../../include/manufacture/AManufacture.h"

AManufacture *newAManufacture()
{
    AManufacture *this = (AManufacture *)malloc(sizeof(AManufacture));
    this->destroy = &destroyAManufacture;
}
void destroyAManufacture(AManufacture *this)
{
    free(this);
}