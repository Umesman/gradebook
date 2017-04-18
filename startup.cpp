
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

#include "Model/datahandler.h"
#include "Model/gradebookmodel.h"
#include "Model/studentterm.h"
#include "Model/proxymodel.h"
#include "startup.h"


Startup::Startup(QObject *parent) :
    QObject(parent),
    m_engine(*new QQmlApplicationEngine()),
    m_phandler(new DataHandler()),
    m_plistmodel(new GradebookModel(m_phandler))//,
    //m_pproxymodel(new ProxyModel(m_plistmodel))
{
    //auto root_context = m_engine.rootContext();

    StudentTerm stefan(892, "Stefan", "C", "stefan@sql.com", 3.80,
                       6.03, 2.92, 3.21, 4.80);

    m_plistmodel->addData(stefan);


    //root_context->setContextProperty("ListModel", m_plistmodel);
    //m_engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    qmlRegisterType<ProxyModel>("proxymodel.test1", 1, 0, "GroupFilter");

    QSortFilterProxyModel *testproxy = new QSortFilterProxyModel;
    testproxy->setSourceModel(m_plistmodel);

    ProxyModel *m_pproxymodel = new ProxyModel();
    m_pproxymodel->setSourceModel(m_plistmodel);

    QQmlContext *root_context = m_engine.rootContext();
    root_context->setContextProperty("myModel", m_plistmodel);
    root_context->setContextProperty("myProxyModel", m_pproxymodel);

    m_engine.load(QUrl("qrc:/main.qml"));

}
