TEMPLATE = app

QT += qml quick widgets
CONFIG += c++11
CONFIG += console

QMAKE_CXXFLAGS += -Wunused-parameter

SOURCES += main.cpp \
    Model/studentterm.cpp \
    Model/studentcollection.cpp \
    ViewManager/mainviewmgr.cpp \
    Model/datahandler.cpp \
    Model/gradebookmodel.cpp \
    startup.cpp \
    Model/proxymodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Model/studentterm.h \
    Model/studentcollection.h \
    publicdefinitions.h \
    ViewManager/mainviewmgr.h \
    Model/datahandler.h \
    Model/gradebookmodel.h \
    startup.h \
    Model/proxymodel.h
