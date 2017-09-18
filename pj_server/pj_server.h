#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_pj_server.h"

class pj_server : public QMainWindow
{
    Q_OBJECT

public:
    pj_server(QWidget *parent = Q_NULLPTR);

private:
    Ui::pj_serverClass ui;
};
