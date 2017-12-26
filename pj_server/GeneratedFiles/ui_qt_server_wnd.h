/********************************************************************************
** Form generated from reading UI file 'qt_server_wnd.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SERVER_WND_H
#define UI_QT_SERVER_WND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "pj_toolbox.h"
#include "pj_widget.h"

QT_BEGIN_NAMESPACE

class Ui_ui_qt_server_wnd
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    pj_widget *pj_widget_1;
    QVBoxLayout *verticalLayout;
    QPushButton *testButton2;
    pj_widget *pj_widget_;
    pj_toolbox *pj_toolbox_;
    pj_toolbox *pj_toolbox_1;
    QTextEdit *textEdit;
    QPushButton *xq_Button;
    QPushButton *testButton1;

    void setupUi(QMainWindow *ui_qt_server_wnd)
    {
        if (ui_qt_server_wnd->objectName().isEmpty())
            ui_qt_server_wnd->setObjectName(QStringLiteral("ui_qt_server_wnd"));
        ui_qt_server_wnd->resize(796, 633);
        centralWidget = new QWidget(ui_qt_server_wnd);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pj_widget_1 = new pj_widget(centralWidget);
        pj_widget_1->setObjectName(QStringLiteral("pj_widget_1"));
        verticalLayout = new QVBoxLayout(pj_widget_1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        testButton2 = new QPushButton(pj_widget_1);
        testButton2->setObjectName(QStringLiteral("testButton2"));

        verticalLayout->addWidget(testButton2);

        pj_widget_ = new pj_widget(pj_widget_1);
        pj_widget_->setObjectName(QStringLiteral("pj_widget_"));
        pj_toolbox_ = new pj_toolbox(pj_widget_);
        pj_toolbox_->setObjectName(QStringLiteral("pj_toolbox_"));
        pj_toolbox_->setGeometry(QRect(208, 183, 276, 28));
        pj_toolbox_1 = new pj_toolbox(pj_widget_);
        pj_toolbox_1->setObjectName(QStringLiteral("pj_toolbox_1"));
        pj_toolbox_1->setGeometry(QRect(208, 209, 276, 28));
        textEdit = new QTextEdit(pj_widget_);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(230, 220, 251, 31));

        verticalLayout->addWidget(pj_widget_);

        xq_Button = new QPushButton(pj_widget_1);
        xq_Button->setObjectName(QStringLiteral("xq_Button"));

        verticalLayout->addWidget(xq_Button);

        testButton1 = new QPushButton(pj_widget_1);
        testButton1->setObjectName(QStringLiteral("testButton1"));

        verticalLayout->addWidget(testButton1);


        gridLayout->addWidget(pj_widget_1, 0, 0, 1, 1);

        ui_qt_server_wnd->setCentralWidget(centralWidget);

        retranslateUi(ui_qt_server_wnd);
        QObject::connect(xq_Button, SIGNAL(clicked()), ui_qt_server_wnd, SLOT(test3()));
        QObject::connect(testButton1, SIGNAL(clicked()), ui_qt_server_wnd, SLOT(test1()));
        QObject::connect(testButton2, SIGNAL(clicked()), ui_qt_server_wnd, SLOT(test2()));

        QMetaObject::connectSlotsByName(ui_qt_server_wnd);
    } // setupUi

    void retranslateUi(QMainWindow *ui_qt_server_wnd)
    {
        ui_qt_server_wnd->setWindowTitle(QApplication::translate("ui_qt_server_wnd", "pj_server", nullptr));
        testButton2->setText(QApplication::translate("ui_qt_server_wnd", "\346\265\213\350\257\225\344\272\214", nullptr));
        pj_widget_->setResFileName(QApplication::translate("ui_qt_server_wnd", "d:\\gires3.wdf", nullptr));
        xq_Button->setText(QApplication::translate("ui_qt_server_wnd", "\345\260\217\347\220\246button", nullptr));
        testButton1->setText(QApplication::translate("ui_qt_server_wnd", "\345\271\275\347\201\265\344\271\237\346\235\245\344\272\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ui_qt_server_wnd: public Ui_ui_qt_server_wnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SERVER_WND_H
