#include "pj_linebox.h"

pj_linebox::pj_linebox(QWidget *parent)
    : QLineEdit(parent)
{
    QPalette palette;
    palette.setColor(QPalette::ColorRole::Base, QColor(0, 0, 0, 0));
    this->setPalette(palette);
    this->setFrame(false);
}

pj_linebox::pj_linebox(QWidget *parent, bool inEditor)
    : pj_linebox(parent)
{
    this->setFrame(true);
}


