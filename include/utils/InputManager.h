#if !defined(INPUTMANAGER)
#define INPUTMANAGER
#include "ArrayList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct InputManager InputManager;

struct InputManager
{
    int *numericArgs;
    ArrayList *populations;
    void (*destroy)(InputManager *);
};
InputManager *newInputManager(int argc, char *argv[]);
void destroyInputManager(InputManager *);
#endif // INPUTMANAGER
