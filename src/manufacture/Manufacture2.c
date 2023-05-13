#include "../../include/manufacture/Manufacture2.h"

Manufacture2 *newManufacture2()
{
    Manufacture2 *this = (Manufacture2 *)malloc(sizeof(Manufacture2));
    this->super = newAManufacture();
    this->destroy = &destroyManufacture2;
    this->super->produce = &produceManufacture2;
    this->produce = this->super->produce;
}
void destroyManufacture2(Manufacture2 *this)
{
    this->super->destroy(this->super);
    free(this);
};
int produceManufacture2()
{
    return M2PP;
};