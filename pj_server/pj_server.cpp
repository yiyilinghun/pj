#include "pj_server.h"
#include <QTimer>
#include <QThread>
#include <IceGrid/Registry.h>
#include "pj_loader.h"

class ThreadTest : public QThread
{
public:
    ThreadTest(PJ_LoginManager* xLoginManager, int32_t index)
        : m_LoginManager(xLoginManager)
        , m_index(index)
    {

    }

    virtual void run()
    {
        //if (m_index == 0)
        //{
        //    double xBegin = (double)clock();
        //    for (int i = 74057; i < 10000000; i++)
        //    {
        //        QString x = QString(u8"%1").arg(i, 8, 10, QChar('0'));
        //        this->m_LoginManager->local_Register(x.toStdString(), x.toStdString());
        //        if (i % 100 == 0)
        //        {
        //            qDebug(QString(u8"写入数据总量%1个\n").arg(this->m_LoginManager->m_writeDictData.GetCount()).toStdString().c_str());
        //        }
        //        this->m_LoginManager->update_count();
        //    }
        //    double xEnd = (double)clock();
        //    qDebug(QString(u8"写入10000次耗时%1秒\n").arg((xEnd / CLOCKS_PER_SEC) - (xBegin / CLOCKS_PER_SEC)).toStdString().c_str());
        //}
        //else
        //{
        //    int32_t ok = 0;
        //    int32_t failed = 0;
        //    double xBegin = clock();
        //    for (int i = 0; i < 10000000; i++)
        //    {
        //        QString x = QString(u8"%1").arg(i, 8, 10, QChar('0'));
        //        if (!this->m_LoginManager->local_Login(x.toStdString(), x.toStdString(), m_index))
        //        {
        //            failed++;
        //        }
        //        else
        //        {
        //            ok++;
        //        }

        //        if (i % 100 == 0)
        //        {
        //            qDebug(QString(u8"失败%1次,成功%2次\n").arg(failed).arg(ok).toStdString().c_str());
        //        }
        //        if (i > m_LoginManager->m_count - 1000)
        //        {
        //            qDebug(QString(u8"读完了,我等着呢\n").toStdString().c_str());
        //            i = 0;
        //        }
        //    }
        //    double xEnd = clock();
        //    qDebug(QString(u8"读取10000次耗时%1秒\n").arg((xEnd / CLOCKS_PER_SEC) - (xBegin / CLOCKS_PER_SEC)).toStdString().c_str());
        //}
    }

    PJ_LoginManager* m_LoginManager;
    int32_t m_count;
    int32_t m_index;
};

ice_server_app g_ice_server_app;
bool aa = true;

ice_server_app::ice_server_app()
    : m_LoginManager1(nullptr)
    , m_LoginManager2(nullptr)
{
    ;
}

