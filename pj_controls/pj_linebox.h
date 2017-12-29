#pragma once

#include <QtWidgets/QLineEdit>

#ifdef QDESIGNER_EXPORT_WIDGETS
#define PJ_DLL_API __declspec(dllexport)
#else
#define PJ_DLL_API __declspec(dllimport)
#endif

class PJ_DLL_API pj_linebox : public QLineEdit
{
    Q_OBJECT;
    Q_PROPERTY(bool lock_size READ lockSize WRITE setLockSize);
    //Q_PROPERTY(QString resFileName READ resFileName WRITE setResFileName);
    //Q_PROPERTY(quint32 resKey READ resKey WRITE setResKey);

public:
    pj_linebox(QWidget *parent = Q_NULLPTR);
    pj_linebox(QWidget *parent, bool inEditor);

public:
    bool lockSize() const
    {
        return _lock_size;
    }

    void setLockSize(const bool &v)
    {
        _lock_size = v;
        if (_lock_size)
        {
            this->setMinimumSize(this->size());
            this->setMaximumSize(this->size());
        }
        else
        {
            this->setMinimumSize(0, 0);
            this->setMaximumSize(16777215, 16777215);
        }
    }

private:
    bool _lock_size = false;
};
