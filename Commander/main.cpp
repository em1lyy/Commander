#include "mainwindow.h"
#include <QApplication>
#include <stdlib.h>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString locale = QLocale::system().name();
    QTranslator translator;
    translator.load(":/" + locale);
    a.installTranslator(&translator);
    MainWindow w;
    setenv("$TERM", "xterm-256color", 1);
    w.show();

    return a.exec();
}
