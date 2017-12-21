#pragma once
#include <QtWidgets/QMainWindow>
#include <QmessageLogger>
#include <QMap>
#include <QSet>
#include <QList>
#include <QTimer>
#include "ui_qt_server_wnd.h"
#include "LoginManager.h"

#include "MsILogin.h"
#include "MsILogin2.h"
#include "MsIScene.h"


class qt_server_wnd : public QMainWindow
{
#pragma region SLOTS
    Q_OBJECT;
    public Q_SLOTS:

    //void timeout(QPrivateSignal);

    void test0();
    void test1();
    void test2();
    void test3();
    void test4();
    void test5();
#pragma endregion

public:

public:
    virtual void closeEvent(QCloseEvent *event);
    int a = 100;
public:
    qt_server_wnd(QWidget *parent = Q_NULLPTR);
    virtual ~qt_server_wnd() { qDebug("~qt_server_wnd"); }

    //private:

        //QTimer m_QTimer;
        //QMap<::Ice::AsyncResultPtr, std::function<bool(const ::Ice::AsyncResultPtr&)>> m_setAsyncResult;
        //QMap<::Ice::AsyncResultPtr, fun_end_c2sLogin> m_setAsyncResult;
    Ui::ui_qt_server_wnd ui;
};



class ice_server_app : virtual public Ice::Application
{
public:
    ice_server_app();
    ~ice_server_app() { qDebug("~ice_server_app"); }

    virtual int run(int, char *[]);

public:
    bool init_server();

    //   ≈‰∆˜
    Ice::ObjectAdapterPtr m_Adapter;

    // µ«¬ºπ‹¿Ì∆˜
    MsNet::ILogin* m_LoginManager1;
    MsNet::ILogin* m_LoginManager2;

    //Ice::ObjectPrx m_xObjectPrx1;
    //Ice::ObjectPrx m_xObjectPrx2;

    MsILogin m_LoginPrx;
    MsILogin2 m_LoginPrx2;
    MsIScene m_ScenePrx;
    qt_server_wnd* m_MainWnd = nullptr;
};
extern ice_server_app g_ice_server_app;
extern bool aa;

