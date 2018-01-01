#include "Precompiled.h"
#include "pj_loader.h"
#include "pj_client.h"
#include "pj_wasani.h"

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

    pj_main_wnd* w_main = NEW pj_main_wnd();
    //w_main->setGeometry(QRect(0, 0, 1024, 768));

    //return a.exec();

    pj_scene* scene = NEW pj_scene();
    scene->setSceneRect(0, 0, 4000, 2000);

    for (qint32 i = 0; i < 20; i++)
    {
        //if (i % 10000 == 0)
        //{
        //    qDebug(QString("%1").arg(i).toStdString().c_str());
        //}
        scene->addItem(NEW pj_image());
    }

    scene->m_QGraphicsTextItem = NEW QGraphicsTextItem();
    scene->addItem(scene->m_QGraphicsTextItem);
    //////scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    //w_login->setGeometry(0, 0, 300, 400);
    //scene->addWidget(w_login);

    //w_main.update();
    m_view = NEW pj_view(scene);

    m_view->centerOn(0, 0);
    QTimer* timer = NEW QTimer(m_view);
    QObject::connect(timer, &QTimer::timeout, m_view, &pj_view::update);
    //QObject::connect(timer, &QTimer::timeout, view, &pj_view::update);
    timer->start(1); // 2秒单触发定时器

    //view.setCacheMode(QGraphicsView::CacheBackground);

    ////view.setDragMode(QGraphicsView::NoDrag);
    ////view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);


    auto* opglwg = NEW QOpenGLWidget();
    //opglwg->setGeometry(QRect(0, 0, 4000, 2000));
    ////view->setRenderHint(QPainter::Antialiasing);
    m_view->setGeometry(QRect(0, 0, 1024, 768));
    m_view->setViewport(opglwg);
    m_view->setParent(w_main);
    //auto* opglwg2 = NEW QOpenGLWidget();
    //opglwg2->setAutoFillBackground(true);
    //opglwg2->setParent(opglwg);
    //opglwg2->move(100, 100);
    //w_login->setParent(opglwg);
    m_view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    //FORRANGE(10)
    {
        qt_login_wnd* w_login = NEW qt_login_wnd(this);
        w_login->setParent(w_main);
        w_login->move(100, 100);
    }
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

    w_main->show();
    //w_login->show();

    return a.exec();
}

pj_view::pj_view(pj_scene* scene)
    :QGraphicsView(scene)
    , m_scene(scene)
{
    time.start();

    //m_scene->m_QGraphicsTextItem->setFont(QFont("楷体", ))
    m_scene->m_QGraphicsTextItem->setDefaultTextColor(QColor(255, 0, 0));
    //qDebug(QString("%1").arg(m_FPS).toStdString().c_str());
    m_scene->m_QGraphicsTextItem->setPos(0, 0);
    m_scene->m_QGraphicsTextItem->show();
}


void pj_view::update()
{
    //QRect x(0, 0, this->parentWidget()->frameSize().width(), this->parentWidget()->frameSize().height());
    //m_scene->setSceneRect(x);
    //this->setGeometry(x);
    //this->centerOn(0, 0);
    //this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //this->resize(this->parentWidget()->frameSize().width(), this->parentWidget()->frameSize().height());
    //this->geometry(x);

    if (time.elapsed() > 1000)
    {
        time.restart();
        m_FPS = m_tempFPS;
        m_tempFPS = 0;
    }
    m_tempFPS++;
    //auto x = QGraphicsView::mapToScene(0, 0);
    //m_scene->m_QGraphicsTextItem->setPos(x);
    m_scene->m_QGraphicsTextItem->setPlainText(QString("%1").arg(m_FPS));

    //m_login->paintEvent(nullptr);
    //this->findChildren<qt_login_wnd>()[0].paintEvent(nullptr);

    //m_scene->items()[1]->setPos(qrand() % 1000, qrand() % 1000);
    //QGraphicsView::update();
}

