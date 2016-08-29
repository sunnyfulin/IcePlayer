#include "iceplayer.h"
#include <QApplication>

#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile skin("../skin/skin.qss");
    skin.open(QFile::ReadOnly);
    a.setStyleSheet(skin.readAll());

    CIcePlayer player;
    player.show();

    return a.exec();
}
