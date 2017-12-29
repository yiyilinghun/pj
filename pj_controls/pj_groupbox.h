#pragma once

#include <QtWidgets/QGroupBox>

#ifdef QDESIGNER_EXPORT_WIDGETS
#define PJ_DLL_API __declspec(dllexport)
#else
#define PJ_DLL_API __declspec(dllimport)
#endif

class PJ_DLL_API pj_groupbox : public QGroupBox
{
    Q_OBJECT;
    Q_PROPERTY(bool auto_back_size READ auto_back_size WRITE setAuto_back_size);
    Q_PROPERTY(QString resFileName READ resFileName WRITE setResFileName);
    Q_PROPERTY(quint32 resKey READ resKey WRITE setResKey);

public:
    pj_groupbox(QWidget *parent = Q_NULLPTR);

public:
    bool auto_back_size() const;
    void setAuto_back_size(const bool &v);

    QString resFileName() const;
    void setResFileName(const QString &v);

    quint32 resKey() const;
    void setResKey(const quint32 &v);

private:
    void update_backres();

    bool _auto_back_size = true;
    bool _needLoadRes = true;
    QString _resFileName = "";
    quint32 _resKey = 0;
};

