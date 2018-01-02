#include "Precompiled.h"
#include "pj_loader.h"
#include "pj_wasani.h"

qint32 pjWasaniAssist::indexAni() const {
    return m_indexAni;
}
void pjWasaniAssist::setIndexAni(const qint32 &v) {
    if (v != m_indexAni)
    {
        m_indexAni = v;
        //m_pj_wasani->update();
    }
}

pj_wasani::pj_wasani(QString&& file, quint32 key)
    :_wasaniAssist(this)
{
    quint32 file_key = 0;
    if (!pj_GetResManager().pjLoadFile(std::forward<QString>(file), file_key))
    {
        return;
    }

    quint64 tempKey = (((quint64)file_key) << 32) + key;

    if (!pj_GetResManager().pjGetWasTextures(tempKey, m_xyUnit))
    {
        return;
    }

    this->setZValue(0.0000);
}

QRectF pj_wasani::boundingRect() const
{
    //qDebug(QString("%1,%2,%3,%4").arg(0).arg(0).arg(m_xyUnit->m_xyTextureInfo.width).arg(m_xyUnit->m_xyTextureInfo.height).toStdString().c_str());
    //return QRectF{ this->pos().x(),this->pos().y(),(qreal)m_xyUnit->m_xyTextureInfo.width ,(qreal)m_xyUnit->m_xyTextureInfo.height };
    return QRectF{ 0,0,(qreal)m_xyUnit->m_xyTextureInfo.width ,(qreal)m_xyUnit->m_xyTextureInfo.height };
}

void pj_wasani::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    hotImage& _hotImage = m_xyUnit->m_ProductImages[_wasaniAssist.m_indexAni % m_xyUnit->m_ProductImages.size()];
    painter->drawImage(_hotImage.qPoint, *_hotImage.qImage.get());
}

