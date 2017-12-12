#include "pj_checkbox.h"
#include "pj_checkboxplugin.h"

#include <QtCore/QtPlugin>

pj_checkboxPlugin::pj_checkboxPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void pj_checkboxPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool pj_checkboxPlugin::isInitialized() const
{
    return initialized;
}

QWidget *pj_checkboxPlugin::createWidget(QWidget *parent)
{
    return new pj_checkbox(parent);
}

QString pj_checkboxPlugin::name() const
{
    return "pj_checkbox";
}

QString pj_checkboxPlugin::group() const
{
    return "My Plugins";
}

QIcon pj_checkboxPlugin::icon() const
{
    return QIcon();
}

QString pj_checkboxPlugin::toolTip() const
{
    return QString();
}

QString pj_checkboxPlugin::whatsThis() const
{
    return QString();
}

bool pj_checkboxPlugin::isContainer() const
{
    return false;
}

QString pj_checkboxPlugin::domXml() const
{
    return "<widget class=\"pj_checkbox\" name=\"pj_checkbox_\">\n"
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

QString pj_checkboxPlugin::includeFile() const
{
    return "pj_checkbox.h";
}
