#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QShortcut>
#include <QKeySequence>
#include <QMessageBox>
#include <stdlib.h>
#include <QSettings>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QFont font = QApplication::font();
    font.setFamily("Hack");
    font.setPointSize(14);
    this->greenScheme = false;
    setenv("TERM", "xterm-256color", 1);
    qDebug() << getenv("TERM");
    QTermWidget *console = new QTermWidget();
    ui->setupUi(this);
    setenv("TERM", "xterm-256color", 1);
    qDebug() << getenv("TERM");
    QSettings settings("JaguDev", "Commander");
    settings.setValue("Term", "xterm-256color");
    QStringList env = QProcess::systemEnvironment();
    env << "TERM=xterm-256color"; // Add an environment variable
    console->setEnvironment(env);
    console->setTerminalFont(font);
    console->setScrollBarPosition(QTermWidget::ScrollBarRight);
    console->setColorScheme("Linux");
    qDebug() << console->availableColorSchemes() << " " << console->availableKeyBindings();
    console->setKeyBindings("linux");
    connect(console, &QTermWidget::finished, this, &MainWindow::close);
    QShortcut *copy = new QShortcut(QKeySequence("Ctrl+Shift+C"), this);
    connect(copy, &QShortcut::activated, console, &QTermWidget::copyClipboard);
    QShortcut *paste = new QShortcut(QKeySequence("Ctrl+Shift+V"), this);
    connect(paste, &QShortcut::activated, console, &QTermWidget::pasteClipboard);
    QShortcut *scheme = new QShortcut(QKeySequence("Ctrl+Shift+S"), this);
    connect(scheme, &QShortcut::activated, this, &MainWindow::switchScheme);
    QShortcut *help = new QShortcut(Qt::Key_F1, this);
    connect(help, &QShortcut::activated, this, &MainWindow::showHelp);
    QShortcut *zout = new QShortcut(QKeySequence("Ctrl+-"), this);
    connect(zout, &QShortcut::activated, console, &QTermWidget::zoomOut);
    QShortcut *zin = new QShortcut(QKeySequence("Ctrl++"), this);
    connect(zin, &QShortcut::activated, console, &QTermWidget::zoomIn);
    connect(this->ui->actionCopy, &QAction::triggered, console, &QTermWidget::copyClipboard);
    connect(this->ui->actionPaste, &QAction::triggered, console, &QTermWidget::pasteClipboard);
    connect(this->ui->action_Switch_Scheme, &QAction::triggered, this, &MainWindow::switchScheme);
    connect(this->ui->action_Help, &QAction::triggered, this, &MainWindow::showHelp);
    connect(this->ui->actionZoom_In, &QAction::triggered, console, &QTermWidget::zoomIn);
    connect(this->ui->actionZoom_Out, &QAction::triggered, console, &QTermWidget::zoomOut);
    connect(this->ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(this->ui->actionAbout_Qt, &QAction::triggered, &QApplication::aboutQt);
    this->setCentralWidget(console);
    this->conwid = console;
    setenv("TERM", "xterm-256color", 1);
    qDebug() << getenv("TERM");
}

void MainWindow::switchScheme()
{
    if (greenScheme)
    {
        this->conwid->setColorScheme("WhiteOnBlack");
        greenScheme = false;
    }
    else
    {
        this->conwid->setColorScheme("GreenOnBlack");
        greenScheme = true;
    }
}

void MainWindow::showHelp()
{
    QMessageBox *helpbox = new QMessageBox();
    helpbox->setWindowTitle(tr("Help - Commander"));
    helpbox->setText(tr("Help:\nCtrl+Shift+C: Copy selected text\nCtrl+Shift+V: Paste Clipboard\nCtrl+Shift+S: Switch color scheme\nCtrl++: Zoom In\nCtrl+-: Zoom Out\nF1: Show this window"));
    helpbox->addButton(QMessageBox::Ok);
    helpbox->show();
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Commander"),
            tr("<p><b>Commander</b> is a very simple terminal,<br />based on QTermWidget and developed by JaguDev.</p>"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
