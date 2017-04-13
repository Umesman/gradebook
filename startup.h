#ifndef STARTUP_H
#define STARTUP_H

#include <QObject>

class QQmlApplicationEngine;

class DataHandler;
class GradebookModel;

class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup(QObject *parent = 0);

signals:

private:
    QQmlApplicationEngine& m_engine;
    DataHandler* m_phandler;
    GradebookModel* m_plistmodel;

};

#endif // STARTUP_H
