#include "pj_textbox.h"

pj_textbox::pj_textbox(QWidget *parent)
    : QTextEdit(parent)
{
    QPalette palette;
    palette.setColor(QPalette::ColorRole::Base, QColor(0, 0, 0, 0));
    this->setPalette(palette);
    //this->setFrame(false);
}


pj_textbox::pj_textbox(QWidget *parent, bool inEditor)
    : pj_textbox(parent)
{
    //this->setFrame(true);
}


