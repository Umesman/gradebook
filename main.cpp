#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>

#include "Model/studentterm.h"
#include "Model/studentcollection.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    StudentTerm *st = new StudentTerm(891, "Bogdan", "2003A", "bogdan.francu6@gmail.com",
                   9, 8.2, 11, 6.3, 7.2);

    StudentCollection colonoscopy;
    colonoscopy.addEntry(st);
    std::cout << colonoscopy;

    colonoscopy.addEntry(new StudentTerm(991, "RRR", "2004B", "rrr@rrr.com",
                                         6, 2.4, 5, 8, 9.10));
    std::cout << *st;

    std::cout << colonoscopy;

    return app.exec();
}
