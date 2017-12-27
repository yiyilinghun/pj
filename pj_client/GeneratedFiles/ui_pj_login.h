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
#include "pj_button.h"
#include "pj_linebox.h"
#include "pj_widget.h"

QT_BEGIN_NAMESPACE

class Ui_ui_login
{
public:
    pj_linebox *pjtb_account;
    pj_linebox *pjtb_password;
    pj_button *pj_button_;
    pj_button *pj_button_1;

    void setupUi(pj_widget *ui_login)
    {
        if (ui_login->objectName().isEmpty())
            ui_login->setObjectName(QStringLiteral("ui_login"));
        ui_login->resize(640, 480);
        ui_login->setResKey(2904516639u);
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
        pj_button_ = new pj_button(ui_login);
        pj_button_->setObjectName(QStringLiteral("pj_button_"));
        pj_button_->setGeometry(QRect(40, 370, 121, 35));
        QPalette palette2;
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::NoBrush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush3);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush4);
        QBrush brush5(QColor(0, 0, 0, 255));
        brush5.setStyle(Qt::NoBrush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush5);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::NoBrush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush4);
        QBrush brush7(QColor(0, 0, 0, 255));
        brush7.setStyle(Qt::NoBrush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        QBrush brush8(QColor(0, 0, 0, 255));
        brush8.setStyle(Qt::NoBrush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush4);
        QBrush brush9(QColor(0, 0, 0, 255));
        brush9.setStyle(Qt::NoBrush);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        pj_button_->setPalette(palette2);
        pj_button_->setResKey(2537760430u);
        pj_button_1 = new pj_button(ui_login);
        pj_button_1->setObjectName(QStringLiteral("pj_button_1"));
        pj_button_1->setGeometry(QRect(50, 330, 121, 35));
        QPalette palette3;
        QBrush brush10(QColor(0, 0, 0, 255));
        brush10.setStyle(Qt::NoBrush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush10);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush4);
        QBrush brush11(QColor(0, 0, 0, 255));
        brush11.setStyle(Qt::NoBrush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush11);
        QBrush brush12(QColor(0, 0, 0, 255));
        brush12.setStyle(Qt::NoBrush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush4);
        QBrush brush13(QColor(0, 0, 0, 255));
        brush13.setStyle(Qt::NoBrush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        QBrush brush14(QColor(0, 0, 0, 255));
        brush14.setStyle(Qt::NoBrush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush4);
        QBrush brush15(QColor(0, 0, 0, 255));
        brush15.setStyle(Qt::NoBrush);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush15);
        pj_button_1->setPalette(palette3);
        pj_button_1->setResKey(464918913u);

        retranslateUi(ui_login);

        QMetaObject::connectSlotsByName(ui_login);
    } // setupUi

    void retranslateUi(pj_widget *ui_login)
    {
        ui_login->setWindowTitle(QApplication::translate("ui_login", "PJ\347\231\273\345\275\225", nullptr));
        ui_login->setResFileName(QApplication::translate("ui_login", "A:\\git\\pj\\res\\gires3.wdf", nullptr));
        pjtb_account->setText(QString());
        pjtb_password->setInputMask(QString());
        pjtb_password->setText(QString());
        pj_button_->setResFileName(QApplication::translate("ui_login", "A:\\git\\pj\\res\\gires3.wdf", nullptr));
        pj_button_1->setResFileName(QApplication::translate("ui_login", "A:\\git\\pj\\res\\gires3.wdf", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ui_login: public Ui_ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PJ_LOGIN_H
