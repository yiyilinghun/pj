#include "Precompiled.h"
#include <qevent.h>
#include "pj_groupbox.h"

pj_groupbox::pj_groupbox(QWidget *parent)
    : QGroupBox(parent)
    //: QOpenGLWidget(parent)
{
    timeFPS.start();
    //this->setFont(QFont(u8"¿¬Ìå", 20));
}



bool pj_groupbox::autoBackSize() const
{
    //Q_D(const pj_groupbox);
    return this->_autoBackSize;
}
void pj_groupbox::setAutoBackSize(const bool &v)
{
    //Q_D(pj_groupbox);
    this->_autoBackSize = v;
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

bool pj_groupbox::canMove() const
{
    return _can_move;
}

void pj_groupbox::setCanMove(const bool &v)
{
    _can_move = v;
}


void pj_groupbox::mousePressEvent(QMouseEvent *e)
{
    if (_can_move && e->button() == Qt::LeftButton)
    {
        _isDrag = true;
        _move_position = e->globalPos() - this->pos();
        e->accept();
    }
}

void pj_groupbox::mouseMoveEvent(QMouseEvent *e)
{
    if (_can_move && _isDrag && (e->buttons() && Qt::LeftButton))
    {
        auto x = e->globalPos() - _move_position;
        move(e->globalPos() - _move_position);
        e->accept();
    }
}

void pj_groupbox::mouseReleaseEvent(QMouseEvent *)
{
    if (_can_move)
    {
        _isDrag = false;
        this->update();
    }
}


//void pj_groupbox::paintEvent(QPaintEvent *e)
//{
//    QPainter qPainter(this);
//    if (_backimageVector.size() > 0)
//    {
//        qPainter.drawImage(0, 0, *_backimageVector[0]);
//    }
//
//    if (timeFPS.elapsed() > 1000)
//    {
//        timeFPS.restart();
//        uiFPS = sumFPS;
//        sumFPS = 0;
//    }
//    sumFPS++;
//    qPainter.drawText(QRect(5, 5, 400, 400), QString("ui_fps:%1\nui_name:%2").arg(uiFPS).arg(this->objectName()));
//}


void pj_groupbox::update_backres()
{
    xyTextureInfo m_backTextureInfo;
    quint32 file_key = 0;
    if (!pj_GetResManager().pjLoadFile(this->resFileName(), file_key))
    {
        return;
    }

    quint64 tempKey = (((quint64)file_key) << 32) + this->resKey();

    _backimageVector.clear();
    if (!pj_GetResManager().pjGetWasTextures(tempKey, m_backTextureInfo, _backimageVector))
    {
        return;
    }

    if (_backimageVector.size() > 0)
    {
        QImage* xImage = _backimageVector[0];
        //QPainter xQPainter(xImage);
        //xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"àÃÆ¨ÁË");
        QPalette palette;
        palette.setBrush(QPalette::ColorRole::Background, QBrush(*xImage));
        this->setAutoFillBackground(true);
        this->setPalette(palette);

        if (this->autoBackSize())
        {
            this->setMinimumSize(xImage->size());
            this->setMaximumSize(xImage->size());
            this->setFixedSize(xImage->size());
            this->setGeometry(QRect(0, 0, xImage->width(), xImage->height()));
        }
    }
}

