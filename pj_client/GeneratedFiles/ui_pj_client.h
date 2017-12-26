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
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "pj_toolbox.h"
#include "pj_widget.h"

QT_BEGIN_NAMESPACE

class Ui_ui_scene
{
public:
    QWidget *centralWidget;
    pj_widget *pj_widget_;
    QTextEdit *textEdit;
    pj_toolbox *pj_toolbox_;
    pj_toolbox *pj_toolbox_1;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ui_scene)
    {
        if (ui_scene->objectName().isEmpty())
            ui_scene->setObjectName(QStringLiteral("ui_scene"));
        ui_scene->resize(943, 622);
        centralWidget = new QWidget(ui_scene);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pj_widget_ = new pj_widget(centralWidget);
        pj_widget_->setObjectName(QStringLiteral("pj_widget_"));
        pj_widget_->setGeometry(QRect(20, 10, 721, 521));
        pj_widget_->setResKey(2904516639u);
        pj_widget_->setProperty("needLoadRes", QVariant(true));
        textEdit = new QTextEdit(pj_widget_);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(242, 221, 251, 31));
        pj_toolbox_ = new pj_toolbox(pj_widget_);
        pj_toolbox_->setObjectName(QStringLiteral("pj_toolbox_"));
        pj_toolbox_->setGeometry(QRect(220, 184, 276, 28));
        pj_toolbox_1 = new pj_toolbox(pj_widget_);
        pj_toolbox_1->setObjectName(QStringLiteral("pj_toolbox_1"));
        pj_toolbox_1->setGeometry(QRect(220, 210, 276, 28));
        ui_scene->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ui_scene);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 943, 23));
        ui_scene->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ui_scene);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ui_scene->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ui_scene);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ui_scene->setStatusBar(statusBar);

        retranslateUi(ui_scene);

        QMetaObject::connectSlotsByName(ui_scene);
    } // setupUi

    void retranslateUi(QMainWindow *ui_scene)
    {
        ui_scene->setWindowTitle(QApplication::translate("ui_scene", "PJ\345\234\272\346\231\257", nullptr));
        pj_widget_->setResFileName(QApplication::translate("ui_scene", "d:\\gires3.wdf", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ui_scene: public Ui_ui_scene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PJ_CLIENT_H
