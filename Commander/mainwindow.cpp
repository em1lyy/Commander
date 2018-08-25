#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QShortcut>
#include <QKeySequence>
#include <QMessageBox>
#include <qtermwidget5/qtermwidget.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QFont font = QApplication::font();
    font.setFamily("Hack");
    font.setPointSize(14);
    this->greenScheme = false;
    ui->setupUi(this);
    this->ui->centralWidget->setTerminalFont(font);
    this->ui->centralWidget->setScrollBarPosition(QTermWidget::ScrollBarRight);
    this->ui->centralWidget->setColorScheme("WhiteOnBlack");
    this->ui->centralWidget->setKeyBindings("linux");
    connect(this->ui->centralWidget, &QTermWidget::finished, this, &MainWindow::close);
    QShortcut *copy = new QShortcut(QKeySequence("Ctrl+Shift+C"), this);
    connect(copy, &QShortcut::activated, this->ui->centralWidget, &QTermWidget::copyClipboard);
    QShortcut *paste = new QShortcut(QKeySequence("Ctrl+Shift+V"), this);
    connect(paste, &QShortcut::activated, this->ui->centralWidget, &QTermWidget::pasteClipboard);
    QShortcut *scheme = new QShortcut(QKeySequence("Ctrl+Shift+S"), this);
    connect(scheme, &QShortcut::activated, this, &MainWindow::switchScheme);
    QShortcut *help = new QShortcut(Qt::Key_F1, this);
    connect(help, &QShortcut::activated, this, &MainWindow::showHelp);
    QShortcut *zout = new QShortcut(QKeySequence("Ctrl+-"), this);
    connect(zout, &QShortcut::activated, this->ui->centralWidget, &QTermWidget::zoomOut);
    QShortcut *zin = new QShortcut(QKeySequence("Ctrl++"), this);
    connect(zin, &QShortcut::activated, this->ui->centralWidget, &QTermWidget::zoomIn);
}

void MainWindow::switchScheme()
{
    if (greenScheme)
    {
        this->ui->centralWidget->setColorScheme("WhiteOnBlack");
        greenScheme = false;
    }
    else
    {
        this->ui->centralWidget->setColorScheme("GreenOnBlack");
        greenScheme = true;
    }
}

void MainWindow::showHelp()
{
    QMessageBox *helpbox = new QMessageBox();
    helpbox->setWindowTitle("Help - Commander");
    helpbox->setText(tr("Help:\nCtrl+Shift+C: Copy selected text\nCtrl+Shift+V: Paste Clipboard\nCtrl+Shift+S: Switch color scheme\nF1: Show this window"));
    helpbox->addButton(QMessageBox::Ok);
    helpbox->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
