#include "../../include/ui/UI.h"

// constructor
Ui *newUi()
{
    Ui *this = (Ui *)malloc(sizeof(Ui));
    this->show = &uiShow;
    this->output = newString("");
    this->divider = newString("\n-------------------------------------------------------");
    this->destroy = &uiDestroy;
    return this;
}

// prints proper output(to sabis document) to screen.
// takes two parameter one of them is screen (Ui) object other one is The list of Log structures produced by GameManager.

void uiShow(Ui *screen, ArrayList *listOfLogsList)
{
    String *ptr = screen->output;
    ArrayList *logs;
    Log *log;

    int i, j;
    for (i = 0; i < listOfLogsList->size; i++)
    {
        logs = ((ArrayList *)listOfLogsList->get(listOfLogsList, i));

        ptr->appendStr(ptr, screen->divider);
        ptr->appendChar(ptr, "\nTour: ");
        ptr->appendInt(ptr, i + 1);
        ptr->appendChar(ptr, "\nColony    Population      Food Stock      Victory Loose");
        for (j = 0; j < logs->size; j++)
        {
            log = ((Log *)logs->get(logs, j));
            ptr->appendChar(ptr, "\n  ");
            ptr->appendStr(ptr, log->toString(log));
            // printf("\n%s", log->toString(log)->str);
        }
    }
    ptr->appendStr(ptr, screen->divider);
    ptr->appendChar(ptr, "\n");

    printf("%s", ptr->str);
}

// destructor
void uiDestroy(Ui *screen)
{
    if (screen->output->str != NULL)
        screen->output->destroy(screen->output);
    screen->divider->destroy(screen->divider);
    free(screen);
}
