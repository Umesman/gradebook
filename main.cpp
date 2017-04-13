#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>

#include "Model/studentterm.h"
#include "Model/studentcollection.h"
#include "Model/datahandler.h"
#include "startup.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    Startup startup;

    //or (auto it = lojique.getCollectionList()->begin();
        // it != lojique.getCollectionList()->end(); it ++)
      //  std::cout << *it;

    return app.exec();
}
