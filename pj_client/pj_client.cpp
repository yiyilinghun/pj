#include "Precompiled.h"
#include "pj_loader.h"
#include "pj_client.h"
#include "pj_wasani.h"
#include "pj_map.h"

ice_client_app g_ice_client_app;

ice_client_app::ice_client_app()
//: m_LoginManager(nullptr)
{
    ;
}

Ice::CommunicatorPtr g_CommunicatorPtr;
Ice::ObjectPrx g_ObjectPrx;
MsNet::ILoginPrx g_LoginPrx;

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
        //        qDebug(u8"ok");
        //    }
        //    else
        //    {
        //        qDebug(u8"no");
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
        //            ThreadTest* xThread = NEW ThreadTest(m_LoginManager, 0);
        //            xThread->start(QThread::HighestPriority);
        //
        //            for (int32_t i = 1; i < 7; i++)
        //            {
        //                ThreadTest* xThread = NEW ThreadTest(m_LoginManager, i);
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
ice_client_app::run(int argc, char* argv[])
{
    setHighDpiEnvironmentVariable();
    QApplication a(argc, argv);

    mainWnd = NEW pj_main_wnd();

    currentScene = NEW pj_map(R"(A:\git\pj\res\scene\1201.map)");
    currentScene->load();

    //for (qint32 i = 0; i < 20; i++)
    //{
    //    //if (i % 10000 == 0)
    //    //{
    //    //    qDebug(QString("%1").arg(i).toStdString().c_str());
    //    //}
    //    currentScene->addItem(NEW pj_image());
    //}

    //currentScene->m_QGraphicsTextItem = NEW QGraphicsTextItem();
    //currentScene->addItem(currentScene->m_QGraphicsTextItem);
    //////scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    //w_login->setGeometry(0, 0, 300, 400);
    //scene->addWidget(w_login);

    //w_main.update();
    mainView = NEW pj_view(currentScene);
    mainView->setParent(mainWnd);


    loginWnd = NEW qt_login_wnd(mainWnd);


    //leftTopTextInfo = NEW QLabel(mainWnd);
    //leftTopTextInfo->show();
    //leftTopTextInfo->move(0, 0);
    //leftTopTextInfo->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    //leftTopTextInfo->setAlignment(Qt::AlignmentFlag::AlignLeft | Qt::AlignmentFlag::AlignTop);
    //leftTopTextInfo->setGeometry(QRect(0, 0, 100, 100));

    //view.setCacheMode(QGraphicsView::CacheBackground);
    ////view.setDragMode(QGraphicsView::NoDrag);
    ////view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);




    //auto* opglwg2 = NEW QOpenGLWidget();
    //opglwg2->setAutoFillBackground(true);
    //opglwg2->setParent(opglwg);
    //opglwg2->move(100, 100);
    //w_login->setParent(opglwg);

    //FORRANGE(10)
    //{
    //    qt_login_wnd* w_login = NEW qt_login_wnd(this);
    //    w_login->setParent(w_main);
    //    w_login->move(100, 100);
    //}
    //view->m_login->setAutoFillBackground(true);
    //view->m_login->setParent(view);
    //view->m_login->move(0, 0);
    //view->m_login->show();

    //view->setParent(w_login);
    //w_login2->setParent(w_main);
    //w_login2->show();


    //for (qint32 i = 0; i < 10; i++)
    //{
    //    qt_login_wnd* w_login2 = NEW qt_login_wnd();
    //    w_login2->setParent(w_main);
    //    //scene->addWidget(w_login2);
    //    w_login2->setGeometry(qrand() % 100, qrand() % 100, 640, 480);
    //    w_login2->show();
    //}

    //for (qint32 i = 0; i < 10; i++)
    //{
    //    auto* x = NEW qt_login_wnd(nullptr);
    //    x->setGeometry(qrand() % 1000, qrand() % 800, 640, 480);
    //    x->setParent(w_main);
    //}

    //w_main.addSubWindow(w_login2);
    //w_main.addSubWindow(view);

    //w_login2->setWindowFlags(Qt::FramelessWindowHint | w_login2->windowFlags());

    //view.setWindowFlags(Qt::FramelessWindowHint | view.windowFlags());
    //view->resize(640, 480);
    //view->show();

    mainWnd->show();
    return a.exec();
}

pj_view::pj_view(pj_map* map)
    : QGraphicsView(map)
{
    this->centerOn(0, 0);
    this->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    this->setGeometry(QRect(0, 0, 1024, 768));
    this->setViewport(NEW QOpenGLWidget());

    qTimerRender = NEW QTimer(this);
    QObject::connect(qTimerRender, &QTimer::timeout, this, &pj_view::update);

    // 渲染定时器,间接控制帧数
    qTimerRender->start(10);
    qTimeFPS.start();

    m_QGraphicsTextItem = NEW QGraphicsTextItem();
    map->addItem(m_QGraphicsTextItem);

    ////m_scene->m_QGraphicsTextItem->setFont(QFont("楷体", ))
    //m_map->m_QGraphicsTextItem->setDefaultTextColor(QColor(255, 0, 0));
    ////qDebug(QString("%1").arg(m_FPS).toStdString().c_str());
    //m_map->m_QGraphicsTextItem->show();
}


