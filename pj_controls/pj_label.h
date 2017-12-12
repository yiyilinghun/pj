#pragma once

#include <QtWidgets/QLabel>

#ifdef QDESIGNER_EXPORT_WIDGETS
#define PJ_DLL_API __declspec(dllexport)
#else
#define PJ_DLL_API __declspec(dllimport)
#endif

class PJ_DLL_API pj_label : public QLabel
{
    Q_OBJECT

public:
    pj_label(QWidget *parent = Q_NULLPTR);
};
