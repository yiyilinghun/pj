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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ui_qt_server_wnd
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ui_qt_server_wnd)
    {
        if (ui_qt_server_wnd->objectName().isEmpty())
            ui_qt_server_wnd->setObjectName(QStringLiteral("ui_qt_server_wnd"));
        ui_qt_server_wnd->resize(600, 400);
        centralWidget = new QWidget(ui_qt_server_wnd);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ui_qt_server_wnd->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ui_qt_server_wnd);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        ui_qt_server_wnd->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ui_qt_server_wnd);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ui_qt_server_wnd->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ui_qt_server_wnd);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ui_qt_server_wnd->setStatusBar(statusBar);

        retranslateUi(ui_qt_server_wnd);

        QMetaObject::connectSlotsByName(ui_qt_server_wnd);
    } // setupUi

    void retranslateUi(QMainWindow *ui_qt_server_wnd)
    {
        ui_qt_server_wnd->setWindowTitle(QApplication::translate("ui_qt_server_wnd", "pj_server", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ui_qt_server_wnd: public Ui_ui_qt_server_wnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SERVER_WND_H
