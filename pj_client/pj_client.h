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

    //// 适配器
    //Ice::ObjectAdapterPtr m_Adapter;

    //// 登录管理器
    //PJ_LoginManager* m_LoginManager;
};
extern ice_client_app g_ice_client_app;


// 登录界面
class qt_login_wnd : public pj_widget
{
    Q_OBJECT

public:
    qt_login_wnd(QWidget *parent = Q_NULLPTR);

private:
    Ui::ui_login uiLogin;
    QMediaPlayer m_QMediaPlayer;
};


// 游戏界面
class qt_scene_wnd : public QMainWindow
{
    Q_OBJECT

public:
    qt_scene_wnd(QWidget *parent = Q_NULLPTR);

private:
    Ui::ui_scene uiScene;
};

