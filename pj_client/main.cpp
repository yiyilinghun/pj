#include "pj_client.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    Ice::InitializationData xInitData;
    xInitData.properties = Ice::createProperties();
    xInitData.properties->load("../../client.cfg");
    return g_ice_client_app.main(argc, argv, xInitData);
}
