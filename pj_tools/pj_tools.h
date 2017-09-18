#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_pj_tools.h"

class pj_tools : public QMainWindow
{
    Q_OBJECT

public:
    pj_tools(QWidget *parent = Q_NULLPTR);

private:
    Ui::pj_toolsClass ui;
};
