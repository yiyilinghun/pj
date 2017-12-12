#pragma once

#include <QtWidgets/QListView>

#ifdef QDESIGNER_EXPORT_WIDGETS
#define PJ_DLL_API __declspec(dllexport)
#else
#define PJ_DLL_API __declspec(dllimport)
#endif

class PJ_DLL_API pj_listview : public QListView
{
    Q_OBJECT

public:
    pj_listview(QWidget *parent = Q_NULLPTR);
};
