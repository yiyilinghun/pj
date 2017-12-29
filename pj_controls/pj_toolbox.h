#pragma once

#include <QtWidgets/QToolBox>

#ifdef QDESIGNER_EXPORT_WIDGETS
#define PJ_DLL_API __declspec(dllexport)
#else
#define PJ_DLL_API __declspec(dllimport)
#endif

class PJ_DLL_API pj_toolbox : public QToolBox
{
    Q_OBJECT

public:
    pj_toolbox(QWidget *parent = Q_NULLPTR);

};
