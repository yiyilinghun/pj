#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_pj_client.h"

class ice_client_app : virtual public Ice::Application
{
public:
    ice_client_app();

    virtual int run(int, char *[]);

public:
    bool init_client();

    //// ÊÊÅäÆ÷
    //Ice::ObjectAdapterPtr m_Adapter;

    //// µÇÂ¼¹ÜÀíÆ÷
    //PJ_LoginManager* m_LoginManager;
};
extern ice_client_app g_ice_client_app;


class qt_client_wnd : public QMainWindow
{
    Q_OBJECT

public:
    qt_client_wnd(QWidget *parent = Q_NULLPTR);

private:
    Ui::pj_clientClass ui;
};
