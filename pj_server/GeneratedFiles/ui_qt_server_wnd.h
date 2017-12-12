/********************************************************************************
** Form generated from reading UI file 'qt_server_wnd.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
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
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "pj_button.h"
#include "pj_checkbox.h"
#include "pj_groupbox.h"
#include "pj_label.h"
#include "pj_listview.h"
#include "pj_textbox.h"
#include "pj_toolbox.h"
#include "pj_widget.h"

QT_BEGIN_NAMESPACE

class Ui_ui_qt_server_wnd
{
public:
    QWidget *centralWidget;
    QPushButton *testButton2;
    QPushButton *testButton1;
    pj_button *pj_button_;
    pj_textbox *pj_textbox_1;
    pj_textbox *pj_textbox_;
    pj_toolbox *pj_toolbox_;
    pj_listview *pj_listview_;
    pj_checkbox *pj_checkbox_;
    pj_groupbox *pj_groupbox_;
    pj_widget *pj_widget_;
    pj_label *pj_label_;

    void setupUi(QMainWindow *ui_qt_server_wnd)
    {
        if (ui_qt_server_wnd->objectName().isEmpty())
            ui_qt_server_wnd->setObjectName(QStringLiteral("ui_qt_server_wnd"));
        ui_qt_server_wnd->resize(360, 428);
        centralWidget = new QWidget(ui_qt_server_wnd);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        testButton2 = new QPushButton(centralWidget);
        testButton2->setObjectName(QStringLiteral("testButton2"));
        testButton2->setGeometry(QRect(1228, 18, 150, 46));
        testButton1 = new QPushButton(centralWidget);
        testButton1->setObjectName(QStringLiteral("testButton1"));
        testButton1->setGeometry(QRect(18, 18, 150, 46));
        pj_button_ = new pj_button(centralWidget);
        pj_button_->setObjectName(QStringLiteral("pj_button_"));
        pj_button_->setGeometry(QRect(629, 18, 62, 46));
        pj_textbox_1 = new pj_textbox(centralWidget);
        pj_textbox_1->setObjectName(QStringLiteral("pj_textbox_1"));
        pj_textbox_1->setGeometry(QRect(1268, 115, 256, 192));
        pj_textbox_ = new pj_textbox(centralWidget);
        pj_textbox_->setObjectName(QStringLiteral("pj_textbox_"));
        pj_textbox_->setGeometry(QRect(629, 115, 256, 192));
        pj_toolbox_ = new pj_toolbox(centralWidget);
        pj_toolbox_->setObjectName(QStringLiteral("pj_toolbox_"));
        pj_toolbox_->setGeometry(QRect(1228, 115, 28, 997));
        pj_listview_ = new pj_listview(centralWidget);
        pj_listview_->setObjectName(QStringLiteral("pj_listview_"));
        pj_listview_->setGeometry(QRect(30, 115, 256, 192));
        pj_checkbox_ = new pj_checkbox(centralWidget);
        pj_checkbox_->setObjectName(QStringLiteral("pj_checkbox_"));
        pj_checkbox_->setGeometry(QRect(629, 76, 26, 26));
        pj_groupbox_ = new pj_groupbox(centralWidget);
        pj_groupbox_->setObjectName(QStringLiteral("pj_groupbox_"));
        pj_groupbox_->setGeometry(QRect(1228, 76, 28, 27));
        pj_widget_ = new pj_widget(centralWidget);
        pj_widget_->setObjectName(QStringLiteral("pj_widget_"));
        pj_widget_->setGeometry(QRect(580, 480, 587, 311));
        pj_label_ = new pj_label(centralWidget);
        pj_label_->setObjectName(QStringLiteral("pj_label_"));
        pj_label_->setGeometry(QRect(250, 70, 100, 100));
        ui_qt_server_wnd->setCentralWidget(centralWidget);

        retranslateUi(ui_qt_server_wnd);
        QObject::connect(testButton2, SIGNAL(clicked()), ui_qt_server_wnd, SLOT(test2()));
        QObject::connect(testButton1, SIGNAL(clicked()), ui_qt_server_wnd, SLOT(test1()));

        QMetaObject::connectSlotsByName(ui_qt_server_wnd);
    } // setupUi

    void retranslateUi(QMainWindow *ui_qt_server_wnd)
    {
        ui_qt_server_wnd->setWindowTitle(QApplication::translate("ui_qt_server_wnd", "pj_server", Q_NULLPTR));
        testButton2->setText(QApplication::translate("ui_qt_server_wnd", "\346\265\213\350\257\225\344\272\214", Q_NULLPTR));
        testButton1->setText(QApplication::translate("ui_qt_server_wnd", "\346\265\213\350\257\225\344\270\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ui_qt_server_wnd: public Ui_ui_qt_server_wnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SERVER_WND_H
