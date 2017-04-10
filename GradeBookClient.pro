TEMPLATE = app

QT += qml quick
CONFIG += c++11
CONFIG += console


SOURCES += main.cpp \
    Model/studentterm.cpp \
    Model/studentcollection.cpp \
    ViewManager/mainviewmgr.cpp \
    Model/datahandler.cpp

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
    Model/datahandler.h
