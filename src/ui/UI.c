#include "../../include/ui/UI.h"

Ui *newUi(Ui *this)
{
    this->write = &uiWrite;
}

void uiWrite(Ui *this, String *text)
{
}
