/********************************************************************************
** Form generated from reading UI file 'planegame.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANEGAME_H
#define UI_PLANEGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyPlaneGameClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyPlaneGameClass)
    {
        if (MyPlaneGameClass->objectName().isEmpty())
            MyPlaneGameClass->setObjectName(QStringLiteral("MyPlaneGameClass"));
        MyPlaneGameClass->resize(600, 400);
        menuBar = new QMenuBar(MyPlaneGameClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MyPlaneGameClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyPlaneGameClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyPlaneGameClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MyPlaneGameClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MyPlaneGameClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MyPlaneGameClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyPlaneGameClass->setStatusBar(statusBar);

        retranslateUi(MyPlaneGameClass);

        QMetaObject::connectSlotsByName(MyPlaneGameClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyPlaneGameClass)
    {
        MyPlaneGameClass->setWindowTitle(QApplication::translate("MyPlaneGameClass", "MyPlaneGame", 0));
    } // retranslateUi

};

namespace Ui {
    class MyPlaneGameClass: public Ui_MyPlaneGameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANEGAME_H
