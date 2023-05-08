#include "../../include/manufacture/Manufacture1.h"

Manufacture1 *newManufacture1()
{
    Manufacture1 *this = (Manufacture1 *)malloc(sizeof(Manufacture1));
    this->super = newAManufacture();
    this->destroy = &destroyManufacture1;
    this->super->produce = &produceManufacture1;
}
void destroyManufacture1(Manufacture1 *this)
{
    this->super->destroy(this->super);
    this->destroy(this);
};
int produceManufacture1()
{
    return 6;
};