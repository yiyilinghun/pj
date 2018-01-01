#pragma once
#include "Precompiled.h"
#include "pj_loader.h"
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QGraphicsItem>
#include <QTime>
#include <QtGui/QPainter>
//#include <QEvent>

#ifdef QDESIGNER_EXPORT_WIDGETS
#define PJ_DLL_API __declspec(dllexport)
#else
#define PJ_DLL_API __declspec(dllimport)
#endif

//class PJ_DLL_API pj_groupbox : public QOpenGLWidget
class PJ_DLL_API pj_groupbox : public QGroupBox
{
    Q_OBJECT;
    Q_PROPERTY(bool autoBackSize READ autoBackSize WRITE setAutoBackSize);
    Q_PROPERTY(QString resFileName READ resFileName WRITE setResFileName);
    Q_PROPERTY(quint32 resKey READ resKey WRITE setResKey);
    Q_PROPERTY(bool canMove READ canMove WRITE setCanMove);

public:
    pj_groupbox(QWidget *parent = Q_NULLPTR);

public:
    bool autoBackSize() const;
    void setAutoBackSize(const bool &v);

    QString resFileName() const;
    void setResFileName(const QString &v);

    quint32 resKey() const;
    void setResKey(const quint32 &v);

    bool canMove() const;
    void setCanMove(const bool &v);

public:
    void mousePressEvent(QMouseEvent *e);

    void mouseMoveEvent(QMouseEvent *e);

    void mouseReleaseEvent(QMouseEvent *);

    //void paintEvent(QPaintEvent *e) Q_DECL_OVERRIDE;

private:
    void update_backres();

    // ÍÏ×§ÒÆ¶¯
    bool _isDrag = false;
    QPoint _move_position;
    bool _can_move = true;

    // Ö¡ÊýÍ³¼Æ
    QTime timeFPS;
    int sumFPS = 0;
    int uiFPS = 0;

    // ±³¾°Í¼Æ¬
    bool _autoBackSize = true;
    bool _needLoadRes = true;
    QString _resFileName = "";
    quint32 _resKey = 0;
    QVector<QImage*> _backimageVector;
};

