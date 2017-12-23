#pragma once
#include "MsBase.h"
#include "pj_loader.h"
#include <QtWidgets\private\qwidget_p.h>

#ifdef QDESIGNER_EXPORT_WIDGETS
#define PJ_DLL_API __declspec(dllexport)
#else
#define PJ_DLL_API __declspec(dllimport)
#endif


class PJ_DLL_API pj_widgetPrivate;
class PJ_DLL_API pj_widget : public QWidget
{
    Q_OBJECT;
    Q_PROPERTY(bool needLoadRes READ isNeedLoadRes WRITE setNeedLoadRes);
    Q_PROPERTY(QString resFileName READ resFileName WRITE setResFileName);
    Q_PROPERTY(quint32 resKey READ resKey WRITE setResKey);

public:
    explicit pj_widget(QWidget *parent = Q_NULLPTR);
    //public Q_SLOTS:
    //void createEvent(WId = 0, bool initializeWindow = true, bool destroyOldWindow = true);
protected:
    //bool event(QEvent *event) Q_DECL_OVERRIDE;
    //virtual void wheelEvent(QWheelEvent *event);
    //virtual void showEvent(QShowEvent *event);
    //virtual void mouseMoveEvent(QMouseEvent *event);
    //virtual void paintEvent(QPaintEvent *event);
    //void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

    //virtual void keyPressEvent(QKeyEvent *event);
    //virtual void paintEvent(QPaintEvent *event);
    //virtual void closeEvent(QCloseEvent *event);

protected:
    //pj_widget(pj_widgetPrivate& dd, QWidget* parent = Q_NULLPTR);
private:
    Q_DISABLE_COPY(pj_widget);
    Q_DECLARE_PRIVATE(pj_widget);
    void update_backres();

public:
    bool isNeedLoadRes() const;
    void setNeedLoadRes(const bool &v);

    QString resFileName() const;
    void setResFileName(const QString &v);

    quint32 resKey() const;
    void setResKey(const quint32 &v);
};

class PJ_DLL_API pj_widgetPrivate : public QWidgetPrivate
{
    Q_DECLARE_PUBLIC(pj_widget);

public:
    //explicit pj_widgetPrivate(int version = QObjectPrivateVersion) {}
    //~pj_widgetPrivate() {}

    void init();

private:
    bool _needLoadRes = true;
    QString _resFileName = "";
    quint32 _resKey = 0;
};
