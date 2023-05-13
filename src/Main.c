#include "../include/utils/InputManager.h"
#include "../include/game/GameManager.h"
#include "../include/game/Game.h"
#include "../include/ui/UI.h"

int main(int argc, char *argv[])
{
    InputManager *inputManager = newInputManager(argc, argv);
    GameManager *gameManager = newGameManager(inputManager->populations);
    Game *game = newGame(gameManager);
    Ui *ui = newUi();

    game->play(game);
    ui->show(ui, game->gm->toursLogPack);

    ui->destroy(ui);
    game->destroy(game);
    gameManager->destroy(gameManager);
    inputManager->destroy(inputManager);
}