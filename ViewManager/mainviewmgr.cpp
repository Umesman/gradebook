
#include "mainviewmgr.h"
#include "../Model/proxymodel.h"
#include "../Model/modelmgr.h"
#include "../Model/gradebookmodel.h"
#include "editform.h"

MainViewMgr::MainViewMgr(ModelMgr *pmanager) :
    QObject(pmanager),
    m_pmodelManager(pmanager),
    m_pStudentForm(Q_NULLPTR),
    m_groupFilter(0),
    m_sortRole(0),
    m_passed(false),
    m_editModeActive(false)
{
    qDebug() << Q_FUNC_INFO;
    m_groupFilter = m_pmodelManager->getGroupFilter();
    m_sortRole = m_pmodelManager->getSortRole();
    m_pStudentForm = new EditForm(this);
}

MainViewMgr::~MainViewMgr()
{
    qDebug() << Q_FUNC_INFO;
    if (Q_NULLPTR != m_pStudentForm)
        delete m_pStudentForm;
}


void MainViewMgr::setPassed(bool passed)
{
    qDebug() << Q_FUNC_INFO << " passed: " << passed;

    if (m_passed == passed)
        return;
    m_passed = passed;
    m_pmodelManager->setPassedFilter(passed);

    emit passedChanged();
}

void MainViewMgr::setGroupFilter(int currentGroup)
{
    qDebug() << Q_FUNC_INFO << " group: " << currentGroup;
    if (m_groupFilter != currentGroup)
    {
        m_groupFilter = currentGroup;
        m_pmodelManager->setGroupFilter(currentGroup);

        emit groupFilterChanged();
    }
}

void MainViewMgr::setSortRole(int attr)
{
    qDebug() << Q_FUNC_INFO << "  attr: " << attr;
    Attributes attribute = static_cast<Attributes> (attr);
    int role = static_cast<int> (m_pmodelManager->mapAttributeToRole(attribute));
    qDebug() << Q_FUNC_INFO << "  role: " << role << " : m_sortRole: " << m_sortRole;
    if (m_sortRole != role)
    {
        m_sortRole = role;        
        emit sortRoleChanged();
    }
    m_pmodelManager->setSortRole(m_sortRole);

}

void MainViewMgr::setEditMode(bool activeVal)
{
    qDebug() << Q_FUNC_INFO << " active: " << activeVal;
    if (m_editModeActive != activeVal)
    {
        m_editModeActive = activeVal;
        emit editModeChanged();
    }
}

void MainViewMgr::editStudentInfo(int id)
{
    qDebug() << Q_FUNC_INFO << "Id: " << id;
    int row = m_pmodelManager->indexOfId(id);
    const StudentTerm *editableStudent = m_pmodelManager->modelListValueAt(row);

    if (Q_NULLPTR != editableStudent)
        m_pStudentForm->setStudentInfo(editableStudent);
}


QSortFilterProxyModel *MainViewMgr::model()
{
    qDebug() << Q_FUNC_INFO;
    return m_pmodelManager->getProxy();
}

EditForm *MainViewMgr::studentForm()
{
    return m_pStudentForm;
}

bool MainViewMgr::passed() const
{
    qDebug() << Q_FUNC_INFO << " is passed filtering active: " << m_passed;
    return m_passed;
}

int MainViewMgr::groupFilter() const
{
    qDebug() << Q_FUNC_INFO << " is current filter: " << m_groupFilter;
    return m_groupFilter;

}

int MainViewMgr::sortRole() const
{
    return m_sortRole;
}

bool MainViewMgr::editMode() const
{
    //qDebug() << Q_FUNC_INFO << " is current active: " << m_editModeActive ;
    return m_editModeActive;
}

void MainViewMgr::sltNotifyStudentInfoChange(QVariant value, Attributes attribute, int studentId)
{
    qDebug() << Q_FUNC_INFO;
    GradebookModel::StudentRoles role = m_pmodelManager->mapAttributeToRole(attribute);

    int row = m_pmodelManager->indexOfId(studentId);
    qDebug() << "Row returned : " << row;
    QModelIndex index = m_pmodelManager->modelIndex(row);
    qDebug() << "Row returned : " << index.row();
     qDebug() << Q_FUNC_INFO << "sgnChangeStudentInfo emitted";
    emit sgnChangeStudentInfo(index, value, role);

}
