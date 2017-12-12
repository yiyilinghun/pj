#include "pj_tools.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pj_tools w;
    w.show();
    return a.exec();
}
