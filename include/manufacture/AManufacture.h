#if !defined(AMANUFACTURE)
#define AMANUFACTURE

typedef struct AManufacture AManufacture;

struct AManufacture
{
    int (*produce)();
    void (*destroy)(AManufacture *);
};

AManufacture *newAManufacture();
void *destroyAManufacture();

#endif // AMANUFACTURE
