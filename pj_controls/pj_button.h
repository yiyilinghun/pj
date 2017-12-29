#pragma once
#include <QtWidgets/QPushButton>
#include <QtWidgets/private/qwidget_p.h>
#include <QtWidgets/private/qpushbutton_p.h>

#ifdef QDESIGNER_EXPORT_WIDGETS
#define PJ_DLL_API __declspec(dllexport)
#else
#define PJ_DLL_API __declspec(dllimport)
#endif

class PJ_DLL_API pj_buttonPrivate;
class PJ_DLL_API pj_button : public QPushButton
{
    Q_OBJECT;
    Q_PROPERTY(bool auto_back_size READ auto_back_size WRITE setAuto_back_size);
    Q_PROPERTY(QString resFileName READ resFileName WRITE setResFileName);
    Q_PROPERTY(quint32 resKey READ resKey WRITE setResKey);

public:
    pj_button(QWidget *parent = Q_NULLPTR);


protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
    virtual void enterEvent(QEvent *);
    virtual void leaveEvent(QEvent *);

private:
    Q_DISABLE_COPY(pj_button);
    Q_DECLARE_PRIVATE(pj_button);
    void update_size();

public:
    bool auto_back_size() const;
    void setAuto_back_size(const bool &v);

    QString resFileName() const;
    void setResFileName(const QString &v);

    quint32 resKey() const;
    void setResKey(const quint32 &v);
};


class PJ_DLL_API pj_buttonPrivate : public QPushButtonPrivate
{
    Q_DECLARE_PUBLIC(pj_button);

public:
    void init();

private:
    bool _auto_back_size = true;
    bool _needLoadRes = true;
    bool _isHover = false;
    QString _resFileName = "";
    quint32 _resKey = 0;
};
