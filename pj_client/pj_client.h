#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_pj_client.h"
#include "ui_pj_login.h"
#include "pj_loader.h"
#include "pj_wasani.h"
#include "pj_map.h"

class pj_main_wnd : public QWidget
{
public:

    pj_main_wnd()
    {
        int w = 1024;
        int h = 768;
        const QRect&& masterScreen1 = QApplication::desktop()->screenGeometry(0);
        const QRect&& masterScreen2 = QApplication::desktop()->screenGeometry(1);
        this->setMinimumSize(640, 480);
        this->setMaximumSize(masterScreen2.width(), masterScreen2.height());
        QPoint x((masterScreen2.width() - w) / 2, (masterScreen2.height() - h) / 2);
        this->setGeometry(x.x(), x.y(), w, h);
    }

    void update()
    {
        QWidget::update();
    }

};

class pj_main_view : public QGraphicsView
{
public:
    pj_main_view(pj_map* map);

    void update();

    QTime qTimeFPS;
    qint32 tempFPS = 0;
    qint32 FPS = 0;

    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE
    {
        return;
    }

    QTimer* qTimerRender;
    QGraphicsTextItem* m_QGraphicsTextItem;
};

// 登录界面
class qt_login_wnd : public pj_groupbox
{
    Q_OBJECT

public:
    qt_login_wnd(QWidget *parent = Q_NULLPTR);

public:
    void go_start();
    void finished();

    bool isDrag = false;
    QPoint m_position;
    //ice_client_app* m_app;

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
    pj_main_wnd*    mainWnd;
    pj_main_view*   mainView;
    pj_map*         currentScene;
    qt_login_wnd*   loginWnd;
    qt_scene_wnd*   sceneWnd;
    QLabel*         leftTopTextInfo;
};
extern ice_client_app g_ice_client_app;
