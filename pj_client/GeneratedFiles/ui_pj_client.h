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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ui_scene
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *ui_scene)
    {
        if (ui_scene->objectName().isEmpty())
            ui_scene->setObjectName(QStringLiteral("ui_scene"));
        ui_scene->resize(943, 622);
        centralWidget = new QWidget(ui_scene);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ui_scene->setCentralWidget(centralWidget);

        retranslateUi(ui_scene);

        QMetaObject::connectSlotsByName(ui_scene);
    } // setupUi

    void retranslateUi(QMainWindow *ui_scene)
    {
        ui_scene->setWindowTitle(QApplication::translate("ui_scene", "PJ\345\234\272\346\231\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ui_scene: public Ui_ui_scene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PJ_CLIENT_H
