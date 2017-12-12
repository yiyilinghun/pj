#include "pj_lable.h"
#include "pj_lableplugin.h"

#include <QtCore/QtPlugin>

pj_lablePlugin::pj_lablePlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void pj_lablePlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool pj_lablePlugin::isInitialized() const
{
    return initialized;
}

QWidget *pj_lablePlugin::createWidget(QWidget *parent)
{
    return new pj_lable(parent);
}

QString pj_lablePlugin::name() const
{
    return "pj_lable";
}

QString pj_lablePlugin::group() const
{
    return "My Plugins";
}

QIcon pj_lablePlugin::icon() const
{
    return QIcon();
}

QString pj_lablePlugin::toolTip() const
{
    return QString();
}

QString pj_lablePlugin::whatsThis() const
{
    return QString();
}

bool pj_lablePlugin::isContainer() const
{
    return false;
}

QString pj_lablePlugin::domXml() const
{
    return "<widget class=\"pj_lable\" name=\"pj_lable_\">\n"
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

QString pj_lablePlugin::includeFile() const
{
    return "pj_lable.h";
}
