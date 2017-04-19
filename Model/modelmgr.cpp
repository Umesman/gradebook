#include "modelmgr.h"
#include "studentcollection.h"
#include "datahandler.h"
#include "ViewManager/mainviewmgr.h"
#include "proxymodel.h"

ModelMgr::ModelMgr(DataHandler *handler, MainViewMgr *viewmgr, QObject *parent) :
    QObject(parent),
    m_phandler(handler),
    m_pviewManager(viewmgr),
    m_pmodel(new GradebookModel()),
    m_pproxymodel(new ProxyModel(m_pmodel, this))
{
    setModelSource();
}

ModelMgr::~ModelMgr()
{
    delete m_pmodel;
    delete m_pproxymodel;
}

void ModelMgr::setModelSource()
{
    if (m_phandler)
        m_pmodel->setModelSource(const_cast<StudentCollection*> (m_phandler->getCollection()));
}

void ModelMgr::setProxySource()
{
    m_pproxymodel->setSourceModel(m_pmodel);
}

GradebookModel *ModelMgr::getModel()
{
    return m_pmodel;
}

ProxyModel *ModelMgr::getProxy()
{
    return m_pproxy;
}

void ModelMgr::sltAddRow(const StudentTerm &st)
{
    if (Q_NULLPTR != m_pmodel)
        if (m_pmodel->addData(st))
            emit sgnRowAdded(st);
}

void ModelMgr::sltRemoveRow(int row)
{
    if (Q_NULLPTR != m_pmodel)
        if (m_pmodel->removeRow(row))
            emit sgnRowRemoved(row);
}

void ModelMgr::sltChangeStudentInfo(const QModelIndex &index, const QVariant &value, int role)
{
    //New QModelIndex objects are created by the model
    //using the QAbstractItemModel::createIndex() function
    if (Q_NULLPTR != m_pmodel)
        if (m_pmodel->setData(index, value, role))
            emit sgnStudentInfoChanged(index, value, role);

}

void ModelMgr::sltPassedConditionChanged(bool cond)
{
    if (Q_NULLPTR != m_pproxymodel) {
        m_pproxymodel->setPassed(cond);
    }
}

void ModelMgr::sltFilterChanged(int filter)
{
    if (Q_NULLPTR != m_pproxymodel) {
        if (!(filter > ProxyModel::Proxy_Filter::GROUP_ALL || filter < ProxyModel::Proxy_Filter::GROUP_A))
            m_pproxymodel->setFilter(filter);
    }
}

void ModelMgr::connectSignals()
{

}
