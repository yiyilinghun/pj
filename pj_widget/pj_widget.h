#pragma once

#include <QtWidgets/QWidget>

#ifdef PJ_WIDGET_EXPORTS
#define PJ_WIDGET_API __declspec(dllexport)
#else
#define PJ_WIDGET_API __declspec(dllimport)
#endif

class PJ_WIDGET_API pj_widget : public QWidget
{
    Q_OBJECT

public:
    pj_widget(QWidget *parent = Q_NULLPTR);


protected:
    virtual void paintEvent(QPaintEvent *event);

};
