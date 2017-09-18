#include "pj_server.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pj_server w;
    w.show();
    return a.exec();
}
