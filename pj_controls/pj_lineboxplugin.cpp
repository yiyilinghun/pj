#include "pj_linebox.h"
#include "pj_lineboxplugin.h"
#include <QtCore/QtPlugin>
#include <QMessageBox>

pj_lineboxPlugin::pj_lineboxPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

void pj_lineboxPlugin::initialize(QDesignerFormEditorInterface* core)
{
    if (initialized)
        return;

    initialized = true;
}

bool pj_lineboxPlugin::isInitialized() const
{
    return initialized;
}

QWidget *pj_lineboxPlugin::createWidget(QWidget *parent)
{
    return new pj_linebox(parent, true);
}

QString pj_lineboxPlugin::name() const
{
    return "pj_linebox";
}

QString pj_lineboxPlugin::group() const
{
    return "pj_plugins";
}

QIcon pj_lineboxPlugin::icon() const
{
    return QIcon();
}

QString pj_lineboxPlugin::toolTip() const
{
    return QString();
}

QString pj_lineboxPlugin::whatsThis() const
{
    return QString();
}

bool pj_lineboxPlugin::isContainer() const
{
    return false;
}

QString pj_lineboxPlugin::domXml() const
{
    return "<widget class=\"pj_linebox\" name=\"pj_linebox\">\n"
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

QString pj_lineboxPlugin::includeFile() const
{
    return "pj_linebox.h";
}
