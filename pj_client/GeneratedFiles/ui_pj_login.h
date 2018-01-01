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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>
#include "pj_button.h"
#include "pj_groupbox.h"
#include "pj_label.h"
#include "pj_linebox.h"
#include "pj_listview.h"
#include "pj_textbox.h"

QT_BEGIN_NAMESPACE

class Ui_ui_login
{
public:
    pj_linebox *pjtb_account;
    pj_linebox *pjtb_password;
    QFrame *f_buttons;
    QHBoxLayout *horizontalLayout;
    pj_button *pjb_register;
    pj_button *pjb_login;
    pj_label *pj_label_;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *page_2;
    QPushButton *pushButton_2;
    pj_textbox *pj_textbox_;
    pj_listview *pj_listview_;
    pj_button *pjb_register_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;

    void setupUi(pj_groupbox *ui_login)
    {
        if (ui_login->objectName().isEmpty())
            ui_login->setObjectName(QStringLiteral("ui_login"));
        ui_login->setWindowModality(Qt::NonModal);
        ui_login->setEnabled(true);
        ui_login->resize(640, 480);
        ui_login->setResKey(2904516639u);
        ui_login->setCanMove(false);
        ui_login->setProperty("auto_back_size", QVariant(true));
        pjtb_account = new pj_linebox(ui_login);
        pjtb_account->setObjectName(QStringLiteral("pjtb_account"));
        pjtb_account->setGeometry(QRect(213, 187, 266, 20));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pjtb_account->sizePolicy().hasHeightForWidth());
        pjtb_account->setSizePolicy(sizePolicy);
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
        pjtb_account->setEchoMode(QLineEdit::Normal);
        pjtb_account->setCursorMoveStyle(Qt::LogicalMoveStyle);
        pjtb_account->setClearButtonEnabled(true);
        pjtb_account->setProperty("lock_size", QVariant(true));
        pjtb_account->setProperty("tabChangesFocus", QVariant(true));
        pjtb_password = new pj_linebox(ui_login);
        pjtb_password->setObjectName(QStringLiteral("pjtb_password"));
        pjtb_password->setGeometry(QRect(213, 213, 266, 20));
        sizePolicy.setHeightForWidth(pjtb_password->sizePolicy().hasHeightForWidth());
        pjtb_password->setSizePolicy(sizePolicy);
        pjtb_password->setFont(font);
        pjtb_password->setTabletTracking(false);
        pjtb_password->setLayoutDirection(Qt::LeftToRight);
        pjtb_password->setAutoFillBackground(false);
        pjtb_password->setMaxLength(32767);
        pjtb_password->setEchoMode(QLineEdit::Password);
        pjtb_password->setCursorMoveStyle(Qt::LogicalMoveStyle);
        pjtb_password->setClearButtonEnabled(true);
        pjtb_password->setProperty("lock_size", QVariant(true));
        pjtb_password->setProperty("tabChangesFocus", QVariant(true));
        f_buttons = new QFrame(ui_login);
        f_buttons->setObjectName(QStringLiteral("f_buttons"));
        f_buttons->setGeometry(QRect(40, 235, 581, 51));
        f_buttons->setFrameShape(QFrame::StyledPanel);
        f_buttons->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(f_buttons);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pjb_register = new pj_button(f_buttons);
        pjb_register->setObjectName(QStringLiteral("pjb_register"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        QBrush brush5(QColor(0, 0, 0, 255));
        brush5.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        pjb_register->setPalette(palette);
        pjb_register->setFocusPolicy(Qt::NoFocus);
        pjb_register->setResKey(2537760430u);

        horizontalLayout->addWidget(pjb_register);

        pjb_login = new pj_button(f_buttons);
        pjb_login->setObjectName(QStringLiteral("pjb_login"));
        pjb_login->setFocusPolicy(Qt::NoFocus);
        pjb_login->setResKey(464918913u);

        horizontalLayout->addWidget(pjb_login);

        pj_label_ = new pj_label(ui_login);
        pj_label_->setObjectName(QStringLiteral("pj_label_"));
        pj_label_->setGeometry(QRect(20, 20, 601, 121));
        QPalette palette1;
        QBrush brush7(QColor(255, 0, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        QBrush brush8(QColor(120, 120, 120, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        pj_label_->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(24);
        pj_label_->setFont(font1);
        pj_label_->setAlignment(Qt::AlignCenter);
        toolBox = new QToolBox(ui_login);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(480, 30, 141, 121));
        QPalette palette2;
        QBrush brush9(QColor(240, 240, 240, 0));
        brush9.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush9);
        QBrush brush10(QColor(255, 255, 255, 0));
        brush10.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush10);
        QBrush brush11(QColor(0, 0, 0, 0));
        brush11.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        toolBox->setPalette(palette2);
        toolBox->setFrameShape(QFrame::Box);
        toolBox->setLineWidth(5);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 131, 59));
        toolBox->addItem(page, QStringLiteral("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 131, 59));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 10, 75, 23));
        toolBox->addItem(page_2, QStringLiteral("Page 2"));
        pj_textbox_ = new pj_textbox(ui_login);
        pj_textbox_->setObjectName(QStringLiteral("pj_textbox_"));
        pj_textbox_->setGeometry(QRect(10, 300, 481, 171));
        pj_listview_ = new pj_listview(pj_textbox_);
        pj_listview_->setObjectName(QStringLiteral("pj_listview_"));
        pj_listview_->setGeometry(QRect(360, 100, 237, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush10);
        QBrush brush12(QColor(240, 240, 240, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        pj_listview_->setPalette(palette3);
        pj_listview_->setFrameShape(QFrame::Box);
        pj_listview_->setLineWidth(5);
        pjb_register_2 = new pj_button(ui_login);
        pjb_register_2->setObjectName(QStringLiteral("pjb_register_2"));
        pjb_register_2->setGeometry(QRect(500, 420, 121, 35));
        QPalette palette4;
        QBrush brush13(QColor(0, 0, 0, 255));
        brush13.setStyle(Qt::NoBrush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush13);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush14(QColor(0, 0, 0, 255));
        brush14.setStyle(Qt::NoBrush);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush14);
        QBrush brush15(QColor(0, 0, 0, 255));
        brush15.setStyle(Qt::NoBrush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush15);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        QBrush brush16(QColor(0, 0, 0, 255));
        brush16.setStyle(Qt::NoBrush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush16);
        QBrush brush17(QColor(0, 0, 0, 255));
        brush17.setStyle(Qt::NoBrush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        QBrush brush18(QColor(0, 0, 0, 255));
        brush18.setStyle(Qt::NoBrush);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush18);
        pjb_register_2->setPalette(palette4);
        pjb_register_2->setFocusPolicy(Qt::NoFocus);
        pjb_register_2->setResKey(2537760430u);
        pushButton_3 = new QPushButton(ui_login);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(550, 170, 75, 23));
        pushButton = new QPushButton(ui_login);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(560, 210, 75, 23));
        QWidget::setTabOrder(pjtb_account, pjtb_password);
        QWidget::setTabOrder(pjtb_password, pjb_register);

        retranslateUi(ui_login);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ui_login);
    } // setupUi

    void retranslateUi(pj_groupbox *ui_login)
    {
        ui_login->setWindowTitle(QApplication::translate("ui_login", "PJ\347\231\273\345\275\225", nullptr));
        ui_login->setResFileName(QApplication::translate("ui_login", "A:\\git\\pj\\res\\gires3.wdf", nullptr));
        pjtb_account->setText(QString());
        pjtb_password->setInputMask(QString());
        pjtb_password->setText(QString());
        pjb_register->setResFileName(QApplication::translate("ui_login", "A:\\git\\pj\\res\\gires3.wdf", nullptr));
        pjb_login->setResFileName(QApplication::translate("ui_login", "A:\\git\\pj\\res\\gires3.wdf", nullptr));
        pj_label_->setText(QApplication::translate("ui_login", "\346\265\213\350\257\225\346\240\207\351\242\230\346\241\206", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("ui_login", "Page 1", nullptr));
        pushButton_2->setText(QApplication::translate("ui_login", "PushButton", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("ui_login", "Page 2", nullptr));
        pj_textbox_->setHtml(QApplication::translate("ui_login", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">fadsfas</span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">\351\230\277\346\226\257\350\222\202\350\212\254\347\232\204\350\220\250\350\212\254\345\260\261</span><span style=\" font-size:18pt; font-weight:600;\">\346\265\201\345\217\243\346\260\264\347\232\204</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-inde"
                        "nt:0px;\"><span style=\" font-size:18pt;\">\350\267\235\347\246\273</span><span style=\" font-size:18pt; font-style:italic;\">\345\226\200\344\273\200</span><span style=\" font-size:18pt;\">\345\234\260\347\210\261\347\232\204\350\211\262\346\224\276\347\210\261\347\232\204\350\211\262\346\224\276\346\226\271</span><span style=\" font-size:18pt; text-decoration: underline;\">\345\260\261</span><span style=\" font-size:18pt;\">\350\200\203\350\231\221</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">\345\217\221</span><span style=\" font-size:18pt; color:#ff0000;\">\350\276\276\347\234\201\344\273\275\346\230\257\346\224\276\345\244\247\346\224\276\345\244\247\347\232\204\350\257\264\346\263\225</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; color:#000000;\">\351\230\277\346\226"
                        "\257\350\222\202\350\212\254\351\230\277\346\226\257\350\222\202\350\212\254</span><img src=\":/1/\346\227\240\346\240\207\351\242\230.png\" /></p></body></html>", nullptr));
        pj_textbox_->setPlaceholderText(QString());
        pjb_register_2->setResFileName(QApplication::translate("ui_login", "A:\\git\\pj\\res\\gires3.wdf", nullptr));
        pushButton_3->setText(QApplication::translate("ui_login", "PushButton", nullptr));
        pushButton->setText(QApplication::translate("ui_login", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ui_login: public Ui_ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PJ_LOGIN_H
