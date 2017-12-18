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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "pj_widget.h"

QT_BEGIN_NAMESPACE

class Ui_ui_qt_server_wnd
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *testButton2;
    pj_widget *pj_widget_;
    QPushButton *testButton1;
    QPushButton *xq_Button;

    void setupUi(QMainWindow *ui_qt_server_wnd)
    {
        if (ui_qt_server_wnd->objectName().isEmpty())
            ui_qt_server_wnd->setObjectName(QStringLiteral("ui_qt_server_wnd"));
        ui_qt_server_wnd->resize(558, 575);
        centralWidget = new QWidget(ui_qt_server_wnd);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        testButton2 = new QPushButton(centralWidget);
        testButton2->setObjectName(QStringLiteral("testButton2"));

        verticalLayout->addWidget(testButton2);

        pj_widget_ = new pj_widget(centralWidget);
        pj_widget_->setObjectName(QStringLiteral("pj_widget_"));

        verticalLayout->addWidget(pj_widget_);

        testButton1 = new QPushButton(centralWidget);
        testButton1->setObjectName(QStringLiteral("testButton1"));

        verticalLayout->addWidget(testButton1);

        xq_Button = new QPushButton(centralWidget);
        xq_Button->setObjectName(QStringLiteral("xq_Button"));

        verticalLayout->addWidget(xq_Button);

        ui_qt_server_wnd->setCentralWidget(centralWidget);

        retranslateUi(ui_qt_server_wnd);
        QObject::connect(testButton2, SIGNAL(clicked()), ui_qt_server_wnd, SLOT(test2()));
        QObject::connect(testButton1, SIGNAL(clicked()), ui_qt_server_wnd, SLOT(test1()));
        QObject::connect(xq_Button, SIGNAL(clicked()), ui_qt_server_wnd, SLOT(test3()));

        QMetaObject::connectSlotsByName(ui_qt_server_wnd);
    } // setupUi

    void retranslateUi(QMainWindow *ui_qt_server_wnd)
    {
        ui_qt_server_wnd->setWindowTitle(QApplication::translate("ui_qt_server_wnd", "pj_server", nullptr));
        testButton2->setText(QApplication::translate("ui_qt_server_wnd", "\346\265\213\350\257\225\344\272\214", nullptr));
        pj_widget_->setResFileName(QApplication::translate("ui_qt_server_wnd", "\345\223\210\345\223\210", nullptr));
        testButton1->setText(QApplication::translate("ui_qt_server_wnd", "\346\265\213\350\257\225\344\270\200", nullptr));
        xq_Button->setText(QApplication::translate("ui_qt_server_wnd", "\345\260\217\347\220\246button", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ui_qt_server_wnd: public Ui_ui_qt_server_wnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SERVER_WND_H
