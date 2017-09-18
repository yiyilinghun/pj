#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_pj_client.h"

class pj_client : public QMainWindow
{
    Q_OBJECT

public:
    pj_client(QWidget *parent = Q_NULLPTR);

private:
    Ui::pj_clientClass ui;
};
