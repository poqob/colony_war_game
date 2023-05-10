#if !defined(UI)
#define UI
#include "../utils/String.h"
typedef struct Ui Ui;

struct Ui
{
    void (*write)(String *);
    void (*destroy)(Ui *);
};
Ui *newUi(Ui *);
void uiWrite(Ui *, String *);
void uiDestroy(Ui *);
#endif // UI
