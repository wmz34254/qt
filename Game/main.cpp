#include "game.h"
#include <QApplication>
#include <QSoundEffect>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainW;
    mainW.show();
    return a.exec();
}
