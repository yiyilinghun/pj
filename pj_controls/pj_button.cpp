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

    //this->update_backres();
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
    //this->update_backres();
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
    //this->update_backres();
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

    xyTextureInfo m_backTextureInfo;
    quint32 file_key = 0;
    if (!pj_GetResManager().pjLoadFile(this->resFileName(), file_key))
    {
        return;
    }

    quint64 tempKey = (((quint64)file_key) << 32) + this->resKey();
    QVector<QImage*> imageVector;
    if (!pj_GetResManager().pjGetWasTextures(tempKey, m_backTextureInfo, imageVector))
    {
        return;
    }

    //imageVector[0]->save("d:\\0.png", "PNG");
    //imageVector[1]->save("d:\\1.png", "PNG");
    //imageVector[2]->save("d:\\2.png", "PNG");

    if (this->isDown())
    {
        qPainter.drawPixmap(0, 0, QPixmap::fromImage(*imageVector[1]));
    }
    else if (d->_isHover)
    {
        qPainter.drawPixmap(0, 0, QPixmap::fromImage(*imageVector[2]));
    }
    else
    {
        qPainter.drawPixmap(0, 0, QPixmap::fromImage(*imageVector[0]));
    }
    qPainter.end();
}

//
//void pj_button::update_backres()
//{
//    Q_D(pj_button);
//
//    xyTextureInfo m_backTextureInfo;
//    quint32 file_key = 0;
//    if (!pj_GetResManager().pjLoadFile(this->resFileName(), file_key))
//    {
//        return;
//    }
//
//    quint64 tempKey = (((quint64)file_key) << 32) + this->resKey();
//    QVector<QImage*> imageVector;
//    if (!pj_GetResManager().pjGetWasTextures(tempKey, m_backTextureInfo, imageVector))
//    {
//        return;
//    }
//
//    if (imageVector.size() > 0)
//    {
//        //QPushButton* x = NEW QPushButton((QWidget*)this->parent());
//        QImage* xImage = imageVector[0];
//        //QPainter xQPainter(xImage);
//        //xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"嗝屁了");
//
//        QIcon icon;
//        QPixmap qPixmap = QPixmap::fromImage(*xImage);
//        icon.addPixmap(qPixmap);
//        this->setIcon(icon);
//        this->setIconSize(qPixmap.size());
//        this->setFixedSize(qPixmap.size());
//        //this->setMask(qPixmap.mask());
//
//        //QPalette palette;
//        //for (int i = 0; i < 20; i++)
//        //{
//        //    palette.setColor(QPalette::ColorRole(i), QColor(255, 0, 0));
//        //}
//
//        //this->setAutoFillBackground(true);
//        //palette.setColor(QPalette::Button, QColor(255, 0, 0));
//        //palette.setColor(QPalette::Button, QColor(255, 0, 0));
//
//        //palette.setBrush(QPalette::ColorRole::Background, QBrush(*xImage));
//        //palette.setBrush(QPalette::ColorRole::Background, QBrush(*xImage));
//        //palette.setBrush(QPalette::ColorRole::Window, QBrush(*xImage));
//        //x->setPalette(palette);
//        //x->setStyleSheet("background-color: rgb(170, 0, 255);");
//        //x->setAutoFillBackground(true);
//        //x->show();
//        //x->move(10, 10);
//
//        //if (this->auto_back_size())
//        //{
//        //    this->setFixedSize(xImage->size());
//        //}
//    }
//}
