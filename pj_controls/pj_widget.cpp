#include "Precompiled.h"
#include "pj_widget.h"
#include <QtGui/QPainter>
//#include <QtWidgets/QMessageBox>


void pj_widgetPrivate::init()
{
    Q_Q(pj_widget);

    _needLoadRes = true;
    _resFileName = "d:\\gires3.wdf";
    _resKey = 2904516639u;

    q->setSizePolicy(QSizePolicy(
        QSizePolicy::Preferred,
        QSizePolicy::Preferred,
        QSizePolicy::Frame)
    );
}

pj_widget::pj_widget(QWidget *parent)
    : QWidget(*(NEW pj_widgetPrivate), parent, Qt::WindowFlags::enum_type::Widget)
{
    Q_D(pj_widget);
    d->init();

    this->update_backres();
}   

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
    this->update_backres();
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

    if (imageVector.size() == 1)
    {
        QImage* xImage = imageVector[0];
        QPainter xQPainter(xImage);
        xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"àÃÆ¨ÁË");
        QPalette palette;
        palette.setBrush(QPalette::ColorRole::Background, QBrush(*xImage));
        this->setAutoFillBackground(true);
        this->setPalette(palette);
    }
}
