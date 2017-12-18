#include "Precompiled.h"
#include "pj_widget.h"
#include <QtGui/QPainter>
//#include <QtGui/QEnterEvent>
//#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>


//class pj_widgetPrivate : public QWidget::QWidgetPrivate
//{
//    Q_DECLARE_PUBLIC(QCheckBox)
//public:
//    //pj_widgetPrivate()
//    //    : QWidgetPrivate(), tristate(false), noChange(false),
//    //    hovering(true), publishedState(Qt::Unchecked) {}
//    //uint tristate : 1;
//    //uint noChange : 1;
//    //uint hovering : 1;
//    //uint publishedState : 2;
//    void init();
//};

void pj_widgetPrivate::init()
{
    Q_Q(pj_widget);

    //align = Qt::AlignLeft;
//#ifndef QT_NO_SHORTCUT
//    shortcutId = 0;
//#endif
    //flat = false;
    //checkable = false;
    //checked = true;
    //hover = false;
    //overCheckBox = false;
    //pressedControl = QStyle::SC_None;
    //calculateFrame();

    _needLoadRes = true;
    _resFileName = "";
    _resKey = 0;

    q->setSizePolicy(QSizePolicy(
        QSizePolicy::Preferred,
        QSizePolicy::Preferred,
        QSizePolicy::Frame)
    );
}

pj_widget::pj_widget(QWidget *parent)
    : QWidget(*(NEW pj_widgetPrivate), parent, Qt::WindowFlags::enum_type::Widget)
    //: QWidget(*NEW, nullptr, (Qt::WindowFlags)(Qt::WindowFlags::enum_type::SubWindow))
    //: QWidget(parent)
    //: pj_widget(*(NEW pj_widgetPrivate), parent)
{
    Q_D(pj_widget);
    d->init();

    //this->show();
    //if (!this->is_need_load_res()) { return; }

    //AutoLeaveRunThis{
    //    this->set_need_load_res(false);
    //});

    xyTextureInfo m_backTextureInfo;
    if (!pj_GetResManager().pjLoadFile(u8R"(A:\git\pj\res\gires3.wdf)", 100))
    {
        return;
    }

    quint64 tempKey = (((quint64)100) << 32) + 578293861;
    QVector<QImage*> imageVector;
    if (!pj_GetResManager().pjGetWasTextures(tempKey, m_backTextureInfo, imageVector))
    {
        return;
    }
    //this->move(QPoint(10, 10));
    //this->resize(QSize(100, 100));
    //this->setFixedWidth(100);
    //this->setFixedHeight(100);
    if (imageVector.size() == 1)
    {
        QImage* xImage = imageVector[0];
        //QWidget* xParent = this->parentWidget()->parentWidget();
        //if (xParent)
        {
            //this->setMinimumSize(QSize(m_backTextureInfo.width, m_backTextureInfo.height));
            //this->setMaximumSize(QSize(m_backTextureInfo.width, m_backTextureInfo.height));

            QPainter xQPainter(xImage);
            xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"嗝屁了");
            QPalette palette;
            palette.setBrush(QPalette::ColorRole::Background, QBrush(*xImage));
            this->setAutoFillBackground(true);
            this->setPalette(palette);
        }
    }
}

//pj_widget::pj_widget(pj_widgetPrivate& dd, QWidget *parent)
//    : QWidget(dd, nullptr, (Qt::WindowFlags)(Qt::WindowFlags::enum_type::SubWindow))
//{
//    //Q_D(pj_widget);
//    //d->init(nullptr, (Qt::WindowFlags)(Qt::WindowFlags::enum_type::SubWindow));
//
//    this->show();
//    //if (!this->is_need_load_res()) { return; }
//
//    //AutoLeaveRunThis{
//    //    this->set_need_load_res(false);
//    //});
//
//    xyTextureInfo m_backTextureInfo;
//    if (!pj_GetResManager().pjLoadFile(u8R"(A:\git\pj\res\gires3.wdf)", 100))
//    {
//        return;
//    }
//
//    quint64 tempKey = (((quint64)100) << 32) + 578293861;
//    QVector<QImage*> imageVector;
//    if (!pj_GetResManager().pjGetWasTextures(tempKey, m_backTextureInfo, imageVector))
//    {
//        return;
//    }
//    //this->move(QPoint(10, 10));
//    //this->resize(QSize(100, 100));
//    //this->setFixedWidth(100);
//    //this->setFixedHeight(100);
//    if (imageVector.size() == 1)
//    {
//        QImage* xImage = imageVector[0];
//        //QWidget* xParent = this->parentWidget()->parentWidget();
//        //if (xParent)
//        {
//            //this->setMinimumSize(QSize(m_backTextureInfo.width, m_backTextureInfo.height));
//            //this->setMaximumSize(QSize(m_backTextureInfo.width, m_backTextureInfo.height));
//
//            QPainter xQPainter(xImage);
//            xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"嗝屁了");
//            QPalette palette;
//            palette.setBrush(QPalette::ColorRole::Background, QBrush(*xImage));
//            this->setPalette(palette);
//            return;
//        }
//    }
//
//    //this->showEvent(nullptr);
//    //QObject::connect(this, SIGNAL(QWidget::showEvent), this, SLOT(pj_widget::showEvent));
//    //QObject::connect(this, &QWidget::create, this, &pj_widget::createEvent);
//}

