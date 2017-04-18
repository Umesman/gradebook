#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>

#include "Model/studentterm.h"
#include "Model/studentcollection.h"
#include "Model/datahandler.h"
#include "startup.h"
#include "Model/gradebookmodel.h"
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);



    Startup startup;
    /*
    QQmlApplicationEngine engine;
    GradebookModel* model = startup.getModel();

    QQmlContext *root_context = engine.rootContext();
    root_context->setContextProperty("myModel", model);

    engine.load(QUrl("qrc:/view.qml"));
    */


    //QQuickView view;
    //view.setResizeMode(QQuickView::SizeRootObjectToView);

    //QQmlContext *ctxt = view.rootContext();
    //ctxt->setContextProperty("myModel", model);

    //view.setSource(QUrl("qrc:view.qml"));
    //view.show();

    return app.exec();
}
