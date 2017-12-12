#pragma once

#include <QtWidgets/QTextEdit>

#ifdef QDESIGNER_EXPORT_WIDGETS
#define PJ_DLL_API __declspec(dllexport)
#else
#define PJ_DLL_API __declspec(dllimport)
#endif

class PJ_DLL_API pj_textbox : public QTextEdit
{
    Q_OBJECT

public:
    pj_textbox(QWidget *parent = Q_NULLPTR);
};
