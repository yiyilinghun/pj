# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = lib
TARGET = pj_button
#DESTDIR = ../bin/Release/x64
QT += core xml designer widgets gui
CONFIG += debug_and_release_target plugin
DEFINES += _UNICODE WIN64 QT_DLL QT_DESIGNER_LIB QT_WIDGETS_LIB QT_XML_LIB
INCLUDEPATH += . \
    ./GeneratedFiles \
    ./GeneratedFiles/Release \
    $(SolutionDir)pj_common \
    $(ICEDIR)/baselib
#LIBS += -L"$(OutDir)" \
#    -L"$(SolutionDir)packages/zeroc.ice.v140.3.7.0/build/native/lib/$(Platform)/$(Configuration)" \
#    -L"$(SolutionDir)packages/zeroc.freeze.v140.3.7.0/build/native/lib/$(Platform)/$(Configuration)" \
#    -l01.pj_common
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/release
OBJECTS_DIR += release
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(pj_button.pri)

#Install the plugin in the designer plugins directory.
target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target