//void pj_widget::createEvent(WId, bool initializeWindow, bool destroyOldWindow)
//{
//    qDebug(u8"pj_widget::createEvent");
//    if (!pj_GetResManager().pjLoadFile(u8R"(A:\git\pj\res\gires3.wdf)", 100))
//    {
//        return;
//    }
//
//    quint64 tempKey = (((quint64)100) << 32) + 578293861;
//    QVector<QImage*> imageVector;
//    if (!pj_GetResManager().pjGetWasTextures(tempKey, m_backTextureInfo, imageVector))
//    {
//        return;
//    }
//
//    if (imageVector.size() == 1)
//    {
//        QImage* xImage = imageVector[0];
//        QWidget* xParent = this->parentWidget()->parentWidget();
//        if (xParent)
//        {
//            xParent->setMinimumSize(QSize(m_backTextureInfo.width, m_backTextureInfo.height));
//            xParent->setMaximumSize(QSize(m_backTextureInfo.width, m_backTextureInfo.height));
//
//            QPainter xQPainter(xImage);
//            xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"嗝屁了");
//            QPalette palette;
//            palette.setBrush(QPalette::ColorRole::Background, QBrush(*xImage));
//            xParent->setPalette(palette);
//            return;
//        }
//    }
//}

//bool pj_widget::event(QEvent *event)
//{
//    return true;
//}

//
//void pj_widget::mouseMoveEvent(QMouseEvent *event)
//{
//    qDebug("pj_widget::wheelEventmouseMoveEvent");
//}


//void pj_widget::wheelEvent(QWheelEvent *event)
//{
//    QMessageBox::information(this, u8"提示", u8"pj_widget::wheelEvent?", u8"确定", u8"取消", 0, 1);
//    qDebug("pj_widget::wheelEvent");
//}

//
//void pj_widget::showEvent(QShowEvent *event)
//{
//    ////if (!this->is_need_load_res()) { return; }
//
//    ////AutoLeaveRunThis{
//    ////    this->set_need_load_res(false);
//    ////});
//
//    //xyTextureInfo m_backTextureInfo;
//    //if (!pj_GetResManager().pjLoadFile(u8R"(A:\git\pj\res\gires3.wdf)", 100))
//    //{
//    //    return;
//    //}
//
//    //quint64 tempKey = (((quint64)100) << 32) + 578293861;
//    //QVector<QImage*> imageVector;
//    //if (!pj_GetResManager().pjGetWasTextures(tempKey, m_backTextureInfo, imageVector))
//    //{
//    //    return;
//    //}
//
//    //if (imageVector.size() == 1)
//    //{
//    //    QImage* xImage = imageVector[0];
//    //    QWidget* xParent = this->parentWidget()->parentWidget();
//    //    if (xParent)
//    //    {
//    //        xParent->setMinimumSize(QSize(m_backTextureInfo.width, m_backTextureInfo.height));
//    //        xParent->setMaximumSize(QSize(m_backTextureInfo.width, m_backTextureInfo.height));
//
//    //        QPainter xQPainter(xImage);
//    //        xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"嗝屁了");
//    //        QPalette palette;
//    //        palette.setBrush(QPalette::ColorRole::Background, QBrush(*xImage));
//    //        xParent->setPalette(palette);
//    //        return;
//    //    }
//    //}
//}

//void
//pj_widget::paintEvent(QPaintEvent *event)
//{
//    QPainter xQPainter(this);
//    xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"嗝屁了");
//}

//void
//pj_widget::keyPressEvent(QKeyEvent *event)
//{
//}
//
//void
//pj_widget::paintEvent(QPaintEvent *event)
//{
//    ;
//}
//
//
//void
//pj_widget::closeEvent(QCloseEvent *event)
//{
//    QWidget* xParent = this->parentWidget()->parentWidget();
//    if (xParent)
//    {
//        xParent->setPalette(QPalette());
//    }
//}
//
//bool
//pj_widget::is_need_load_res() const {
//    Q_D(const pj_widget);
//    return d->m_need_load_res;
//}
//
//void
//pj_widget::set_need_load_res(bool v) {
//    Q_D(pj_widget);
//    d->m_need_load_res = v;
//}


bool pj_widget::isNeedLoadRes() const
{
    Q_D(const pj_widget);
    return d->_needLoadRes;
}
void pj_widget::setNeedLoadRes(const bool &v)
{
    Q_D(pj_widget);
    d->_needLoadRes = v;
}

QString pj_widget::resFileName() const
{
    Q_D(const pj_widget);
    return d->_resFileName;
}
void pj_widget::setResFileName(const QString &v)
{
    Q_D(pj_widget);
    d->_resFileName = v;
}

quint32 pj_widget::resKey() const
{
    Q_D(const pj_widget);
    return d->_resKey;
}
void pj_widget::setResKey(const quint32 &v)
{
    Q_D(pj_widget);
    d->_resKey = v;
}
