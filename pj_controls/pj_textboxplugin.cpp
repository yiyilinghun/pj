#include "MsBase.h"
#include "pj_textbox.h"
#include "pj_textboxplugin.h"

#include <QtCore/QtPlugin>

pj_textboxPlugin::pj_textboxPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void pj_textboxPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool pj_textboxPlugin::isInitialized() const
{
    return initialized;
}

QWidget *pj_textboxPlugin::createWidget(QWidget *parent)
{
    return NEW pj_textbox(parent);
}

QString pj_textboxPlugin::name() const
{
    return "pj_textbox";
}

QString pj_textboxPlugin::group() const
{
    return "My Plugins";
}

QIcon pj_textboxPlugin::icon() const
{
    return QIcon();
}

QString pj_textboxPlugin::toolTip() const
{
    return QString();
}

QString pj_textboxPlugin::whatsThis() const
{
    return QString();
}

bool pj_textboxPlugin::isContainer() const
{
    return false;
}

QString pj_textboxPlugin::domXml() const
{
    return "<widget class=\"pj_textbox\" name=\"pj_textbox_\">\n"
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

QString pj_textboxPlugin::includeFile() const
{
    return "pj_textbox.h";
}
