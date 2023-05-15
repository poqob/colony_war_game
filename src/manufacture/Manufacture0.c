#include "../../include/manufacture/Manufacture0.h"

// Constructor of Manufacture0 structure
Manufacture0 *newManufacture0()
{

    Manufacture0 *this = (Manufacture0 *)malloc(sizeof(Manufacture0));
    this->super = newAManufacture();
    this->destroy = &destroyManufacture0;
    this->super->produce = &produceManufacture0;
    this->produce = this->super->produce;
    return this;
}

// the produce method of Manufacture0
int produceManufacture0() { return M0PP; };

// Destructor of Manufacture0 structure
void destroyManufacture0(Manufacture0 *this)
{
    this->super->destroy(this->super);
    free(this);
};
