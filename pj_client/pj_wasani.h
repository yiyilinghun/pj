#pragma once
#include <QtWidgets/QGraphicsItem>
#include <QtGui/QPainter>
#include <QtCore/QTime>
#include "pj_loader.h"

class pj_wasani;
class pjWasaniAssist : public QObject
{
    Q_OBJECT;
    Q_PROPERTY(qint32 indexAni READ indexAni WRITE setIndexAni);
public:
    pjWasaniAssist(pj_wasani* _pj_wasani) :m_pj_wasani(_pj_wasani) {}

    qint32 indexAni() const;
    void setIndexAni(const qint32 &v);

private:
    friend class pj_wasani;
    pj_wasani* m_pj_wasani = nullptr;
    qint32 m_indexAni = 0;
};


class pj_wasani : public QGraphicsItem
{
public:

    pj_wasani(QString&& file, quint32 key);

    virtual QRectF boundingRect() const;
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = Q_NULLPTR);

public:
    XYUnit * m_xyUnit = nullptr;
    pjWasaniAssist _wasaniAssist;
};
