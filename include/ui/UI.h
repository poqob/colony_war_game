#if !defined(UI)
#define UI
#include "../utils/ArrayList.h"
#include "../utils/String.h"

/*
The task of the Ui structure is to write the given Log structures to the console in a specific format using the show() method.
*/

typedef struct Ui Ui;
struct Ui
{
    String *output;
    String *divider;
    void (*show)(Ui *, ArrayList *);
    void (*destroy)(Ui *);
};
Ui *newUi();
void uiShow(Ui *, ArrayList *);
void uiDestroy(Ui *);
#endif // UI
