#pragma once

#include <QtWidgets/QLabel>

#ifdef QDESIGNER_EXPORT_WIDGETS
#define PJ_DLL_API __declspec(dllexport)
#else
#define PJ_DLL_API __declspec(dllimport)
#endif

class PJ_DLL_API pj_label : public QLabel
{
    Q_OBJECT;
    Q_PROPERTY(int fsize READ fsize WRITE setfsize);


public:
    pj_label(QWidget *parent = Q_NULLPTR);


    int fsize() const
    {
        return _fsize;
    }
    void setfsize(const int &v)
    {
        qDebug(QString("%1").arg(v).toStdString().c_str());
        _fsize = v;
        const auto& x = this->font();
        QFont xNew(x.family(), x.pointSize(), x.weight());
        xNew.setPointSize(_fsize);
        this->setFont(xNew);
    }

private:
    int _fsize = 0;
};
