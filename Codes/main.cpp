#include<QApplication>
#include "board.h"
#include "game_controller.h"

int main(int argc, char *argv[])
{
    QApplication app (argc, argv);


    GameController gctrlr;

    gctrlr.resize(500,500);
    gctrlr.setWindowTitle("Game of life");
    gctrlr.show();

    return app.exec();
}
