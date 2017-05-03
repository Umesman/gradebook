
#include <QQmlContext>
#include <QDebug>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

#include "Model/gradebookmodel.h"
#include "Model/studentterm.h"
#include "startup.h"
#include "ViewManager/editform.h"


Startup::Startup(QObject *parent) :
    QObject(parent),
    m_engine(*new QQmlApplicationEngine()),
    m_phandler(Q_NULLPTR),
    m_pmodelManager(Q_NULLPTR),
    m_pviewMgr(Q_NULLPTR)

{

    m_phandler = new DataHandler(this);
    m_pmodelManager = new ModelMgr(m_phandler, this);

    m_pviewMgr = m_pmodelManager->getViewMgr();

    /*auto root_context = m_engine.rootContext();
    root_context->setContextProperty("ListModel", m_plistmodel);
    m_engine.load(QUrl(QStringLiteral("qrc:/main.qml")));*/
    // qmlRegisterType<ProxyModel>("proxymodel.test1", 1, 0, "GroupFilter");


    //GradebookModel *model = m_pmodelManager->getModel();
    //ProxyModel *proxyModel = m_pmodelManager->getProxy();

    QQmlContext *root_context = m_engine.rootContext();
    //root_context->setContextProperty("myModel", model);
    //root_context->setContextProperty("myProxyModel", proxyModel);
    root_context->setContextProperty("viewMgr", m_pviewMgr);
    root_context->setContextProperty("editForm", m_pviewMgr->studentForm());

    qmlRegisterType<QSortFilterProxyModel>();


    m_engine.load(QUrl("qrc:/main.qml"));

}

Startup::~Startup()
{

}

void Startup::initialize()
{

}
