/********************************************************************************
** Form generated from reading UI file 'pj_server.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PJ_SERVER_H
#define UI_PJ_SERVER_H

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

class Ui_pj_serverClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *pj_serverClass)
    {
        if (pj_serverClass->objectName().isEmpty())
            pj_serverClass->setObjectName(QStringLiteral("pj_serverClass"));
        pj_serverClass->resize(600, 400);
        menuBar = new QMenuBar(pj_serverClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        pj_serverClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(pj_serverClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        pj_serverClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(pj_serverClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pj_serverClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(pj_serverClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        pj_serverClass->setStatusBar(statusBar);

        retranslateUi(pj_serverClass);

        QMetaObject::connectSlotsByName(pj_serverClass);
    } // setupUi

    void retranslateUi(QMainWindow *pj_serverClass)
    {
        pj_serverClass->setWindowTitle(QApplication::translate("pj_serverClass", "pj_server", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pj_serverClass: public Ui_pj_serverClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PJ_SERVER_H
