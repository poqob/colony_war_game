#include "../../include/ui/UI.h"

Ui *newUi()
{
    Ui *this = (Ui *)malloc(sizeof(Ui));
    this->write = &uiWrite;
    return this;
}

void uiWrite(Ui *this, String *text)
{
}
