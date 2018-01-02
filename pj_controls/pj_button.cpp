#include "Precompiled.h"
#include "pj_button.h"
#include <QtGui/QPainter>
#include <QtGui/QBitmap>
//#include <QtPlugin>
//Q_IMPORT_PLUGIN(qjpeg)
//Q_IMPORT_PLUGIN(qjpeg)

#define AUTO_REPEAT_DELAY  300
#define AUTO_REPEAT_INTERVAL 100
QAbstractButtonPrivate::QAbstractButtonPrivate(QSizePolicy::ControlType type)
    :
#ifndef QT_NO_SHORTCUT
    shortcutId(0),
#endif
    checkable(false), checked(false), autoRepeat(false), autoExclusive(false),
    down(false), blockRefresh(false), pressed(false),
#if QT_CONFIG(buttongroup)
    group(0),
#endif
    autoRepeatDelay(AUTO_REPEAT_DELAY),
    autoRepeatInterval(AUTO_REPEAT_INTERVAL),
    controlType(type)
{}

void pj_buttonPrivate::init()
{
    Q_Q(pj_button);

    _needLoadRes = true;
    _resFileName = "";
    _resKey = 0u;

    //_qPushButton->setParent(parent);
    //_qPushButton->show();
    //_qPushButton->setFixedSize(100, 100);
    //q->setSizePolicy(QSizePolicy(
    //    QSizePolicy::Preferred,
    //    QSizePolicy::Preferred,
    //    QSizePolicy::Frame)
    //);
}


pj_button::pj_button(QWidget *parent)
    : QPushButton(*(NEW pj_buttonPrivate), parent)
{
    Q_D(pj_button);
    d->init();

    this->update_size();
}


bool pj_button::auto_back_size() const
{
    Q_D(const pj_button);
    return d->_auto_back_size;
}
void pj_button::setAuto_back_size(const bool &v)
{
    Q_D(pj_button);
    d->_auto_back_size = v;
}

QString pj_button::resFileName() const
{
    Q_D(const pj_button);
    return d->_resFileName;
}
void pj_button::setResFileName(const QString &v)
{
    Q_D(pj_button);
    d->_resFileName = v;
    this->update_size();
}

quint32 pj_button::resKey() const
{
    Q_D(const pj_button);
    return d->_resKey;
}
void pj_button::setResKey(const quint32 &v)
{
    Q_D(pj_button);
    d->_resKey = v;
    this->update_size();
}

void pj_button::enterEvent(QEvent *)
{
    Q_D(pj_button);
    d->_isHover = true;
}

void pj_button::leaveEvent(QEvent *)
{
    Q_D(pj_button);
    d->_isHover = false;
}

//void pj_button::mousePressEvent(QMouseEvent *e)
//{
//    setBkPalette(150);
//}
//void pj_button::mouseReleaseEvent(QMouseEvent *e)
//{
//    setBkPalette(120);
//    emit clicked();//必须写上，否则不会发出clicked信号  
//}

void
pj_button::paintEvent(QPaintEvent *)
{
    Q_D(pj_button);

    QPainter qPainter;
    qPainter.begin(this);

    quint32 file_key = 0;
    if (!pj_GetResManager().pjLoadFile(this->resFileName(), file_key))
    {
        return;
    }

    quint64 tempKey = (((quint64)file_key) << 32) + this->resKey();
    XYUnit* xyUnit = nullptr;
    if (!pj_GetResManager().pjGetWasTextures(tempKey, xyUnit))
    {
        return;
    }

    if (this->isDown())
    {
        qPainter.drawPixmap(0, 0, QPixmap::fromImage(*(xyUnit->m_ProductImages[1].qImage.get())));
    }
    else if (d->_isHover)
    {
        qPainter.drawPixmap(0, 0, QPixmap::fromImage(*(xyUnit->m_ProductImages[2].qImage.get())));
    }
    else
    {
        qPainter.drawPixmap(0, 0, QPixmap::fromImage(*(xyUnit->m_ProductImages[0].qImage.get())));
    }
    qPainter.end();
}


void pj_button::update_size()
{
    Q_D(pj_button);

    quint32 file_key = 0;
    if (!pj_GetResManager().pjLoadFile(this->resFileName(), file_key))
    {
        return;
    }

    quint64 tempKey = (((quint64)file_key) << 32) + this->resKey();
    XYUnit* xyUnit = nullptr;
    if (!pj_GetResManager().pjGetWasTextures(tempKey, xyUnit))
    {
        return;
    }

    if (xyUnit->m_ProductImages.size() > 0)
    {
        QImage* xImage = xyUnit->m_ProductImages[0].qImage.get();
        this->setMinimumSize(xImage->size());
        this->setMaximumSize(xImage->size());
    }
}
