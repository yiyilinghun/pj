#pragma once
#include <QtWidgets/QMainWindow>
#include <QmessageLogger>
#include <QMap>
#include <QSet>
#include <QList>
#include <QTimer>
#include "ui_qt_server_wnd.h"
#include "LoginManager.h"


#pragma region ICE_PRC远程调用1参,0返
#define ICE_CALL1_RET0(rpc_call,pt1)  bool rpc_call(const pt1&, const ::Ice::Context& context = Ice::noExplicitContext);\
typedef pt1 rpc_call##p1;\
bool ice_default_exe##rpc_call(bool _ice_result, const pt1 p1);\
void ms##rpc_call(const pt1 p1)\
{\
    m_setAsyncResult.insert(m_Prx->begin_##rpc_call(p1), \
    [=](const ::Ice::AsyncResultPtr& xAsynResult){\
    bool _ice_result = m_Prx->end_##rpc_call(xAsynResult);\
    return ice_default_exe##rpc_call(_ice_result, p1);});\
}\
void ms##rpc_call(const pt1 p1, std::function<bool(bool, const pt1)> lambdac_all)\
{\
    m_setAsyncResult.insert(m_Prx->begin_##rpc_call(p1), \
    [=](const ::Ice::AsyncResultPtr& xAsynResult){\
    bool _ice_result = m_Prx->end_##rpc_call(xAsynResult);\
    return lambdac_all(_ice_result, p1);});\
}
#define ICE_DIY_CALL1_RET0(_prx, rpc_call, _p1) _prx.ms##rpc_call(_p1, [=](bool ice_ret, decltype(_prx)::rpc_call##p1 p1)
#pragma endregion

#pragma region ICE_PRC远程调用1参,1返
#define ICE_CALL1_RET1(rpc_call,pt1,rt1)  bool rpc_call(const pt1&, const ::Ice::Context& context = Ice::noExplicitContext);\
typedef pt1 rpc_call##p1;\
typedef rt1 rpc_call##r1;\
bool ice_default_exe##rpc_call(bool _ice_result, const pt1 p1, const rt1 r1);\
void ms##rpc_call(const pt1 p1)\
{\
    m_setAsyncResult.insert(m_Prx->begin_##rpc_call(p1), \
    [=](const ::Ice::AsyncResultPtr& xAsynResult){\
    rt1 r1;\
    bool _ice_result = m_Prx->end_##rpc_call(r1, xAsynResult);\
    return ice_default_exe##rpc_call(_ice_result, p1, r1);});\
}\
void ms##rpc_call(const pt1 p1, std::function<bool(bool, const pt1, const rt1)> lambdac_all)\
{\
    m_setAsyncResult.insert(m_Prx->begin_##rpc_call(p1), \
    [=](const ::Ice::AsyncResultPtr& xAsynResult){\
    rt1 r1;\
    bool _ice_result = m_Prx->end_##rpc_call(r1, xAsynResult);\
    return lambdac_all(_ice_result, p1, r1);});\
}
#define ICE_DIY_CALL1_RET1(_prx, rpc_call, _p1) _prx.ms##rpc_call(_p1, [=](bool ice_ret, decltype(_prx)::rpc_call##p1 p1, decltype(_prx)::rpc_call##r1 r1)
#pragma endregion

#pragma region ICE_PRC远程调用1参,2返
#define ICE_CALL1_RET2(rpc_call,pt1,rt1,rt2)  bool rpc_call(const pt1&, const ::Ice::Context& context = Ice::noExplicitContext);\
typedef pt1 rpc_call##p1;\
typedef rt1 rpc_call##r1;\
typedef rt2 rpc_call##r2;\
bool ice_default_exe##rpc_call(bool _ice_result, const pt1 p1, const rt1 r1, const rt2 r2);\
void ms##rpc_call(const pt1 p1)\
{\
    m_setAsyncResult.insert(m_Prx->begin_##rpc_call(p1), \
    [=](const ::Ice::AsyncResultPtr& xAsynResult){\
    rt1 r1;\
    rt2 r2;\
    bool _ice_result = m_Prx->end_##rpc_call(r1, r2, xAsynResult);\
    return ice_default_exe##rpc_call(_ice_result, p1, r1, r2);});\
}
#define ICE_DIY_CALL1_RET2(_prx, rpc_call, _p1) _prx.ms##rpc_call(_p1, [=](bool ice_ret, decltype(_prx)::rpc_call##p1 p1, decltype(_prx)::rpc_call##r1 r1, decltype(_prx)::rpc_call##r2 r2)
#pragma endregion



#pragma region ICE_PRC远程调用2参,0返
#define ICE_CALL2_RET0(rpc_call,pt1,pt2)  bool rpc_call(const pt1&, const pt2&, const ::Ice::Context& context = Ice::noExplicitContext);\
bool ms_exe##rpc_call(bool _ice_result, const pt1 p1, const pt2 p2);\
void ms##rpc_call(const pt1 p1, const pt2 p2)\
{\
    m_setAsyncResult.insert(m_Prx->begin_##rpc_call(p1, p2), \
    [=](const ::Ice::AsyncResultPtr& xAsynResult){\
    bool _ice_result = m_Prx->end_##rpc_call(xAsynResult);\
    return ms_exe##rpc_call(_ice_result, p1, p2);});\
}
#pragma endregion

#pragma region ICE_PRC远程调用2参,1返
#define ICE_CALL2_RET1(rpc_call,pt1,pt2,rt1)  bool rpc_call(const pt1&, const pt2&, const ::Ice::Context& context = Ice::noExplicitContext);\
bool ms_exe##rpc_call(bool _ice_result, const pt1 p1,const pt2 p2, const rt1 r1);\
void ms##rpc_call(const pt1 p1, const pt2 p2)\
{\
    m_setAsyncResult.insert(m_Prx->begin_##rpc_call(p1, p2), \
    [=](const ::Ice::AsyncResultPtr& xAsynResult){\
    rt1 r1;\
    bool _ice_result = m_Prx->end_##rpc_call(r1, xAsynResult);\
    return ms_exe##rpc_call(_ice_result, p1, p2, r1);});\
}
#pragma endregion

template<class ICE_T>
class ICE_CALL_ASSIST : public QObject
{
protected:
    void _ice_call_tick()
    {
        if (m_setAsyncResult.size() == 0) { return; }

        QList<::Ice::AsyncResultPtr> xTempList;
        QMapIterator<::Ice::AsyncResultPtr, std::function<bool(const ::Ice::AsyncResultPtr&)>> itmap(m_setAsyncResult);
        while (itmap.hasNext())
        {
            auto xPair = itmap.next();
            ::Ice::AsyncResultPtr xKey = xPair.key();
            std::function<bool(const ::Ice::AsyncResultPtr&)> xValue = xPair.value();
            if (xKey->isCompleted())
            {
                xTempList.push_back(xKey);
                IceProxy::MsNet::ILogin& xTemp = *(g_ice_server_app.m_LoginPrx1.m_Prx.get());
                if (xValue(xKey))
                {
                    qDebug(u8"成功");
                }
                else
                {
                    qDebug(u8"失败");
                }
                qDebug(u8"Completed");
            }
        }

        QListIterator<::Ice::AsyncResultPtr> itlist(xTempList);
        while (itlist.hasNext())
        {
            m_setAsyncResult.remove(itlist.next());
        }
    }
public:
    ICE_T m_Prx;
    QTimer m_QTimer;
    QMap<::Ice::AsyncResultPtr, std::function<bool(const ::Ice::AsyncResultPtr&)>> m_setAsyncResult;
};

class MsNetLogin
    : public ICE_CALL_ASSIST<MsNet::ILoginPrx>
{
#pragma region BASE_AND_SLOTS
    Q_OBJECT;
    public Q_SLOTS:
public:
    void begin(int32_t msec = 1)
    {
        m_QTimer.setInterval(msec);
        QObject::connect(&m_QTimer, &QTimer::timeout, this, &MsNetLogin::ice_call_tick);
        m_QTimer.start();
    }

    void ice_call_tick() { return this->_ice_call_tick(); }
#pragma endregion

public:

    ICE_CALL1_RET0(p1r0,
        std::string
    );

    ICE_CALL1_RET1(c2sLogin,
        MsNet::Login,
        int32_t
    );

    ICE_CALL1_RET2(c2sRegister,
        MsNet::Login,
        int32_t,
        MsNet::Login
    );

    ICE_CALL1_RET1(c2sxqCall,
        std::string,
        qint32
    );
    //c2sxqCallp1
};


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

    // 适配器
    Ice::ObjectAdapterPtr m_Adapter;

    // 登录管理器
    MsNet::ILogin* m_LoginManager1;
    MsNet::ILogin* m_LoginManager2;

    //Ice::ObjectPrx m_xObjectPrx1;
    //Ice::ObjectPrx m_xObjectPrx2;

    MsNetLogin m_LoginPrx1;
    qt_server_wnd* m_MainWnd = nullptr;

};
extern ice_server_app g_ice_server_app;
extern bool aa;
