#include "startup.h"
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include "Model/datahandler.h"
#include "Model/gradebookmodel.h"
#include "Model/studentterm.h"

Startup::Startup(QObject *parent) :
    QObject(parent),
    m_engine(*new QQmlApplicationEngine()),
    m_phandler(new DataHandler()),
    m_plistmodel(new GradebookModel(m_phandler))
{
   auto root_context = m_engine.rootContext();

   StudentTerm stefan;
   m_plistmodel->addData(stefan);

   root_context->setContextProperty("ListModel", m_plistmodel);
   m_engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
}
