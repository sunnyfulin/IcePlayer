#include "iceplayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CIcePlayer player;
    player.show();

    return a.exec();
}