void qt_login_wnd::finished()
{
    QPropertyAnimation* animation = NEW QPropertyAnimation(&m_ani->_wasaniAssist, "indexAni");
    QObject::connect(animation, &QPropertyAnimation::finished, this, &qt_login_wnd::finished);

    animation->setDuration(50000);
    animation->setStartValue(0);
    //animation->setKeyValueAt(0.1, QRect(0, 0, 50, 100));
    //animation->setKeyValueAt(0.2, QRect(600, 0, 100, 70));
    //animation->setKeyValueAt(0.3, QRect(500, 0, 80, 100));
    //animation->setKeyValueAt(0.4, QRect(500, 400, 90, 100));
    //animation->setKeyValueAt(0.5, QRect(600, 450, 100, 100));
    //animation->setKeyValueAt(0.6, QRect(0, 450, 100, 90));
    //animation->setKeyValueAt(0.7, QRect(0, 400, 50, 40));
    //animation->setKeyValueAt(0.8, QRect(0, 0, 30, 100));
    //animation->setKeyValueAt(0.9, QRect(0, 0, 100, 60));
    animation->setEndValue(10);
    animation->start();
}

void qt_login_wnd::go_start()
{
    m_ani = NEW pj_wasani();
    m_ani->setPos(0, 0);

    QPropertyAnimation* animation = NEW QPropertyAnimation(&m_ani->_wasaniAssist, "indexAni");
    QObject::connect(animation, &QPropertyAnimation::finished, this, &qt_login_wnd::finished);

    animation->setDuration(50000);
    animation->setStartValue(0);
    //animation->setKeyValueAt(0.1, QRect(0, 0, 50, 100));
    //animation->setKeyValueAt(0.2, QRect(600, 0, 100, 70));
    //animation->setKeyValueAt(0.3, QRect(500, 0, 80, 100));
    //animation->setKeyValueAt(0.4, QRect(500, 400, 90, 100));
    //animation->setKeyValueAt(0.5, QRect(600, 450, 100, 100));
    //animation->setKeyValueAt(0.6, QRect(0, 450, 100, 90));
    //animation->setKeyValueAt(0.7, QRect(0, 400, 50, 40));
    //animation->setKeyValueAt(0.8, QRect(0, 0, 30, 100));
    //animation->setKeyValueAt(0.9, QRect(0, 0, 100, 60));
    animation->setEndValue(10);
    animation->start();

    this->m_app->m_view->scene()->addItem(m_ani);
}

