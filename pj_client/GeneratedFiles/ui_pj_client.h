/********************************************************************************
** Form generated from reading UI file 'pj_client.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PJ_CLIENT_H
#define UI_PJ_CLIENT_H

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

class Ui_pj_clientClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *pj_clientClass)
    {
        if (pj_clientClass->objectName().isEmpty())
            pj_clientClass->setObjectName(QStringLiteral("pj_clientClass"));
        pj_clientClass->resize(600, 400);
        menuBar = new QMenuBar(pj_clientClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        pj_clientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(pj_clientClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        pj_clientClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(pj_clientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pj_clientClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(pj_clientClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        pj_clientClass->setStatusBar(statusBar);

        retranslateUi(pj_clientClass);

        QMetaObject::connectSlotsByName(pj_clientClass);
    } // setupUi

    void retranslateUi(QMainWindow *pj_clientClass)
    {
        pj_clientClass->setWindowTitle(QApplication::translate("pj_clientClass", "pj_client", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pj_clientClass: public Ui_pj_clientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PJ_CLIENT_H
