#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_pj_client.h"
#include "ui_pj_login.h"
#include "pj_loader.h"
#include "pj_wasani.h"

class pj_view;
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
    pj_view* m_view;
};
extern ice_client_app g_ice_client_app;


//class pj_scene;
class pj_main_wnd : public QWidget
{
public:

    pj_main_wnd()
    {
        int w = 1024;
        int h = 768;
        QDesktopWidget* desktop = QApplication::desktop();

        this->setMinimumSize(400, 300);
        this->setMaximumSize(desktop->width(), desktop->height());
        this->setGeometry((desktop->width() - w) / 2, (desktop->height() - h) / 2, w, h);
    }

    void update()
    {
        QWidget::update();
    }

};



class qt_login_wnd;
class pj_scene;
class pj_view : public QGraphicsView
{
public:
    pj_view(pj_scene* scene);

    void update();

    //void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE
    //{
    //    QPainter qPainter(this);
    //    qPainter.setPen(QColor(255, 0, 0));
    //    qPainter.drawText(QPoint(100, 100), "123");
    //}

    QTime time;
    int m_tempFPS = 0;
    int m_FPS = 0;
    pj_scene* m_scene;

    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE
    {
        return;
    }

    qt_login_wnd* m_login = nullptr;
};

class pj_image : public QGraphicsItem
{
public:

    pj_image()
    {
        quint32 file_key = 0;
        if (!pj_GetResManager().pjLoadFile(R"(A:\git\pj\res\gires3.wdf)", file_key))
        {
            return;
        }

        quint64 tempKey = (((quint64)file_key) << 32) + 2904516639;
        QVector<hotImage> imageVector;
        XYUnit* xyUnit = nullptr;
        if (!pj_GetResManager().pjGetWasTextures(tempKey, xyUnit))
        {
            return;
        }

        if (imageVector.size() > 0)
        {
            m_QImage = imageVector[0].qImage.get();
            QPainter xQPainter(m_QImage);
            xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"了屁嗝");
            //QPalette palette;
            //palette.setBrush(QPalette::ColorRole::Background, QBrush(*xImage));
            //this->setAutoFillBackground(true);
            //this->setPalette(palette);

            //if (this->auto_back_size())
            //{
            //    this->setFixedSize(xImage->size());
            //    this->setMinimumSize(xImage->size());
            //    this->setMaximumSize(xImage->size());
            //}
        }

        //((DOUBLE)rand());
        qsrand(QTime::currentTime().msec() + QTime::currentTime().second() * 1000);
        auto x = (qint64)qrand()*(qint64)qrand()*(qint64)qrand() % 4000;
        auto y = (qint64)qrand()*(qint64)qrand()*(qint64)qrand() % 2000;
        this->setPos(x, y);
        //if (x > 500000 || y > 500000)
        //{
        //    qDebug(QString("%1,%2").arg(x).arg(y).toStdString().c_str());
        //}
    }

    virtual QRectF boundingRect() const
    {
        return { 0,0,640,480 };
    }

    QImage* m_QImage = nullptr;
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = Q_NULLPTR)
    {
        if (m_QImage)
        {
            //painter->drawImage(100 + qrand() % 100, 100 + qrand() % 20, *m_QImage);
            painter->drawImage(100, 100, *m_QImage);
        }
    }
};


class pj_scene : public QGraphicsScene
{

public:
    QGraphicsTextItem * m_QGraphicsTextItem;
    //QGraphicsItem * m_QGraphicsTextItem;
};


// 登录界面
class qt_login_wnd : public pj_groupbox
{
    Q_OBJECT

public:
    qt_login_wnd(ice_client_app* app, QWidget *parent = Q_NULLPTR);
    qt_login_wnd(ice_client_app* app, QWidget *parent,  bool);

public:
    void go_start();
    void finished();

    bool isDrag = false;
    QPoint m_position;
    QVector<pj_wasani*> aniVector;
    ice_client_app* m_app;

    //void paintEvent(QPaintEvent *e) Q_DECL_OVERRIDE
    //{
    //    if (isDrag)
    //    {
    //        return;
    //    }
    //    else
    //    {
    //        return pj_groupbox::paintEvent(e);
    //    }
    //}

    //void mousePressEvent(QMouseEvent *e)
    //{
    //    if (e->button() == Qt::LeftButton)
    //    {
    //        isDrag = true;
    //        m_position = e->globalPos() - this->pos();

    //        //QListIterator<QWidget*> _it(this->findChildren<QWidget*>());
    //        //while (_it.hasNext())
    //        //{
    //        //    _it.next()->hide();
    //        //}
    //        //this->setEnabled(false);
    //        //e->accept();
    //    }
    //}

    //void mouseMoveEvent(QMouseEvent *e)
    //{
    //    if (isDrag && (e->buttons() && Qt::LeftButton))
    //    {
    //        //if (qrand() % 2 == 0)
    //        {
    //            auto x = e->globalPos() - m_position;
    //            move(e->globalPos() - m_position);
    //            //setGeometry(QRect(x.x(), x.y(), 640, 480));
    //            //e->accept();
    //        }
    //    }
    //}

    //void mouseReleaseEvent(QMouseEvent *)
    //{
    //    isDrag = false;
    //    this->update();
    //    //QListIterator<QWidget*> _it(this->findChildren<QWidget*>());
    //    //while (_it.hasNext())
    //    //{
    //    //    _it.next()->show();
    //    //}
    //    //this->setEnabled(true);
    //}

public:
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

