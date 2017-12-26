#include "Precompiled.h"
#include "pj_client.h"

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
    qt_login_wnd w;
    w.show();
    return a.exec();
}

qt_login_wnd::qt_login_wnd(QWidget *parent)
    : pj_widget(parent)
{
    uiLogin.setupUi(this);

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
    uiLogin.pjtb_account->setStyleSheet("background-color:transparent;");
    uiLogin.pjtb_password->setStyleSheet("background-color:transparent;");

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


qt_scene_wnd::qt_scene_wnd(QWidget *parent)
    : QMainWindow(parent)
{
    uiScene.setupUi(this);

    //g_ice_client_app.init_client();
}

