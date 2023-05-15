#include "../../include/manufacture/Manufacture1.h"

// Constructor of Manufacture1 structure
Manufacture1 *newManufacture1()
{
    Manufacture1 *this = (Manufacture1 *)malloc(sizeof(Manufacture1));
    this->super = newAManufacture();
    this->destroy = &destroyManufacture1;
    this->super->produce = &produceManufacture1;
    this->produce = this->super->produce;
    return this;
}

// the produce method of Manufacture1
int produceManufacture1() { return M1PP; };

// Destructor of Manufacture1 structure
void destroyManufacture1(Manufacture1 *this)
{
    this->super->destroy(this->super);
    free(this);
};