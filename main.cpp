#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>

#include "Model/studentterm.h"
#include "Model/studentcollection.h"
#include "Model/datahandler.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    DataHandler lojique;

    //or (auto it = lojique.getCollectionList()->begin();
        // it != lojique.getCollectionList()->end(); it ++)
      //  std::cout << *it;

    return app.exec();
}
