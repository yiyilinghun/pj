/********************************************************************************
** Form generated from reading UI file 'pj_robot.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PJ_ROBOT_H
#define UI_PJ_ROBOT_H

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

class Ui_pj_robotClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *pj_robotClass)
    {
        if (pj_robotClass->objectName().isEmpty())
            pj_robotClass->setObjectName(QStringLiteral("pj_robotClass"));
        pj_robotClass->resize(600, 400);
        menuBar = new QMenuBar(pj_robotClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        pj_robotClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(pj_robotClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        pj_robotClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(pj_robotClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pj_robotClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(pj_robotClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        pj_robotClass->setStatusBar(statusBar);

        retranslateUi(pj_robotClass);

        QMetaObject::connectSlotsByName(pj_robotClass);
    } // setupUi

    void retranslateUi(QMainWindow *pj_robotClass)
    {
        pj_robotClass->setWindowTitle(QApplication::translate("pj_robotClass", "pj_robot", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pj_robotClass: public Ui_pj_robotClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PJ_ROBOT_H
