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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ui_qt_server_wnd
{
public:
    QWidget *centralWidget;
    QPushButton *testButton2;
    QPushButton *testButton1;

    void setupUi(QMainWindow *ui_qt_server_wnd)
    {
        if (ui_qt_server_wnd->objectName().isEmpty())
            ui_qt_server_wnd->setObjectName(QStringLiteral("ui_qt_server_wnd"));
        ui_qt_server_wnd->resize(565, 454);
        centralWidget = new QWidget(ui_qt_server_wnd);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        testButton2 = new QPushButton(centralWidget);
        testButton2->setObjectName(QStringLiteral("testButton2"));
        testButton2->setGeometry(QRect(0, 18, 150, 46));
        testButton1 = new QPushButton(centralWidget);
        testButton1->setObjectName(QStringLiteral("testButton1"));
        testButton1->setGeometry(QRect(170, 20, 150, 46));
        ui_qt_server_wnd->setCentralWidget(centralWidget);

        retranslateUi(ui_qt_server_wnd);
        QObject::connect(testButton2, SIGNAL(clicked()), ui_qt_server_wnd, SLOT(test2()));
        QObject::connect(testButton1, SIGNAL(clicked()), ui_qt_server_wnd, SLOT(test1()));

        QMetaObject::connectSlotsByName(ui_qt_server_wnd);
    } // setupUi

    void retranslateUi(QMainWindow *ui_qt_server_wnd)
    {
        ui_qt_server_wnd->setWindowTitle(QApplication::translate("ui_qt_server_wnd", "pj_server", nullptr));
        testButton2->setText(QApplication::translate("ui_qt_server_wnd", "\346\265\213\350\257\225\344\272\214", nullptr));
        testButton1->setText(QApplication::translate("ui_qt_server_wnd", "\346\265\213\350\257\225\344\270\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ui_qt_server_wnd: public Ui_ui_qt_server_wnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SERVER_WND_H
