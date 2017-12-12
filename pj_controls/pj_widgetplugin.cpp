#include "pj_widget.h"
#include "pj_widgetplugin.h"

#include <QtCore/QtPlugin>

pj_buttuonPlugin::pj_buttuonPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void pj_buttuonPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool pj_buttuonPlugin::isInitialized() const
{
    return initialized;
}

QWidget *pj_buttuonPlugin::createWidget(QWidget *parent)
{
    return new pj_widget(parent);
}

QString pj_buttuonPlugin::name() const
{
    return "pj_widget";
}

QString pj_buttuonPlugin::group() const
{
    return "My Plugins";
}

QIcon pj_buttuonPlugin::icon() const
{
    return QIcon();
}

QString pj_buttuonPlugin::toolTip() const
{
    return QString();
}

QString pj_buttuonPlugin::whatsThis() const
{
    return QString();
}

bool pj_buttuonPlugin::isContainer() const
{
    return false;
}

QString pj_buttuonPlugin::domXml() const
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

QString pj_buttuonPlugin::includeFile() const
{
    return "pj_widget.h";
}
