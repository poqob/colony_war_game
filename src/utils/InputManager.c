#include "../../include/utils/InputManager.h"

// constructor
InputManager *newInputManager(int argc, char *argv[])
{
    // attemps
    InputManager *this = (InputManager *)malloc(sizeof(InputManager));
    this->destroy = &destroyInputManager;
    this->numericArgs = (int *)malloc(sizeof(int) * argc);
    this->populations = createArrayList(3, INT);

    // read all inputs and turn them into intagers then append them to populations list.
    int i;
    for (i = 0; i < argc; i++)
    {
        if (i == 0)
            continue; // -- first argument is always 0

        this->numericArgs[i - 1] = atoi(argv[i]);
        // printf("--%d\n", this->numericArgs[i - 1]);
        this->populations->append(this->populations, &this->numericArgs[i - 1]);
    }
    // this->populations->display(this->populations);
    return this;
}

// destructor
void destroyInputManager(InputManager *this)
{
    free(this->numericArgs);
    this->populations->destroyArrayList(this->populations);
    free(this);
}