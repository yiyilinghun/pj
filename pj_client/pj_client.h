#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_pj_client.h"
#include "ui_pj_login.h"
#include "pj_loader.h"

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
};
extern ice_client_app g_ice_client_app;


//class pj_scene;
class pj_main_wnd : public QWidget
{
public:

};



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
};

class pj_image : public QGraphicsItem
{
public:

    pj_image()
    {
        xyTextureInfo m_backTextureInfo;
        quint32 file_key = 0;
        if (!pj_GetResManager().pjLoadFile(R"(A:\git\pj\res\gires3.wdf)", file_key))
        {
            return;
        }

        quint64 tempKey = (((quint64)file_key) << 32) + 2904516639;
        QVector<QImage*> imageVector;
        if (!pj_GetResManager().pjGetWasTextures(tempKey, m_backTextureInfo, imageVector))
        {
            return;
        }

        if (imageVector.size() > 0)
        {
            m_QImage = imageVector[0];
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
    }

    virtual QRectF boundingRect() const
    {
        return { 0,0,0,0 };
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
    qt_login_wnd(QWidget *parent = Q_NULLPTR);
    qt_login_wnd(QWidget *parent, bool);

public:
    void go_start();
    void finished();

    bool isDrag = false;
    QPoint m_position;

    void mousePressEvent(QMouseEvent *e)
    {
        if (e->button() == Qt::LeftButton)
        {
            isDrag = true;
            m_position = e->globalPos() - this->pos();
            e->accept();
        }
    }

    void mouseMoveEvent(QMouseEvent *e)
    {
        if (isDrag && (e->buttons() && Qt::LeftButton))
        {
            move(e->globalPos() - m_position);
            e->accept();
        }
    }

    void mouseReleaseEvent(QMouseEvent *)
    {
        isDrag = false;
    }

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

