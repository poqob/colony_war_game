#include "../../include/manufacture/Manufacture2.h"

// Constructor of Manufacture2 structure
Manufacture2 *newManufacture2()
{
    Manufacture2 *this = (Manufacture2 *)malloc(sizeof(Manufacture2));
    this->super = newAManufacture();
    this->destroy = &destroyManufacture2;
    this->super->produce = &produceManufacture2;
    this->produce = this->super->produce;
    return this;
}

// the produce method of Manufacture2
int produceManufacture2() { return M2PP; };

// Destructor of Manufacture1 structure
void destroyManufacture2(Manufacture2 *this)
{
    this->super->destroy(this->super);
    free(this);
};
