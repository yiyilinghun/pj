#pragma once
#include <QtWidgets/QGraphicsItem>
#include <QtGui/QPainter>
#include <QtCore/QTime>
#include "pj_loader.h"

//#include "ui_pj_client.h"
//#include "ui_pj_login.h"

class pjWasaniAssist : public QObject
{
    Q_OBJECT;
    Q_PROPERTY(qint32 indexAni READ indexAni WRITE setIndexAni);
public:
    qint32 indexAni() const {
        return _indexAni;
    }
    void setIndexAni(const qint32 &v){
        _indexAni = v;
    }

private:
    friend class pj_wasani;
    qint32 _indexAni = 0;
};


class pj_wasani : public QGraphicsItem
{
public:

    pj_wasani()
    {
        xyTextureInfo m_backTextureInfo;
        quint32 file_key = 0;
        if (!pj_GetResManager().pjLoadFile(R"(A:\git\pj\res\shape.wdf)", file_key))
        {
            return;
        }

        quint64 tempKey = (((quint64)file_key) << 32) + 0xa896b4;

        _imageVector.clear();
        if (!pj_GetResManager().pjGetWasTextures(tempKey, m_backTextureInfo, _imageVector))
        {
            return;
        }
    }

    virtual QRectF boundingRect() const
    {
        return { 0, 0,
            (Double)_imageVector[_wasaniAssist._indexAni%_imageVector.size()]->width(),
            (Double)_imageVector[_wasaniAssist._indexAni%_imageVector.size()]->height()
        };
    }

    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = Q_NULLPTR)
    {
        painter->drawImage(0, 0, *(_imageVector[_wasaniAssist._indexAni%_imageVector.size()]));
    }

public:
    pjWasaniAssist _wasaniAssist;
//private:
    QVector<QImage*> _imageVector;
};
