#pragma once
#include "MsBase.h"
#include "pj_loader.h"
#include <QtWidgets/QDialog>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/private/qdialog_p.h>
//#include <QtWidgets/private/qwidget_p.h>

#ifdef QDESIGNER_EXPORT_WIDGETS
#define PJ_DLL_API __declspec(dllexport)
#else
#define PJ_DLL_API __declspec(dllimport)
#endif


//class PJ_DLL_API pj_widgetPrivate;
class PJ_DLL_API pj_widget : public QMainWindow
{
    Q_OBJECT;
    Q_PROPERTY(bool auto_back_size READ auto_back_size WRITE setAuto_back_size);
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
    //Q_DECLARE_PRIVATE(pj_widget);
    void update_backres();

public:
    bool auto_back_size() const;
    void setAuto_back_size(const bool &v);

    QString resFileName() const;
    void setResFileName(const QString &v);

    quint32 resKey() const;
    void setResKey(const quint32 &v);

private:
    bool _auto_back_size = true;
    bool _needLoadRes = true;
    QString _resFileName = "";
    quint32 _resKey = 0;
};

////class PJ_DLL_API pj_widgetPrivate : public QWidgetPrivate
//class PJ_DLL_API pj_widgetPrivate : public QDialogPrivate
//{
//    Q_DECLARE_PUBLIC(pj_widget);
//
//public:
//    //explicit pj_widgetPrivate(int version = QObjectPrivateVersion) {}
//    //~pj_widgetPrivate() {}
//
//    void init();
//
//private:
//    bool _auto_back_size = true;
//    bool _needLoadRes = true;
//    QString _resFileName = "";
//    quint32 _resKey = 0;
//};
