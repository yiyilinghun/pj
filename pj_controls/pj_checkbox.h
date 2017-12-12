#pragma once

#include <QtWidgets/QCheckBox>

#ifdef QDESIGNER_EXPORT_WIDGETS
#define PJ_DLL_API __declspec(dllexport)
#else
#define PJ_DLL_API __declspec(dllimport)
#endif

class PJ_DLL_API pj_checkbox : public QCheckBox
{
    Q_OBJECT

public:
    pj_checkbox(QWidget *parent = Q_NULLPTR);
};
