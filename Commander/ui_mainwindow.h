/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *action_Help;
    QAction *action_Switch_Scheme;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuEdit;
    QMenu *menuAbout;
    QMenu *menu_Appearance;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 577);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("utilities-terminal");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        MainWindow->setWindowIcon(icon);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        action_Help = new QAction(MainWindow);
        action_Help->setObjectName(QString::fromUtf8("action_Help"));
        action_Switch_Scheme = new QAction(MainWindow);
        action_Switch_Scheme->setObjectName(QString::fromUtf8("action_Switch_Scheme"));
        actionZoom_In = new QAction(MainWindow);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        actionZoom_Out = new QAction(MainWindow);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 28));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menu_Appearance = new QMenu(menuBar);
        menu_Appearance->setObjectName(QString::fromUtf8("menu_Appearance"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menu_Appearance->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuAbout->addAction(action_Help);
        menuAbout->addSeparator();
        menuAbout->addAction(actionAbout);
        menuAbout->addAction(actionAbout_Qt);
        menu_Appearance->addAction(action_Switch_Scheme);
        menu_Appearance->addAction(actionZoom_In);
        menu_Appearance->addAction(actionZoom_Out);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Commander", nullptr));
        actionCopy->setText(QApplication::translate("MainWindow", "&Copy", nullptr));
        actionPaste->setText(QApplication::translate("MainWindow", "&Paste", nullptr));
        action_Help->setText(QApplication::translate("MainWindow", "&Help", nullptr));
        action_Switch_Scheme->setText(QApplication::translate("MainWindow", "&Switch Scheme", nullptr));
        actionZoom_In->setText(QApplication::translate("MainWindow", "Zoom &In", nullptr));
        actionZoom_Out->setText(QApplication::translate("MainWindow", "Zoom &Out", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About &Qt", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "&Edit", nullptr));
        menuAbout->setTitle(QApplication::translate("MainWindow", "&About", nullptr));
        menu_Appearance->setTitle(QApplication::translate("MainWindow", "&Appearance", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
