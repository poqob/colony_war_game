#if !defined(UI)
#define UI
#include "../utils/String.h"
typedef struct Ui Ui;

struct Ui
{
    void (*write)(Ui *, String *);
    void (*destroy)(Ui *);
};
Ui *newUi();
void uiWrite(Ui *, String *);
void uiDestroy(Ui *);
#endif // UI
