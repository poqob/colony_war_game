#include "../../include/manufacture/Manufacture0.h"

Manufacture0 *newManufacture0()
{

    Manufacture0 *this = (Manufacture0 *)malloc(sizeof(Manufacture0));
    this->super = newAManufacture();
    this->destroy = &destroyManufacture0;
    this->super->produce = &produceManufacture0;
    this->produce = this->super->produce;
}
void destroyManufacture0(Manufacture0 *this)
{
    this->super->destroy(this->super);
    free(this);
};
int produceManufacture0() { return 9; };