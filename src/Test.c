#include <stdio.h>
#include "../include/utils/DebugPrinter.h"
#include "../include/utils/ArrayList.h"
#include "../include/utils/DataType.h"
#include "../include/utils/ArrayList.h"
#include "../include/Colony/Colony.h"
#include "../include/utils/String.h"
#include "../include/game/GameManager.h"
#include "../include/game/Game.h"
#include "../include/log/Log.h"
#include "../include/ui/UI.h"

// TODO:
// create game structure to manage the game.
// complate the Colony structure, add produce, fight modules.
int main(int argc, char *argv[])
{
    // ARRAYLIST TEST
    int mock = 23;
    ArrayList *list = createArrayList(10, INT);
    ArrayList *clist = createArrayList(10, CHAR);

    // Append integer elements
    int a = 1, b = 2, c = 3;

    // append char elements
    char c_a = 'a', c_b = 'b', c_c = 'c';
    list->append(list, &a);
    list->append(list, &b);
    list->append(list, &c);

    clist->append(clist, &c_a);
    clist->append(clist, &c_b);
    clist->append(clist, &c_c);

    // Get an element
    int *element = (int *)list->get(list, 2);
    printf("Element at index 2: %d\n", *element);

    // Display the list
    list->display(list);

    clist->display(clist);
    clist->destroyArrayList(clist);

    // Clean up
    list->destroyArrayList(list);

    // TODO: create colony according to mock data. DONE
    Colony *colony = newColony(mock);

    printf("\n%s\n", colony->toString(colony)->str);

    colony->destroyColony(colony);

    String *myStr = newString("zort");
    printf("%s\n", myStr->str);
    printf("Length: %d\n", myStr->len);
    printf("Size: %d\n", myStr->getSize(myStr));
    destroyString(myStr);

    printf("\n");

    // ARGUMENTS TEST
    int i;

    for (i = 0; i < argc; i++)
    {
        int zz = atoi(argv[i]);
        printf("arg %d: %d\n", i, zz);
    }

    // GAME TEST
    int k = 127;
    int q = 54;
    int p = 49;
    int g = 47;
    int y = 67;
    int v = 278;
    int n = 357;
    ArrayList *populations = createArrayList(3, INT);
    populations->append(populations, &k);
    populations->append(populations, &q);
    populations->append(populations, &p);
    populations->append(populations, &g);
    populations->append(populations, &y);
    populations->append(populations, &v);
    populations->append(populations, &n);

    GameManager *gameManager = newGameManager(populations);
    Game *game = newGame(gameManager);
    game->play(game);

    // UI TEST DONE
    Ui *ui = newUi();
    ui->show(ui, game->gm->toursLogPack);
    ui->destroy(ui);

    game->destroy(game);
    gameManager->destroy(gameManager);
    populations->destroyArrayList(populations);

    // DEBUGPRINTER TEST
    DebugPrinter *dprinter = newDebugPrinter();
    // LOG TEST
    Colony *coll = newColony(98);
    Log *log = newLog(coll);
    dprinter->println("\n\nTEST LOG", CHAR);
    dprinter->println(log, _LOG);
    dprinter->destroy(dprinter);
    log->destroy(log);
    coll->destroyColony(coll);

    // WHICH CHARACTERS ARE PRINTABLE TEST
    dprinter = newDebugPrinter();
    int ii;
    char cc;
    for (ii = 0; ii < 50; ii++)
    {
        cc = ii;
        dprinter->print("character ", CHAR);
        dprinter->print(&ii, INT);
        dprinter->print(" : ", CHAR);
        dprinter->print(&cc, CHAR);
        dprinter->println(" ", CHAR);
    }
    dprinter->destroy(dprinter);

     // STRING TEST
    String *noerr = newString("\nno error.");
    String *trol = newMultiplyString("\nkaligula", 3);
    noerr->appendStr(noerr, trol);
    noerr->appendInt(noerr, q);
    noerr->appendChar(noerr, "    ");
    printf("\nTRIM ONCESI UZUNLUK: %d\nMETIN:%s", noerr->len, noerr->str);
    noerr->trim(noerr);
    printf("\nTRIM SONRASI UZUNLUK: %d\nMETIN:%s", noerr->len, noerr->str);

    noerr->destroy(noerr);
    trol->destroy(trol);

    return 0;
}