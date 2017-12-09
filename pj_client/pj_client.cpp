#include "pj_client.h"

ice_client_app g_ice_client_app;

ice_client_app::ice_client_app()
//: m_LoginManager(nullptr)
{
    ;
}

MemoryDictionary<mstr, Ice::CommunicatorPtr> g_CommunicatorPtr;
MemoryDictionary<mstr, Ice::ObjectPrx> g_ObjectPrx;
MemoryDictionary<mstr, MsNet::ILoginPrx> g_LoginPrx;

bool
ice_client_app::init_client()
{
    try
    {
        //g_CommunicatorPtr["main"] = this->communicator();

        //g_ObjectPrx["main"]
        //    = g_CommunicatorPtr["main"]->stringToProxy("PJ:udp - p 10000");

        //g_LoginPrx["main"]
        //    = MsNet::ILoginPrx::checkedCast(g_ObjectPrx["main"]);

        //if (g_LoginPrx["main"])
        //{
        //    ::MsNet::Login xParam;
        //    xParam.account = "1";
        //    xParam.password = "1";
        //    xParam.Info = "1";

        //    if (g_LoginPrx["main"]->c2sLogin(xParam))
        //    {
        //        qDebug("ok");
        //    }
        //    else
        //    {
        //        qDebug("no");
        //    }
        //    return (INT_PTR)TRUE;
        //}

        //Ice::CommunicatorPtr xCommunicatorPtr = this->communicator();
        //if (xCommunicatorPtr)
        //{
        //    Ice::ObjectAdapterPtr xAdapter
        //        = xCommunicatorPtr->createObjectAdapterWithEndpoints("PJ", "default");
        //}
        //            Freeze::ConnectionPtr xFreezeConnection
        //                = Freeze::createConnection(xCommunicatorPtr, "../../pj_db");
        //
        //            if (xAdapter && xFreezeConnection)
        //            {
        //                m_LoginManager = NEW PJ_LoginManager(xAdapter, xFreezeConnection);
        //            }
        //
        //            xAdapter->activate();
        //
        //            ThreadTest* xThread = new ThreadTest(m_LoginManager, 0);
        //            xThread->start(QThread::HighestPriority);
        //
        //            for (int32_t i = 1; i < 7; i++)
        //            {
        //                ThreadTest* xThread = new ThreadTest(m_LoginManager, i);
        //                xThread->start(QThread::NormalPriority);
        //            }
        //        }
        //        return True;
    }
    catch (IceUtil::Exception& ex)
    {
        qDebug(ex.what());
        ex.ice_throw();
    }
    catch (std::exception& ex)
    {
        qDebug(ex.what());
        throw ex.what();
    }
    return False;
}

int
ice_client_app::run(int argc, char* argv[])
{
    QApplication a(argc, argv);
    qt_client_wnd w;
    w.show();
    return a.exec();
}



qt_client_wnd::qt_client_wnd(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    g_ice_client_app.init_client();
}
