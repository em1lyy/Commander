#include "mainwindow.h"
#include <QApplication>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    setenv("$TERM", "konsole-256color", 1);
    w.show();

    return a.exec();
}
