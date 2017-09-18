#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_pj_robot.h"

class pj_robot : public QMainWindow
{
    Q_OBJECT

public:
    pj_robot(QWidget *parent = Q_NULLPTR);

private:
    Ui::pj_robotClass ui;
};
