#include <stdio.h>
#include "../include/utils/ArrayList.h"
#include "../include/utils/DataType.h"
#include "../include/utils/ArrayList.h"
#include "../include/Colony/Colony.h"
#include "../include/utils/String.h"
#include "../include/game/Game.h"

// TODO:
// create game structure to manage the game.
// complate the Colony structure, add produce, fight modules.
int main(int argc, char *argv[])
{
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
    printf("\ncolony symbol: %c ", colony->symbol);
    colony->destroyColony(colony);

    String *myStr = newString("zort");
    printf("%s\n", myStr->str);
    printf("Length: %d\n", myStr->len);
    printf("Size: %d\n", myStr->getSize(myStr));
    destroyString(myStr);

    printf("\n");

    // console argument test
    int i;

    for (i = 0; i < argc; i++)
    {
        int zz = atoi(argv[i]);
        printf("arg %d: %d\n", i, zz);
    }
    ArrayList *populations = createArrayList(4, INT);
    populations->append(populations, &a);
    populations->append(populations, &b);
    Game *game = newGame(populations);

    printf("\nno error.");

    return 0;
}