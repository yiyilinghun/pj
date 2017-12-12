#pragma once

#include <QtWidgets/QPushButton>

#ifdef QDESIGNER_EXPORT_WIDGETS
#define PJ_DLL_API __declspec(dllexport)
#else
#define PJ_DLL_API __declspec(dllimport)
#endif

class PJ_DLL_API pj_button : public QPushButton
{
    Q_OBJECT

public:
    pj_button(QWidget *parent = Q_NULLPTR);
};
