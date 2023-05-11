#include "../../include/ui/UI.h"

Ui *newUi()
{
    Ui *this = (Ui *)malloc(sizeof(Ui));
    this->show = &uiShow;
    this->output = newString("");
    this->divider = newString("\n-------------------------------------------------------");
    return this;
}

// TODO: characters shifts after tour 6. LOOK FOR IT
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
        }
    }
    ptr->appendStr(ptr, screen->divider);
    ptr->appendChar(ptr, "\n");

    printf("%s", ptr->str);
}

void uiDestroy(Ui *screen)
{
    screen->output->destroy(screen->output);
    screen->divider->destroy(screen->divider);
    free(screen);
}
