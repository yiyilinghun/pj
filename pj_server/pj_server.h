#pragma once

#include <QtWidgets/QMainWindow>
#include <QmessageLogger>
#include "ui_qt_server_wnd.h"
#include "LoginManager.h"


class ice_server_app : virtual public Ice::Application
{
public:
    ice_server_app();

    virtual int run(int, char *[]);

public:
    bool init_server();

    //   ≈‰∆˜
    Ice::ObjectAdapterPtr m_Adapter;

    // µ«¬ºπ‹¿Ì∆˜
    PJ_LoginManager* m_LoginManager;
};
extern ice_server_app g_ice_server_app;


class qt_server_wnd : public QMainWindow
{

#pragma region SLOTS
    Q_OBJECT;
    public Q_SLOTS:

    void test0() {
        qDebug("test0");
    }
    void test1() {
        qDebug("test1");
    }
    void test2() {
        qDebug("test2");
    }
    void test3() {
        qDebug("test3");
    }
    void test4() {
        qDebug("test4");
    }
    void test5() {
        qDebug("test5");
    }
#pragma endregion

public:
    virtual void closeEvent(QCloseEvent *event);
    int a = 100;
public:
    qt_server_wnd(QWidget *parent = Q_NULLPTR);

private:
    Ui::ui_qt_server_wnd ui;
};

