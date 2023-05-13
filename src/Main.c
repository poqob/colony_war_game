#include "../include/game/GameManager.h"
#include "../include/game/Game.h"
#include "../include/ui/UI.h"

int main(int argc, char *argv[])
{

    ArrayList *populations = createArrayList(3, INT);
    int *numericArgs = (int *)malloc(sizeof(int) * argc);

    int i;
    for (i = 0; i < argc; i++)
    {
        if (i == 0)
            continue; // -- first argument is 0

        numericArgs[i - 1] = atoi(argv[i]);
        printf("--%d\n", numericArgs[i - 1]);
        populations->append(populations, &numericArgs[i - 1]);
    }
    // populations->display(populations);

    GameManager *gameManager = newGameManager(populations);
    Game *game = newGame(gameManager);
    Ui *ui = newUi();
    game->play(game);

    ui->show(ui, game->gm->toursLogPack);
    ui->destroy(ui);

    game->destroy(game);
    gameManager->destroy(gameManager);
    populations->destroyArrayList(populations);
    free(numericArgs);
}