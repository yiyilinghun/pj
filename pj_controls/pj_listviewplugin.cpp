#include "MsBase.h"
#include "pj_listview.h"
#include "pj_listviewplugin.h"

#include <QtCore/QtPlugin>

pj_listviewPlugin::pj_listviewPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void pj_listviewPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool pj_listviewPlugin::isInitialized() const
{
    return initialized;
}

QWidget *pj_listviewPlugin::createWidget(QWidget *parent)
{
    return NEW pj_listview(parent);
}

QString pj_listviewPlugin::name() const
{
    return "pj_listview";
}

QString pj_listviewPlugin::group() const
{
    return "My Plugins";
}

QIcon pj_listviewPlugin::icon() const
{
    return QIcon();
}

QString pj_listviewPlugin::toolTip() const
{
    return QString();
}

QString pj_listviewPlugin::whatsThis() const
{
    return QString();
}

bool pj_listviewPlugin::isContainer() const
{
    return false;
}

QString pj_listviewPlugin::domXml() const
{
    return "<widget class=\"pj_listview\" name=\"pj_listview_\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width>100</width>\n"
        "   <height>100</height>\n"
        "  </rect>\n"
        " </property>\n"
        "</widget>\n";
}

QString pj_listviewPlugin::includeFile() const
{
    return "pj_listview.h";
}
