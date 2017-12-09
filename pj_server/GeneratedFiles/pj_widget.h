#pragma once

#include <QtWidgets/QWidget>

class pj_widget : public QWidget
{
    Q_OBJECT

public:
    pj_widget(QWidget *parent = Q_NULLPTR);


protected:
    virtual void paintEvent(QPaintEvent *event);

};
