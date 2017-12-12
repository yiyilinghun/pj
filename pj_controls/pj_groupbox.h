#pragma once

#include <QtWidgets/QGroupBox>

#ifdef QDESIGNER_EXPORT_WIDGETS
#define PJ_DLL_API __declspec(dllexport)
#else
#define PJ_DLL_API __declspec(dllimport)
#endif

class PJ_DLL_API pj_groupbox : public QGroupBox
{
    Q_OBJECT

public:
    pj_groupbox(QWidget *parent = Q_NULLPTR);
};
