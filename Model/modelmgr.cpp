#include "modelmgr.h"
#include "studentcollection.h"
#include "datahandler.h"
#include "ViewManager/mainviewmgr.h"
#include "proxymodel.h"

ModelMgr::ModelMgr(DataHandler *handler, QObject *parent) :
    QObject(parent),
    m_phandler(handler),
    m_pmodel(new GradebookModel()),
    m_pproxyModel(Q_NULLPTR),
    m_pviewManager(Q_NULLPTR)
{
    qDebug() << Q_FUNC_INFO;
    setModelSource();
    m_pproxyModel = new ProxyModel(m_pmodel);
    m_pviewManager = new MainViewMgr(this);
    connectSignals();
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

    //setProxySource();
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

int ModelMgr::getGroupFilter()
{
    return m_pproxyModel->filter();
}

int ModelMgr::getSortRole()
{
    return m_pproxyModel->sortRole();
}

void ModelMgr::setSortRole(int role)
{
    qDebug() << Q_FUNC_INFO << " sort role: " << role;
    m_pproxyModel->setSortRole(role);
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

GradebookModel::StudentRoles ModelMgr::mapAttributeToRole(Attributes attribute)
{
    //using GradebookModel::StudentRoles;

    GradebookModel::StudentRoles ret;

    switch (attribute) {
    case Attributes::ID :
        ret = GradebookModel::StudentRoles::IdRole;
        break;
    case Attributes::FIRST_NAME :
        ret = GradebookModel::StudentRoles::FirstNameRole;
        break;
    case Attributes::LAST_NAME :
        ret = GradebookModel::StudentRoles::LastNameRole;
        break;
    case Attributes::GROUP :
        ret = GradebookModel::StudentRoles::GroupRole;
        break;
    case Attributes::EMAIL :
        ret = GradebookModel::StudentRoles::EmailRole;
        break;
    case Attributes::ASSESSMENTS :
        ret = GradebookModel::StudentRoles::AssessmentsRole;
        break;
    case Attributes::HOMEWORK1 :
        ret = GradebookModel::StudentRoles::Homework1Role;
        break;
    case Attributes::HOMEWORK2 :
        ret = GradebookModel::StudentRoles::Homework2Role;
        break;
    case Attributes::LABGRADE :
        ret = GradebookModel::StudentRoles::LabGradeRole;
        break;
    case Attributes::TESTGRADE :
        ret = GradebookModel::StudentRoles::TestGradeRole;
        break;
    case Attributes::FINAL:
        ret = GradebookModel::StudentRoles::FinalRole;
        break;
    default:
        break;
    }
    qDebug() << Q_FUNC_INFO << attribute;
    return ret;
}

int ModelMgr::indexOfId(int id)
{
    return m_pmodel->indexOfId(id);
}

QModelIndex ModelMgr::modelIndex(int row, int column, QModelIndex parent)
{
    return m_pmodel->index(row, column, parent);
}

const StudentTerm *ModelMgr::modelListValueAt(int row)
{
    return m_pmodel->listValueAt(row);
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
    qDebug() << Q_FUNC_INFO;

    if (Q_NULLPTR != m_pmodel)
        if (m_pmodel->setData(index, value, role))
            emit sgnStudentInfoChanged(index, value, role);

}

//void ModelMgr::sltPassedConditionChanged(bool cond)
//{
//    qDebug() << Q_FUNC_INFO;
//    if (Q_NULLPTR != m_pproxyModel) {
//        m_pproxyModel->setPassed(cond);
//    }
//}

//void ModelMgr::sltFilterChanged(int filter)
//{
//    qDebug() << Q_FUNC_INFO;
//    if (Q_NULLPTR != m_pproxyModel) {
//        if (!(filter > ProxyModel::Proxy_Filter::GROUP_ALL || filter < ProxyModel::Proxy_Filter::GROUP_A))
//            m_pproxyModel->setFilter(filter);
//    }
//}

//void ModelMgr::sltSortRoleChanged(int role){
//    qDebug() << Q_FUNC_INFO;
//    if (Q_NULLPTR != m_pproxyModel)
//        m_pproxyModel->setSortRole(role);
//}

void ModelMgr::connectSignals()
{
    qDebug() << Q_FUNC_INFO;
    connect(m_pviewManager, &MainViewMgr::sgnAddRow, this, &ModelMgr::sltAddRow);
    connect(m_pviewManager, &MainViewMgr::sgnRemoveRow, this, &ModelMgr::sltRemoveRow);
    connect(m_pviewManager, &MainViewMgr::sgnChangeStudentInfo, this, &ModelMgr::sltChangeStudentInfo);
    //connect(m_pviewManager, &MainViewMgr::sgnPassedConditionChanged, this, &ModelMgr::sltPassedConditionChanged);
    //connect(m_pviewManager, &MainViewMgr::sgnFilterChanged, this, &ModelMgr::sltFilterChanged);

    connect(this, &ModelMgr::sgnRowAdded, m_phandler, &DataHandler::sltRowAdded);
    connect(this, &ModelMgr::sgnRowRemoved, m_phandler, &DataHandler::sltRowRemoved);
    connect(this, &ModelMgr::sgnStudentInfoChanged, m_phandler, &DataHandler::sltStudentInfoChanged);
}
