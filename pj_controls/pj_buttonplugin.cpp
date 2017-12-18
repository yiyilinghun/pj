#include "MsBase.h"
#include "pj_button.h"
#include "pj_buttonplugin.h"

#include <QtCore/QtPlugin>

pj_buttonPlugin::pj_buttonPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void pj_buttonPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool pj_buttonPlugin::isInitialized() const
{
    return initialized;
}

QWidget *pj_buttonPlugin::createWidget(QWidget *parent)
{
    return NEW pj_button(parent);
}

QString pj_buttonPlugin::name() const
{
    return "pj_button";
}

QString pj_buttonPlugin::group() const
{
    return "pj_plugins";
}

QIcon pj_buttonPlugin::icon() const
{
    return QIcon();
}

QString pj_buttonPlugin::toolTip() const
{
    return QString();
}

QString pj_buttonPlugin::whatsThis() const
{
    return QString();
}

bool pj_buttonPlugin::isContainer() const
{
    return false;
}

QString pj_buttonPlugin::domXml() const
{
    return "<widget class=\"pj_button\" name=\"pj_button_\">\n"
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

QString pj_buttonPlugin::includeFile() const
{
    return "pj_button.h";
}