bool
ice_server_app::init_server()
{
    try
    {
        Ice::CommunicatorPtr xCommunicatorPtr = this->communicator();
        if (xCommunicatorPtr)
        {
            if (aa)
            {
                Ice::ObjectAdapterPtr xAdapter1
                    = xCommunicatorPtr->createObjectAdapterWithEndpoints("PJ1", "tcp -h * -p 10000");

                Freeze::ConnectionPtr xFreezeConnection
                    = Freeze::createConnection(xCommunicatorPtr, "../../pj_db1");

                if (xAdapter1 && xFreezeConnection)
                {
                    m_LoginManager1 = NEW PJ_LoginManager(xAdapter1, "PJ1");
                }

                xAdapter1->activate();
            }
            else
            {

                Ice::ObjectAdapterPtr xAdapter1
                    = xCommunicatorPtr->createObjectAdapterWithEndpoints("PJ2", "tcp -h * -p 10001");

                Freeze::ConnectionPtr xFreezeConnection
                    = Freeze::createConnection(xCommunicatorPtr, "../../pj_db2");

                if (xAdapter1 && xFreezeConnection)
                {
                    m_LoginManager1 = NEW PJ_LoginManager(xAdapter1, "PJ2");
                }

                xAdapter1->activate();


                //auto base = this->communicator()->stringToProxy("IceGrid/Registry:tcp -p 1234");
                //auto registry = Ice::checkedCast<IceGrid::RegistryPrx>(base);
                //::std::string username = "root";
                //::std::string password = "root";
                //try
                //{
                //    ::IceGrid::AdminSessionPrx session = registry->createAdminSession(username, password);
                //}
                //catch (const IceGrid::PermissionDeniedException& ex)
                //{
                //    //cout << "permission denied:\n" << ex.reason << endl;
                //}



            }
            return True;
        }
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

void
setHighDpiEnvironmentVariable()
{
    static const char ENV_VAR_QT_DEVICE_PIXEL_RATIO[] = "QT_DEVICE_PIXEL_RATIO";
    if (!qEnvironmentVariableIsSet(ENV_VAR_QT_DEVICE_PIXEL_RATIO) // legacy in 5.6, but still functional
        && !qEnvironmentVariableIsSet("QT_AUTO_SCREEN_SCALE_FACTOR")
        && !qEnvironmentVariableIsSet("QT_SCALE_FACTOR")
        && !qEnvironmentVariableIsSet("QT_SCREEN_SCALE_FACTORS")) {
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    }
}

int
ice_server_app::run(int argc, char* argv[])
{
    setHighDpiEnvironmentVariable();
    QApplication a(argc, argv);
    std::shared_ptr<qt_server_wnd> mainWnd(LAMBDA_AUTO_NEW_DELETE(qt_server_wnd));
    m_MainWnd = mainWnd.get();
    mainWnd->show();
    return a.exec();
}



qt_server_wnd::qt_server_wnd(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QRect clientRect = this->geometry();
    clientRect.setWidth(640);
    clientRect.setHeight(480);
    this->setGeometry(clientRect);
    this->move((QApplication::desktop()->width() - this->width()) / 2, (QApplication::desktop()->height() - this->height()) / 2);

    //xyTextureInfo m_backTextureInfo;
    //if (!pj_GetResManager().pjLoadFile(u8R"(A:\git\pj\res\gires3.wdf)", 100))
    //{
    //    return;
    //}

    //quint64 tempKey = (((quint64)100) << 32) + 578293861;
    //QVector<QImage*> imageVector;
    //if (!pj_GetResManager().pjGetWasTextures(tempKey, m_backTextureInfo, imageVector))
    //{
    //    return;
    //}
    //if (imageVector.size() == 1)
    //{
    //    QImage* xImage = imageVector[0];
    //    QPainter xQPainter(xImage);
    //    xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"嗝屁了");
    //    QPalette palette;
    //    palette.setBrush(QPalette::ColorRole::Background, QBrush(*xImage));
    //    ui.groupBox->setAutoFillBackground(true);
    //    ui.groupBox->setPalette(palette);
    //}
    g_ice_server_app.init_server();
}

void qt_server_wnd::closeEvent(QCloseEvent *event)
{
    return;
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



//void
//qt_server_wnd::timeout(QPrivateSignal)
//{
//    //qDebug(u8"on timeout");
//
//    QList<::Ice::AsyncResultPtr> xTempList;
//    QMapIterator<::Ice::AsyncResultPtr, std::function<bool(const ::Ice::AsyncResultPtr&)>> itmap(m_setAsyncResult);
//    while (itmap.hasNext())
//    {
//        auto xPair = itmap.next();
//        ::Ice::AsyncResultPtr xKey = xPair.key();
//        std::function<bool(const ::Ice::AsyncResultPtr&)> xValue = xPair.value();
//        if (xKey->isCompleted())
//        {
//            xTempList.push_back(xKey);
//            IceProxy::MsNet::ILogin& xTemp = *(g_ice_server_app.m_LoginPrx.m_Prx.get());
//            if (xValue(xKey))
//            {
//                qDebug(u8"成功");
//            }
//            else
//            {
//                qDebug(u8"失败");
//            }
//            qDebug(u8"Completed");
//        }
//    }
//
//    QListIterator<::Ice::AsyncResultPtr> itlist(xTempList);
//    while (itlist.hasNext())
//    {
//        m_setAsyncResult.remove(itlist.next());
//    }
//}



void
qt_server_wnd::test0() {
    qDebug(u8"test0");
}



void
qt_server_wnd::test1() {
    qDebug(u8"test1");
    MsNet::Login xxParam;
    xxParam.account = "1";
    xxParam.password = "1";
    //g_ice_server_app.m_LoginPrx->c2sLogin(xxParam);

    //g_ice_server_app.m_LoginPrx->msc2sLogin(xxParam);

    g_ice_server_app.m_LoginPrx.msc2sRegister(xxParam);


    //ICE_CALL_0(g_ice_server_app.m_LoginPrx, c2sLogin, xxParam);
    //qDebug(u8"我来了");
    //END_ICE_CALL;


    //MsNet::Login ret;
    //ICE_CALL_1(g_ice_server_app.m_LoginPrx, c2sRegister, xxParam, ret);
    //qDebug(u8"我来了");
    //END_ICE_CALL;


    //DEF_ICE_CALL(g_ice_server_app.m_LoginPrx->begin_c2sRegister(xxParam));
    //EXE_ICE_CALL(g_ice_server_app.m_LoginPrx->end_c2sRegister(aa, xAsynResult));
    //qDebug(u8"我来了");
    //END_ICE_CALL(aa);

    //DEF_ICE_CALL(g_ice_server_app.m_LoginPrx->begin_c2sRegister(xxParam))

    //    qDebug(u8"我来了");
    //END_ICE_CALL;

    //m_setAsyncResult.insert(g_ice_server_app.m_LoginPrx->begin_c2sLogin(xxParam),
    //    [&](const ::Ice::AsyncResultPtr& xAsynResult)
    //{
    //    return g_ice_server_app.m_LoginPrx->end_c2sLogin(xAsynResult);
    //});

    //while (!xRet->isCompleted())
    //{
    //    continue;
    //}
    //g_ice_server_app.m_LoginPrx->end_c2sLogin(xRet);
}


void
qt_server_wnd::test2() {

    g_ice_server_app.m_LoginPrx.begin();
    //g_ice_server_app.m_LoginPrx = NEW MsNetLogin(0);
    g_ice_server_app.m_LoginPrx.m_Prx
        = MsNet::ILoginPrx::checkedCast(g_ice_server_app.communicator()->stringToProxy("PJ1:tcp -h 127.0.0.1 -p 10000"));

    //g_ice_server_app.m_LoginPrx2
    //    = MsNet::ILoginPrx::checkedCast(g_ice_server_app.communicator()->stringToProxy("PJ2:tcp -h 192.168.4.227 -p 10001"));

    qDebug(u8"test2");
}


void
qt_server_wnd::test3() {
    qDebug(u8"test3");

    std::string temp = u8"放大啊的说法是的地方";

    g_ice_server_app.m_LoginPrx.msc2sxqCall(u8"太一", [=](bool ice_ret, const std::string p1, const qint32 r1)
    {
        return true;
    });

    ICE_DIY_CALL1_RET0(g_ice_server_app.m_LoginPrx, p1r0, u8"p1")
    {
        return false;
    });

    ICE_DIY_CALL1_RET0(g_ice_server_app.m_LoginPrx, p1r0, u8"p1")
    {
        return true;
    });
    //g_ice_server_app.m_LoginPrx.msc2sxqCall(u8"太一", 
    //    [=](bool ice_ret, decltype(g_ice_server_app.m_LoginPrx)::c2sxqCallp1 p1, decltype(g_ice_server_app.m_LoginPrx)::c2sxqCallr1 r1)
    ICE_DIY_CALL1_RET1(g_ice_server_app.m_LoginPrx, c2sxqCall, u8"太一")
    {
        return true;
    });

    g_ice_server_app.m_LoginPrx.msc2sxqCall(u8"太一", [=](bool ice_ret, const std::string p1, const qint32 r1)
    {
        if (temp == u8"放大啊的说法是的地方")
        {
            qDebug(QString(u8"name:%1,age:%2").arg(p1.c_str()).arg(r1).toStdString().c_str());
            return true;
        }
        return false;
    });

    g_ice_server_app.m_LoginPrx.msc2sxqCall(u8"小琦");

    //g_ice_server_app.m_LoginPrx->msc2sxqCall(u8"小琦"){
    //    qDebug(QString(u8"name:%1,age:%2").arg(p1.c_str()).arg(r1).toStdString().c_str());
    //    return true;
    //}
}



