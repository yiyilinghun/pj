#include "pj_server.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    Ice::InitializationData xInitData;
    xInitData.properties = Ice::createProperties();
    xInitData.properties->load("../../server.cfg");
    return g_ice_server_app.main(argc, argv, xInitData);
}
