#include "modelmgr.h"
#include "studentcollection.h"
#include "datahandler.h"
#include "ViewManager/mainviewmgr.h"
#include "proxymodel.h"

ModelMgr::ModelMgr(DataHandler *handler, QObject *parent) :
    QObject(parent),
    m_phandler(handler),
    m_pmodel(new GradebookModel()),
    m_pproxyModel(new ProxyModel(m_pmodel, this)),
    m_pviewManager(Q_NULLPTR)
{
    qDebug() << Q_FUNC_INFO;
    setModelSource();
    m_pviewManager = new MainViewMgr(this);
}

ModelMgr::~ModelMgr()
{
    qDebug() << Q_FUNC_INFO;
    delete m_pmodel;
    m_pmodel = Q_NULLPTR;

    delete m_pproxyModel;
    m_pproxyModel = Q_NULLPTR;

    delete m_pviewManager;
    m_pviewManager = Q_NULLPTR;
}

void ModelMgr::setModelSource()
{
    qDebug() << Q_FUNC_INFO;
    if (m_phandler)
        m_pmodel->setModelSource(const_cast<StudentCollection*> (m_phandler->getCollection()));

    setProxySource();
}

void ModelMgr::setProxySource()
{
    qDebug() << Q_FUNC_INFO;
    m_pproxyModel->setSourceModel(m_pmodel);
}

void ModelMgr::setPassedFilter(bool passed)
{
    m_pproxyModel->setPassed(passed);
}

void ModelMgr::setGroupFilter(int groupFilter)
{
    qDebug() << Q_FUNC_INFO << " Group: " << groupFilter;
    m_pproxyModel->setFilter(groupFilter);
}

GradebookModel *ModelMgr::getModel()
{
    qDebug() << Q_FUNC_INFO;
    return m_pmodel;
}

ProxyModel *ModelMgr::getProxy()
{
    qDebug() << Q_FUNC_INFO;
    return m_pproxyModel;
}

MainViewMgr *ModelMgr::getViewMgr()
{
    qDebug() << Q_FUNC_INFO;
    return m_pviewManager;
}

void ModelMgr::sltAddRow(const StudentTerm &st)
{
    qDebug() << Q_FUNC_INFO;
    if (Q_NULLPTR != m_pmodel)
        if (m_pmodel->addData(st))
            emit sgnRowAdded(st);
}

void ModelMgr::sltRemoveRow(int row)
{
    qDebug() << Q_FUNC_INFO;
    if (Q_NULLPTR != m_pmodel)
        if (m_pmodel->removeRow(row))
            emit sgnRowRemoved(row);
}

void ModelMgr::sltChangeStudentInfo(const QModelIndex &index, const QVariant &value, int role)
{
    //New QModelIndex objects are created by the model
    //using the QAbstractItemModel::createIndex() function
    qDebug() << Q_FUNC_INFO;
    if (Q_NULLPTR != m_pmodel)
        if (m_pmodel->setData(index, value, role))
            emit sgnStudentInfoChanged(index, value, role);

}

void ModelMgr::sltPassedConditionChanged(bool cond)
{
    qDebug() << Q_FUNC_INFO;
    if (Q_NULLPTR != m_pproxyModel) {
        m_pproxyModel->setPassed(cond);
    }
}

void ModelMgr::sltFilterChanged(int filter)
{
    qDebug() << Q_FUNC_INFO;
    if (Q_NULLPTR != m_pproxyModel) {
        if (!(filter > ProxyModel::Proxy_Filter::GROUP_ALL || filter < ProxyModel::Proxy_Filter::GROUP_A))
            m_pproxyModel->setFilter(filter);
    }
}

void ModelMgr::connectSignals()
{
    qDebug() << Q_FUNC_INFO;
    connect(m_pviewManager, &MainViewMgr::sgnAddRow, this, &ModelMgr::sltAddRow);
    connect(m_pviewManager, &MainViewMgr::sgnRemoveRow, this, &ModelMgr::sltRemoveRow);
    connect(m_pviewManager, &MainViewMgr::sgnChangeStudentInfo, this, &ModelMgr::sltChangeStudentInfo);
    connect(m_pviewManager, &MainViewMgr::sgnPassedConditionChanged, this, &ModelMgr::sltPassedConditionChanged);
    connect(m_pviewManager, &MainViewMgr::sgnFilterChanged, this, &ModelMgr::sltFilterChanged);

    connect(this, &ModelMgr::sgnRowAdded, m_phandler, &DataHandler::sltRowAdded);
    connect(this, &ModelMgr::sgnRowRemoved, m_phandler, &DataHandler::sltRowRemoved);
    connect(this, &ModelMgr::sgnStudentInfoChanged, m_phandler, &DataHandler::sltStudentInfoChanged);
}
