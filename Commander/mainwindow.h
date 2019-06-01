#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtermwidget5/qtermwidget.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool greenScheme;
    void showHelp();
    void switchScheme();
    explicit MainWindow(QWidget *parent = 0);
    void about();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTermWidget *conwid;
};

#endif // MAINWINDOW_H
