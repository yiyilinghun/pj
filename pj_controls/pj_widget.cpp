#include "Precompiled.h"
#include "pj_widget.h"
#include <QtGui/QPainter>


//void pj_widgetPrivate::init()
//{
//    Q_Q(pj_widget);
//
//    _needLoadRes = true;
//    _resFileName = "";
//    _resKey = 0u;
//
//    q->setSizePolicy(QSizePolicy(
//        QSizePolicy::Preferred,
//        QSizePolicy::Preferred,
//        QSizePolicy::Frame)
//    );
//}

pj_widget::pj_widget(QWidget *parent)
//: QMainWindow(*(NEW pj_widgetPrivate), parent)
    : QMainWindow(parent)
{
    //Q_D(pj_widget);
    //d->init();

    _needLoadRes = true;
    _resFileName = "";
    _resKey = 0u;

    this->setSizePolicy(QSizePolicy(
        QSizePolicy::Preferred,
        QSizePolicy::Preferred,
        QSizePolicy::Frame)
    );

    this->update_backres();
}

bool pj_widget::auto_back_size() const
{
    //Q_D(const pj_widget);
    return this->_auto_back_size;
}
void pj_widget::setAuto_back_size(const bool &v)
{
    //Q_D(pj_widget);
    this->_auto_back_size = v;
}

QString pj_widget::resFileName() const
{
    //Q_D(const pj_widget);
    return this->_resFileName;
}
void pj_widget::setResFileName(const QString &v)
{
    //Q_D(pj_widget);
    this->_resFileName = v;
    this->update_backres();
}

quint32 pj_widget::resKey() const
{
    //Q_D(const pj_widget);
    return this->_resKey;
}
void pj_widget::setResKey(const quint32 &v)
{
    //Q_D(pj_widget);
    this->_resKey = v;
    this->update_backres();
}

void pj_widget::update_backres()
{
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

    if (imageVector.size() > 0)
    {
        QImage* xImage = imageVector[0];
        QPainter xQPainter(xImage);
        xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"àÃÆ¨ÁË");
        QPalette palette;
        palette.setBrush(QPalette::ColorRole::Background, QBrush(*xImage));
        this->setAutoFillBackground(true);
        this->setPalette(palette);

        if (this->auto_back_size())
        {
            this->setFixedSize(xImage->size());
            this->setMinimumSize(xImage->size());
            this->setMaximumSize(xImage->size());
        }
    }
}

