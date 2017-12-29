#include "pj_listview.h"

pj_listview::pj_listview(QWidget *parent)
    : QListView(parent)
{
    this->setFrameShape(QFrame::Shape::NoFrame);
}

pj_listview::pj_listview(QWidget *parent, bool inEditor)
    : QListView(parent)
{
    QPalette palette;
    palette.setColor(QPalette::ColorRole::Base, QColor(0, 0, 0, 0));
    this->setPalette(palette);
    this->setFrameShape(QFrame::Shape::StyledPanel);
}


