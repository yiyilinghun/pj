#pragma once

#include <QtWidgets/QWidget>

#ifdef QDESIGNER_EXPORT_WIDGETS
#define PJ_DLL_API __declspec(dllexport)
#else
#define PJ_DLL_API __declspec(dllimport)
#endif

class PJ_DLL_API pj_widget : public QWidget
{
    Q_OBJECT

public:
    pj_widget(QWidget *parent = Q_NULLPTR);


protected:
    virtual void showEvent(QShowEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void paintEvent(QPaintEvent *event);

};
