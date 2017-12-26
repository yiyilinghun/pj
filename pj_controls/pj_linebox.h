#pragma once

#include <QtWidgets/QLineEdit>

#ifdef QDESIGNER_EXPORT_WIDGETS
#define PJ_DLL_API __declspec(dllexport)
#else
#define PJ_DLL_API __declspec(dllimport)
#endif

class PJ_DLL_API pj_linebox : public QLineEdit
{
    Q_OBJECT

public:
    pj_linebox(QWidget *parent = Q_NULLPTR);
};
