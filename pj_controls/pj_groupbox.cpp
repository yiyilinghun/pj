#include "Precompiled.h"
#include "pj_groupbox.h"
#include <QtGui/QPainter>

pj_groupbox::pj_groupbox(QWidget *parent)
    //: QGroupBox(parent)
    : QGroupBox(parent)
{

}



bool pj_groupbox::auto_back_size() const
{
    //Q_D(const pj_groupbox);
    return this->_auto_back_size;
}
void pj_groupbox::setAuto_back_size(const bool &v)
{
    //Q_D(pj_groupbox);
    this->_auto_back_size = v;
}

QString pj_groupbox::resFileName() const
{
    //Q_D(const pj_groupbox);
    return this->_resFileName;
}
void pj_groupbox::setResFileName(const QString &v)
{
    //Q_D(pj_groupbox);
    this->_resFileName = v;
    this->update_backres();
}

quint32 pj_groupbox::resKey() const
{
    //Q_D(const pj_groupbox);
    return this->_resKey;
}
void pj_groupbox::setResKey(const quint32 &v)
{
    //Q_D(pj_groupbox);
    this->_resKey = v;
    this->update_backres();
}

void pj_groupbox::update_backres()
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

