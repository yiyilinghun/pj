#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_pj_client.h"
#include "ui_pj_login.h"

class ice_client_app : virtual public Ice::Application
{
public:
    ice_client_app();

    virtual int run(int, char *[]);

public:
    bool init_client();

    //// ������
    //Ice::ObjectAdapterPtr m_Adapter;

    //// ��¼������
    //PJ_LoginManager* m_LoginManager;
};
extern ice_client_app g_ice_client_app;


// ��¼����
class qt_login_wnd : public pj_widget
{
    Q_OBJECT

public:
    qt_login_wnd(QWidget *parent = Q_NULLPTR);

private:
    Ui::ui_login uiLogin;
    QMediaPlayer m_QMediaPlayer;
};


// ��Ϸ����
class qt_scene_wnd : public QMainWindow
{
    Q_OBJECT

public:
    qt_scene_wnd(QWidget *parent = Q_NULLPTR);

private:
    Ui::ui_scene uiScene;
};

