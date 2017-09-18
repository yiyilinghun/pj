/********************************************************************************
** Form generated from reading UI file 'pj_tools.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PJ_TOOLS_H
#define UI_PJ_TOOLS_H

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

class Ui_pj_toolsClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *pj_toolsClass)
    {
        if (pj_toolsClass->objectName().isEmpty())
            pj_toolsClass->setObjectName(QStringLiteral("pj_toolsClass"));
        pj_toolsClass->resize(600, 400);
        menuBar = new QMenuBar(pj_toolsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        pj_toolsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(pj_toolsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        pj_toolsClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(pj_toolsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pj_toolsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(pj_toolsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        pj_toolsClass->setStatusBar(statusBar);

        retranslateUi(pj_toolsClass);

        QMetaObject::connectSlotsByName(pj_toolsClass);
    } // setupUi

    void retranslateUi(QMainWindow *pj_toolsClass)
    {
        pj_toolsClass->setWindowTitle(QApplication::translate("pj_toolsClass", "pj_tools", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pj_toolsClass: public Ui_pj_toolsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PJ_TOOLS_H
