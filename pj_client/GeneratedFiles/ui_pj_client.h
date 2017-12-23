/********************************************************************************
** Form generated from reading UI file 'pj_client.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
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
#include "pj_widget.h"

QT_BEGIN_NAMESPACE

class Ui_pj_clientClass
{
public:
    QWidget *centralWidget;
    pj_widget *pj_widget_;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *pj_clientClass)
    {
        if (pj_clientClass->objectName().isEmpty())
            pj_clientClass->setObjectName(QStringLiteral("pj_clientClass"));
        pj_clientClass->resize(600, 622);
        centralWidget = new QWidget(pj_clientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pj_widget_ = new pj_widget(centralWidget);
        pj_widget_->setObjectName(QStringLiteral("pj_widget_"));
        pj_widget_->setGeometry(QRect(20, 10, 511, 421));
        pj_widget_->setNeedLoadRes(true);
        pj_widget_->setResKey(2904516639u);
        pj_clientClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(pj_clientClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        pj_clientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(pj_clientClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        pj_clientClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(pj_clientClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        pj_clientClass->setStatusBar(statusBar);

        retranslateUi(pj_clientClass);

        QMetaObject::connectSlotsByName(pj_clientClass);
    } // setupUi

    void retranslateUi(QMainWindow *pj_clientClass)
    {
        pj_clientClass->setWindowTitle(QApplication::translate("pj_clientClass", "pj_client", nullptr));
        pj_widget_->setResFileName(QApplication::translate("pj_clientClass", "d:\\gires3.wdf", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pj_clientClass: public Ui_pj_clientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PJ_CLIENT_H