void
qt_server_wnd::test4() {

    qDebug(u8"test4");
}



void
qt_server_wnd::test5() {

    qDebug(u8"test5");
}



bool
MsILogin::ice_default_cbc2sLogin(bool _ice_result,
    const ::MsNet::Login& p1,
    const qint32& r0) {

    g_ice_server_app.m_MainWnd->ui.testButton1->setText(QString(u8"%1").arg(r0));
    this->msc2sLogin(p1);
    qDebug(u8"dsjlkfjadslk;jf32u43823");
    return _ice_result;
}


bool
MsILogin::ice_default_cbc2sRegister(bool _ice_result,
    const MsNet::Login& p1,
    const qint32& r1,
    const MsNet::Login& r2) {

    return _ice_result;
}


bool
MsILogin::ice_default_cbc2sxqCall(bool _ice_result,
    const std::string& p1,
    const qint32& r1) {

    return _ice_result;
}

bool
MsILogin2::ice_default_cba2c2sRegister(bool _ice_result,
    const MsNet::Login& p1,
    const qint32& r0,
    const MsNet::Login& r1) {

    g_ice_server_app.m_MainWnd->ui.testButton2->setText(QString(u8"%1").arg(r0));
    this->msa2c2sRegister(p1);
    qDebug(u8"dsjlkfjadslk;jf32u43823");
    return _ice_result;
}



bool
MsIScene::ice_default_cba2c2sxqCall(bool _ice_result,
    const std::string& p1,
    const qint32& r1) {

    qDebug(QString(u8"name:%1,age:%2").arg(p1.c_str()).arg(r1).toStdString().c_str());
    return true;
}
