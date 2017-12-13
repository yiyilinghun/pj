#include "MsBase.h"
#include "pj_label.h"
#include "pj_labelplugin.h"

#include <QtCore/QtPlugin>

pj_labelPlugin::pj_labelPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void pj_labelPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool pj_labelPlugin::isInitialized() const
{
    return initialized;
}

QWidget *pj_labelPlugin::createWidget(QWidget *parent)
{
    return NEW pj_label(parent);
}

QString pj_labelPlugin::name() const
{
    return "pj_label";
}

QString pj_labelPlugin::group() const
{
    return "My Plugins";
}

QIcon pj_labelPlugin::icon() const
{
    return QIcon();
}

QString pj_labelPlugin::toolTip() const
{
    return QString();
}

QString pj_labelPlugin::whatsThis() const
{
    return QString();
}

bool pj_labelPlugin::isContainer() const
{
    return false;
}

QString pj_labelPlugin::domXml() const
{
    return "<widget class=\"pj_label\" name=\"pj_label_\">\n"
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

QString pj_labelPlugin::includeFile() const
{
    return "pj_label.h";
}