void pj_view::update()
{
    m_QGraphicsTextItem->setPos(QGraphicsView::mapToScene(0, 0));
    m_QGraphicsTextItem->update();
    m_QGraphicsTextItem->setPlainText(QString("%1,%2").arg(FPS).arg(g_ice_client_app.currentScene->aniVector.size()));
    //g_ice_client_app.leftTopTextInfo->setText(QString("%1,%2").arg(FPS).arg(g_ice_client_app.currentScene->aniVector.size()));

    //QRect x(0, 0, this->parentWidget()->frameSize().width(), this->parentWidget()->frameSize().height());
    //m_scene->setSceneRect(x);
    //this->setGeometry(x);
    //this->centerOn(0, 0);
    //this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //this->resize(this->parentWidget()->frameSize().width(), this->parentWidget()->frameSize().height());
    //this->geometry(x);

    if (qTimeFPS.elapsed() > 1000)
    {
        qTimeFPS.restart();
        FPS = tempFPS;
        tempFPS = 0;
    }
    else
    {
        tempFPS++;
    }

    //if (m_login)
    //{
    //    auto x = QGraphicsView::mapToScene(0, 0);
    //    m_map->m_QGraphicsTextItem->setPos(x);
    //    m_map->m_QGraphicsTextItem->setPlainText(QString("%1,%2").arg(m_FPS).arg(m_login->aniVector.size()));
    //    m_map->m_QGraphicsTextItem->setZValue(1000.0);
    //}

    //m_scene->m_QGraphicsTextItem->setPos()
    //m_login->paintEvent(nullptr);
    //this->findChildren<qt_login_wnd>()[0].paintEvent(nullptr);

    //m_scene->items()[1]->setPos(qrand() % 1000, qrand() % 1000);

    QGraphicsView::update();
}

void qt_login_wnd::finished()
{
    QVectorIterator<pj_wasani*> it(g_ice_client_app.currentScene->aniVector);
    while (it.hasNext())
    {
        pj_wasani* ani = it.next();

        QPropertyAnimation* animation = NEW QPropertyAnimation(&ani->_wasaniAssist, "indexAni");
        QObject::connect(animation, &QPropertyAnimation::finished, this, &qt_login_wnd::finished);

        animation->setDuration((ani->m_xyUnit->m_ProductImages.size() - 1) * 100);
        animation->setStartValue(0);
        animation->setEndValue(ani->m_xyUnit->m_ProductImages.size() - 1);
        animation->start();
    }
}

void qt_login_wnd::go_start()
{
    FORRANGE(1000)
    {
        pj_wasani* ani = NEW pj_wasani(R"(A:\git\pj\res\shape.wdf)", 0xb012d547);
        ani->setPos(100 + qrand() % 1000, 100 + qrand() % 1000);
        g_ice_client_app.currentScene->aniVector.append(ani);
    }

    QVectorIterator<pj_wasani*> it(g_ice_client_app.currentScene->aniVector);
    while (it.hasNext())
    {
        pj_wasani* ani = it.next();

        QPropertyAnimation* animation = NEW QPropertyAnimation(&(ani->_wasaniAssist), "indexAni");
        QObject::connect(animation, &QPropertyAnimation::finished, this, &qt_login_wnd::finished);

        animation->setDuration((ani->m_xyUnit->m_ProductImages.size() - 1) * 100);
        animation->setStartValue(0);
        animation->setEndValue(ani->m_xyUnit->m_ProductImages.size() - 1);
        animation->start();

        if (g_ice_client_app.currentScene)
        {
            g_ice_client_app.currentScene->addItem(ani);
        }
    }
    //this->m_app->m_view->m_login = this;

}

qt_login_wnd::qt_login_wnd(QWidget *parent)
    : pj_groupbox(parent)
{
    uiLogin.setupUi(this);

    QObject::connect(uiLogin.pushButton_3, &QPushButton::clicked, this, &qt_login_wnd::go_start);

    quint32 file_key = 0;
    if (!pj_GetResManager().pjLoadFile("A:/git/pj/bin/mh/music.wdf", file_key))
    {
        return;
    }
    quint64 tempKey = (((quint64)file_key) << 32) + 0x2142584c;

    QBuffer* mp3Buffer = NEW QBuffer();
    if (!pj_GetResManager().pjGetMp3(tempKey, mp3Buffer))
    {
        return;
    }

    mp3Buffer->open(QIODevice::ReadOnly);
    mp3Buffer->seek(0);
    m_QMediaPlayer.setMedia(QMediaContent(), mp3Buffer);
    m_QMediaPlayer.play();
}



qt_scene_wnd::qt_scene_wnd(QWidget *parent)
    : QMainWindow(parent)
{
    uiScene.setupUi(this);

    //g_ice_client_app.init_client();
}

