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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ui_qt_server_wnd
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *testButton1;
    QPushButton *testButton2;

    void setupUi(QMainWindow *ui_qt_server_wnd)
    {
        if (ui_qt_server_wnd->objectName().isEmpty())
            ui_qt_server_wnd->setObjectName(QStringLiteral("ui_qt_server_wnd"));
        ui_qt_server_wnd->resize(816, 747);
        centralWidget = new QWidget(ui_qt_server_wnd);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        testButton1 = new QPushButton(centralWidget);
        testButton1->setObjectName(QStringLiteral("testButton1"));

        gridLayout->addWidget(testButton1, 0, 0, 1, 1);

        testButton2 = new QPushButton(centralWidget);
        testButton2->setObjectName(QStringLiteral("testButton2"));

        gridLayout->addWidget(testButton2, 0, 1, 1, 1);

        ui_qt_server_wnd->setCentralWidget(centralWidget);

        retranslateUi(ui_qt_server_wnd);
        QObject::connect(testButton1, SIGNAL(clicked()), ui_qt_server_wnd, SLOT(test1()));
        QObject::connect(testButton2, SIGNAL(clicked()), ui_qt_server_wnd, SLOT(test2()));

        QMetaObject::connectSlotsByName(ui_qt_server_wnd);
    } // setupUi

    void retranslateUi(QMainWindow *ui_qt_server_wnd)
    {
        ui_qt_server_wnd->setWindowTitle(QApplication::translate("ui_qt_server_wnd", "pj_server", Q_NULLPTR));
        testButton1->setText(QApplication::translate("ui_qt_server_wnd", "\346\265\213\350\257\225\344\270\200", Q_NULLPTR));
        testButton2->setText(QApplication::translate("ui_qt_server_wnd", "\346\265\213\350\257\225\344\272\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ui_qt_server_wnd: public Ui_ui_qt_server_wnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SERVER_WND_H
