#include "pj_robot.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pj_robot w;
    w.show();
    return a.exec();
}
