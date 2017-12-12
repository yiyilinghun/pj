#include "pj_toolbox.h"
#include "pj_toolboxplugin.h"

#include <QtCore/QtPlugin>

pj_toolboxPlugin::pj_toolboxPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void pj_toolboxPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool pj_toolboxPlugin::isInitialized() const
{
    return initialized;
}

QWidget *pj_toolboxPlugin::createWidget(QWidget *parent)
{
    return new pj_toolbox(parent);
}

QString pj_toolboxPlugin::name() const
{
    return "pj_toolbox";
}

QString pj_toolboxPlugin::group() const
{
    return "My Plugins";
}

QIcon pj_toolboxPlugin::icon() const
{
    return QIcon();
}

QString pj_toolboxPlugin::toolTip() const
{
    return QString();
}

QString pj_toolboxPlugin::whatsThis() const
{
    return QString();
}

bool pj_toolboxPlugin::isContainer() const
{
    return false;
}

QString pj_toolboxPlugin::domXml() const
{
    return "<widget class=\"pj_toolbox\" name=\"pj_toolbox_\">\n"
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

QString pj_toolboxPlugin::includeFile() const
{
    return "pj_toolbox.h";
}
