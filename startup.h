#ifndef STARTUP_H
#define STARTUP_H

#include <QObject>

class QQmlApplicationEngine;

class DataHandler;
class GradebookModel;
class ProxyModel;

class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup(QObject *parent = 0);

    inline GradebookModel* getModel()
    {
        return m_plistmodel;
    }

signals:

private:
    QQmlApplicationEngine& m_engine;
    DataHandler* m_phandler;
    GradebookModel* m_plistmodel;
    //ProxyModel *m_pproxymodel;

};

#endif // STARTUP_H
