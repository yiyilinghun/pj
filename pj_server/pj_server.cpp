#include "pj_server.h"

ice_server_app g_ice_server_app;

ice_server_app::ice_server_app()
    : m_LoginManager(nullptr)
{
    ;
}

bool ice_server_app::init_server()
{
    try
    {
        Ice::CommunicatorPtr xCommunicatorPtr = this->communicator();
        if (xCommunicatorPtr)
        {
            Ice::ObjectAdapterPtr xAdapter
                = xCommunicatorPtr->createObjectAdapterWithEndpoints("PJ", "default -h 0.0.0.0 -p 10000");

            Freeze::ConnectionPtr xFreezeConnection
                = Freeze::createConnection(xCommunicatorPtr, "pj_db");

            if (xAdapter && xFreezeConnection)
            {
                m_LoginManager = NEW PJ_LoginManager(xAdapter, xFreezeConnection);
            }

            xAdapter->activate();

            for (int i = 0; i < 1000000; i++)
            {
                QString x = QString("%1").arg(i, 8, 10, QChar('0'));
                this->m_LoginManager->local_Register(x.toStdString(), x.toStdString());
            }
        }
        return True;
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
ice_server_app::run(int argc, char* argv[])
{
    QApplication a(argc, argv);
    qt_server_wnd w;
    w.show();
    return a.exec();
}

qt_server_wnd::qt_server_wnd(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    g_ice_server_app.init_server();
}

void qt_server_wnd::closeEvent(QCloseEvent *event)
{
    switch (QMessageBox::information(this, u8"提示", u8"你确定退出该软件?", u8"确定", u8"取消", 0, 1))
    {
        case 0:
        {
            g_ice_server_app.communicator()->shutdown();
            g_ice_server_app.communicator()->waitForShutdown();
            g_ice_server_app.communicator()->destroy();
            event->accept();
        }break;

        case 1:
        default:
        {
            event->ignore();
        }break;
    }
}
