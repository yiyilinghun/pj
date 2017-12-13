#include "MsBase.h"
#include "pj_groupbox.h"
#include "pj_groupboxplugin.h"

#include <QtCore/QtPlugin>

pj_groupboxPlugin::pj_groupboxPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void pj_groupboxPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool pj_groupboxPlugin::isInitialized() const
{
    return initialized;
}

QWidget *pj_groupboxPlugin::createWidget(QWidget *parent)
{
    return NEW pj_groupbox(parent);
}

QString pj_groupboxPlugin::name() const
{
    return "pj_groupbox";
}

QString pj_groupboxPlugin::group() const
{
    return "My Plugins";
}

QIcon pj_groupboxPlugin::icon() const
{
    return QIcon();
}

QString pj_groupboxPlugin::toolTip() const
{
    return QString();
}

QString pj_groupboxPlugin::whatsThis() const
{
    return QString();
}

bool pj_groupboxPlugin::isContainer() const
{
    return false;
}

QString pj_groupboxPlugin::domXml() const
{
    return "<widget class=\"pj_groupbox\" name=\"pj_groupbox_\">\n"
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

QString pj_groupboxPlugin::includeFile() const
{
    return "pj_groupbox.h";
}
