/********************************************************************************
** Form generated from reading UI file 'pj_login.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PJ_LOGIN_H
#define UI_PJ_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include "pj_linebox.h"
#include "pj_widget.h"

QT_BEGIN_NAMESPACE

class Ui_ui_login
{
public:
    pj_linebox *pjtb_account;
    pj_linebox *pjtb_password;

    void setupUi(pj_widget *ui_login)
    {
        if (ui_login->objectName().isEmpty())
            ui_login->setObjectName(QStringLiteral("ui_login"));
        ui_login->resize(640, 480);
        pjtb_account = new pj_linebox(ui_login);
        pjtb_account->setObjectName(QStringLiteral("pjtb_account"));
        pjtb_account->setGeometry(QRect(213, 187, 266, 20));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pjtb_account->sizePolicy().hasHeightForWidth());
        pjtb_account->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(0, 255, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        pjtb_account->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font.setPointSize(13);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferAntialias);
        pjtb_account->setFont(font);
        pjtb_account->setTabletTracking(false);
        pjtb_account->setLayoutDirection(Qt::LeftToRight);
        pjtb_account->setAutoFillBackground(false);
        pjtb_account->setFrame(false);
        pjtb_account->setEchoMode(QLineEdit::Normal);
        pjtb_account->setCursorMoveStyle(Qt::LogicalMoveStyle);
        pjtb_account->setClearButtonEnabled(true);
        pjtb_account->setProperty("tabChangesFocus", QVariant(true));
        pjtb_password = new pj_linebox(ui_login);
        pjtb_password->setObjectName(QStringLiteral("pjtb_password"));
        pjtb_password->setGeometry(QRect(213, 213, 266, 20));
        sizePolicy.setHeightForWidth(pjtb_password->sizePolicy().hasHeightForWidth());
        pjtb_password->setSizePolicy(sizePolicy);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        pjtb_password->setPalette(palette1);
        pjtb_password->setFont(font);
        pjtb_password->setTabletTracking(false);
        pjtb_password->setLayoutDirection(Qt::LeftToRight);
        pjtb_password->setAutoFillBackground(false);
        pjtb_password->setMaxLength(32767);
        pjtb_password->setFrame(false);
        pjtb_password->setEchoMode(QLineEdit::Password);
        pjtb_password->setCursorMoveStyle(Qt::LogicalMoveStyle);
        pjtb_password->setClearButtonEnabled(true);
        pjtb_password->setProperty("tabChangesFocus", QVariant(true));

        retranslateUi(ui_login);

        QMetaObject::connectSlotsByName(ui_login);
    } // setupUi

    void retranslateUi(pj_widget *ui_login)
    {
        ui_login->setWindowTitle(QApplication::translate("ui_login", "PJ\347\231\273\345\275\225", nullptr));
        pjtb_account->setText(QString());
        pjtb_password->setInputMask(QString());
        pjtb_password->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ui_login: public Ui_ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PJ_LOGIN_H
