#include "pj_client.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pj_client w;
    w.show();
    return a.exec();
}