qt_login_wnd::qt_login_wnd(ice_client_app* app, QWidget *parent, bool)
    : pj_groupbox(parent)
    , m_app(app)
{
    uiLogin.setupUi(this);
    //this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //uiLogin.pj_listview_.;

    QObject::connect(uiLogin.pushButton_3, &QPushButton::clicked, this, &qt_login_wnd::go_start);
    //auto x = uiLogin.pj_label_->font();

    //go_start();
    //auto xx = x.family();
    //QPropertyAnimation* animation = NEW QPropertyAnimation(uiLogin.pushButton_3, "geometry");

    ////QFont xFont = uiLogin.pj_label_->font();
    //animation->setDuration(5000);
    //animation->setStartValue(QRect(320, 240, 50, 50));
    //animation->setKeyValueAt(0.1, QRect(0, 0, 50, 100));
    //animation->setKeyValueAt(0.2, QRect(600, 0, 100, 70));
    //animation->setKeyValueAt(0.3, QRect(500, 0, 80, 100));
    //animation->setKeyValueAt(0.4, QRect(500, 400, 90, 100));
    //animation->setKeyValueAt(0.5, QRect(600, 450, 100, 100));
    //animation->setKeyValueAt(0.6, QRect(0, 450, 100, 90));
    //animation->setKeyValueAt(0.7, QRect(0, 400, 50, 40));
    //animation->setKeyValueAt(0.8, QRect(0, 0, 30, 100));
    //animation->setKeyValueAt(0.9, QRect(0, 0, 100, 60));
    ////animation->setKeyValueAt(0.9, QRect(0, 0, 10, 10));
    ////xFont.setPointSize(99);
    //animation->setEndValue(QRect(320, 240, 50, 50));
    //animation->start();

    //QSize x;
    //x.setWidth;
    //QGraphicsItem;
    //QGraphicsPixmapItem;
    //QFont()
    //QVariant v = QRect(640, 480, 200, 150);
    //QVariant v1 = x;
    //QFont aa;
    //aa.fromString(v1.toString());

    //uiLogin.pj_label_->setFont(aa);


    ////connect(animation, SIGNAL(finished()), ani, SLOT(deleteLater()));
    //animation->setStartValue(x);
    //x.setWeight(99); animation->setEndValue(x);
    //QVariant v2 = x;

    //x.setWeight(10);    animation->setKeyValueAt(0.1, x);
    //x.setWeight(20);    animation->setKeyValueAt(0.2, x);
    //x.setWeight(30);    animation->setKeyValueAt(0.3, x);
    //x.setWeight(40);    animation->setKeyValueAt(0.4, x);
    //x.setWeight(50);    animation->setKeyValueAt(0.5, x);
    //x.setWeight(60);    animation->setKeyValueAt(0.6, x);
    //x.setWeight(70);    animation->setKeyValueAt(0.7, x);
    //x.setWeight(80);    animation->setKeyValueAt(0.8, x);
    //x.setWeight(90);    animation->setKeyValueAt(0.9, x);
    //x.setWeight(99); animation->setEndValue(x);
    //animation->setDuration(1000);
    ////animation->setEasingCurve(QEasingCurve::Linear);
    //animation->start();


    //QPropertyAnimation *animation2 = NEW QPropertyAnimation(uiLogin.pjb_register_2, "geometry");
    //animation2->setDuration(10000);
    //animation2->setStartValue(QRect(640, 480, 200, 150));
    //animation2->setEndValue(QRect(0, 0, 10, 10));
    //animation2->start();

    //this->palette().
    int w = this->width();
    int h = this->height();
    QDesktopWidget* desktop = QApplication::desktop();
    this->setGeometry((desktop->width() - w) / 2, (desktop->height() - h) / 2, w, h);
    this->setMinimumSize(this->size());
    this->setMaximumSize(this->size());


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

    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00, 0x00, 0x00, 0x00));

    //QGraphicsEffect* x = uiLogin.textEdit->graphicsEffect();
    //x->Opacity();
    //uiLogin.textEdit->setGraphicsEffect();

    //uiLogin.textEdit->setWindowOpacity(0);
    //uiLogin.pjtb_account->setStyleSheet("background-color:transparent;");
    //uiLogin.pjtb_password->setStyleSheet("background-color:transparent;");

    //QFile xFile("A:\\1.mp3");
    //if (!xFile.open(QIODevice::ReadOnly))
    //{
    //    return;
    //}
    //QByteArray xData = xFile.readAll();
    //xFile.close();
    //m_QMediaPlayer.setMedia(QUrl::fromEncoded(xData)) 
    ////m_QMediaPlayer.setMedia(QUrl::fromLocalFile("A:\\1.mp3"));
    //m_QMediaPlayer.setVolume(100);  
    //m_QMediaPlayer.data (100);
    //m_QMediaPlayer.play();

    //QFile file("A:\\1.mp3");
    //file.open(QIODevice::ReadOnly);
    //QByteArray* arr = new QByteArray(file.readAll());
    //file.close();
    //QBuffer* buffer = new QBuffer(arr);
    mp3Buffer->open(QIODevice::ReadOnly);
    mp3Buffer->seek(0);
    m_QMediaPlayer.setMedia(QMediaContent(), mp3Buffer);
    m_QMediaPlayer.play();


    //QAudioOutput *audio = new QAudioOutput(QAudioDeviceInfo::defaultOutputDevice(), audioFormat);

    //uiLogin.pjtb_password->setStyleSheet("background-color:rgb(102,102,102);border:1px solid #e1e0e0;");
    //uiLogin.pjtb_password->setStyleSheet("background-color:transparent;");

    //auto* standardItemModel = NEW QStandardItemModel(this);
    //QStringList strList;
    //strList.append("string1");
    //strList.append("string2");
    //strList.append("string3");
    //strList.append("string4");
    //strList.append("string5");
    //strList.append("string6");
    //strList.append("string7");
    //strList << "string8";
    //strList += "string9";
    //int nCount = strList.size();
    //for (int i = 0; i < nCount; i++)
    //{
    //    QString string = static_cast<QString>(strList.at(i));
    //    QStandardItem *item = new QStandardItem(string);
    //    if (i % 2 == 1)
    //    {
    //        QLinearGradient linearGrad(QPointF(0, 0), QPointF(200, 200));
    //        linearGrad.setColorAt(0, Qt::darkGreen);
    //        linearGrad.setColorAt(1, Qt::yellow);
    //        QBrush brush(linearGrad);
    //        item->setBackground(brush);
    //    }
    //    standardItemModel->appendRow(item);
    //}
    //uiLogin.pj_listview_->setModel(standardItemModel);

    //uiLogin.textEdit->setAutoFillBackground(true);
    //uiLogin.textEdit->setPalette(pal);
    //uiLogin.textEdit->setAttribute(Qt::WA_TranslucentBackground, true);

    g_ice_client_app.init_client();

}


