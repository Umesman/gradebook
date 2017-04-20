#ifndef STARTUP_H
#define STARTUP_H

#include<QQmlApplicationEngine>
#include <QObject>

#include "Model/datahandler.h"
#include "Model/modelmgr.h"
#include "ViewManager/mainviewmgr.h"

class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup(QObject *parent = 0);

    virtual ~Startup();

signals:

private:
    void initialize();

    QQmlApplicationEngine& m_engine;
    DataHandler* m_phandler;
    ModelMgr* m_pmodelManager;
    MainViewMgr* m_pviewMgr;

};

#endif // STARTUP_H
