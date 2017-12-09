#include "pj_widget.h"
#include "pj_widgetplugin.h"

#include <QtCore/QtPlugin>

pj_widgetPlugin::pj_widgetPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void pj_widgetPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool pj_widgetPlugin::isInitialized() const
{
    return initialized;
}

QWidget *pj_widgetPlugin::createWidget(QWidget *parent)
{
    return new pj_widget(parent);
}

QString pj_widgetPlugin::name() const
{
    return "pj_widget";
}

QString pj_widgetPlugin::group() const
{
    return "My Plugins";
}

QIcon pj_widgetPlugin::icon() const
{
    return QIcon();
}

QString pj_widgetPlugin::toolTip() const
{
    return QString();
}

QString pj_widgetPlugin::whatsThis() const
{
    return QString();
}

bool pj_widgetPlugin::isContainer() const
{
    return false;
}

QString pj_widgetPlugin::domXml() const
{
    return "<widget class=\"pj_widget\" name=\"pj_widget_\">\n"
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

QString pj_widgetPlugin::includeFile() const
{
    return "pj_widget.h";
}