qt_login_wnd::qt_login_wnd(ice_client_app* app, QWidget *parent)
    : pj_groupbox(parent)
    , m_app(app)
{
    uiLogin.setupUi(this);
    //this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //uiLogin.pj_listview_.;

    QObject::connect(uiLogin.pushButton_3, &QPushButton::clicked, this, &qt_login_wnd::go_start);
    //auto x = uiLogin.pj_label_->font();

    //go_start();
    //auto xx = x.family();
    //QPropertyAnimation* animation = NEW QPropertyAnimation(uiLogin.pushButton_3, "geometry");

    ////QFont xFont = uiLogin.pj_label_->font();
    //animation->setDuration(5000);
    //animation->setStartValue(QRect(320, 240, 50, 50));
    //animation->setKeyValueAt(0.1, QRect(0, 0, 50, 100));
    //animation->setKeyValueAt(0.2, QRect(600, 0, 100, 70));
    //animation->setKeyValueAt(0.3, QRect(500, 0, 80, 100));
    //animation->setKeyValueAt(0.4, QRect(500, 400, 90, 100));
    //animation->setKeyValueAt(0.5, QRect(600, 450, 100, 100));
    //animation->setKeyValueAt(0.6, QRect(0, 450, 100, 90));
    //animation->setKeyValueAt(0.7, QRect(0, 400, 50, 40));
    //animation->setKeyValueAt(0.8, QRect(0, 0, 30, 100));
    //animation->setKeyValueAt(0.9, QRect(0, 0, 100, 60));
    ////animation->setKeyValueAt(0.9, QRect(0, 0, 10, 10));
    ////xFont.setPointSize(99);
    //animation->setEndValue(QRect(320, 240, 50, 50));
    //animation->start();

    //QSize x;
    //x.setWidth;
    //QGraphicsItem;
    //QGraphicsPixmapItem;
    //QFont()
    //QVariant v = QRect(640, 480, 200, 150);
    //QVariant v1 = x;
    //QFont aa;
    //aa.fromString(v1.toString());

    //uiLogin.pj_label_->setFont(aa);


    ////connect(animation, SIGNAL(finished()), ani, SLOT(deleteLater()));
    //animation->setStartValue(x);
    //x.setWeight(99); animation->setEndValue(x);
    //QVariant v2 = x;

    //x.setWeight(10);    animation->setKeyValueAt(0.1, x);
    //x.setWeight(20);    animation->setKeyValueAt(0.2, x);
    //x.setWeight(30);    animation->setKeyValueAt(0.3, x);
    //x.setWeight(40);    animation->setKeyValueAt(0.4, x);
    //x.setWeight(50);    animation->setKeyValueAt(0.5, x);
    //x.setWeight(60);    animation->setKeyValueAt(0.6, x);
    //x.setWeight(70);    animation->setKeyValueAt(0.7, x);
    //x.setWeight(80);    animation->setKeyValueAt(0.8, x);
    //x.setWeight(90);    animation->setKeyValueAt(0.9, x);
    //x.setWeight(99); animation->setEndValue(x);
    //animation->setDuration(1000);
    ////animation->setEasingCurve(QEasingCurve::Linear);
    //animation->start();


    //QPropertyAnimation *animation2 = NEW QPropertyAnimation(uiLogin.pjb_register_2, "geometry");
    //animation2->setDuration(10000);
    //animation2->setStartValue(QRect(640, 480, 200, 150));
    //animation2->setEndValue(QRect(0, 0, 10, 10));
    //animation2->start();

    //this->palette().
    int w = this->width();
    int h = this->height();
    this->setMinimumSize(0, 0);
    this->setMaximumSize(60000, 60000);
    QDesktopWidget* desktop = QApplication::desktop();
    this->setGeometry((desktop->width() - w) / 2, (desktop->height() - h) / 2, w, h);
    //this->setMinimumSize(this->size());
    //this->setMaximumSize(this->size());


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

    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00, 0x00, 0x00, 0x00));

    //QGraphicsEffect* x = uiLogin.textEdit->graphicsEffect();
    //x->Opacity();
    //uiLogin.textEdit->setGraphicsEffect();

    //uiLogin.textEdit->setWindowOpacity(0);
    //uiLogin.pjtb_account->setStyleSheet("background-color:transparent;");
    //uiLogin.pjtb_password->setStyleSheet("background-color:transparent;");

    //QFile xFile("A:\\1.mp3");
    //if (!xFile.open(QIODevice::ReadOnly))
    //{
    //    return;
    //}
    //QByteArray xData = xFile.readAll();
    //xFile.close();
    //m_QMediaPlayer.setMedia(QUrl::fromEncoded(xData)) 
    ////m_QMediaPlayer.setMedia(QUrl::fromLocalFile("A:\\1.mp3"));
    //m_QMediaPlayer.setVolume(100);  
    //m_QMediaPlayer.data (100);
    //m_QMediaPlayer.play();

    //QFile file("A:\\1.mp3");
    //file.open(QIODevice::ReadOnly);
    //QByteArray* arr = new QByteArray(file.readAll());
    //file.close();
    //QBuffer* buffer = new QBuffer(arr);
    mp3Buffer->open(QIODevice::ReadOnly);
    mp3Buffer->seek(0);
    m_QMediaPlayer.setMedia(QMediaContent(), mp3Buffer);
    m_QMediaPlayer.play();


    //QAudioOutput *audio = new QAudioOutput(QAudioDeviceInfo::defaultOutputDevice(), audioFormat);

    //uiLogin.pjtb_password->setStyleSheet("background-color:rgb(102,102,102);border:1px solid #e1e0e0;");
    //uiLogin.pjtb_password->setStyleSheet("background-color:transparent;");

    //auto* standardItemModel = NEW QStandardItemModel(this);
    //QStringList strList;
    //strList.append("string1");
    //strList.append("string2");
    //strList.append("string3");
    //strList.append("string4");
    //strList.append("string5");
    //strList.append("string6");
    //strList.append("string7");
    //strList << "string8";
    //strList += "string9";
    //int nCount = strList.size();
    //for (int i = 0; i < nCount; i++)
    //{
    //    QString string = static_cast<QString>(strList.at(i));
    //    QStandardItem *item = new QStandardItem(string);
    //    if (i % 2 == 1)
    //    {
    //        QLinearGradient linearGrad(QPointF(0, 0), QPointF(200, 200));
    //        linearGrad.setColorAt(0, Qt::darkGreen);
    //        linearGrad.setColorAt(1, Qt::yellow);
    //        QBrush brush(linearGrad);
    //        item->setBackground(brush);
    //    }
    //    standardItemModel->appendRow(item);
    //}
    //uiLogin.pj_listview_->setModel(standardItemModel);

    //uiLogin.textEdit->setAutoFillBackground(true);
    //uiLogin.textEdit->setPalette(pal);
    //uiLogin.textEdit->setAttribute(Qt::WA_TranslucentBackground, true);


    //this->resize(100, 100);
    g_ice_client_app.init_client();
}


qt_scene_wnd::qt_scene_wnd(QWidget *parent)
    : QMainWindow(parent)
{
    uiScene.setupUi(this);

    //g_ice_client_app.init_client();
}

