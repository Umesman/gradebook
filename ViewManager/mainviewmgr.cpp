#include "mainviewmgr.h"
#include "../Model/proxymodel.h"
#include "../Model/modelmgr.h"
#include "../Model/gradebookmodel.h"

MainViewMgr::MainViewMgr(ModelMgr *pmanager) :
    QObject(pmanager),
    m_pmodelManager(pmanager),
    m_pmodel(Q_NULLPTR),
    m_pmodelProxy(Q_NULLPTR),
    m_groupFilter(ProxyModel::Proxy_Filter::GROUP_ALL),
    m_passed(false),
    m_editModeActive(false)
{
    qDebug() << Q_FUNC_INFO;
    if (m_pmodelManager != Q_NULLPTR)
    {
        m_pmodel = m_pmodelManager->getModel();
        //m_pmodelProxy = m_pmodelManager->getProxy();
        setModelProxy(m_pmodelManager->getProxy());
    }
}

void MainViewMgr::setModel(QAbstractItemModel *model)
{
    qDebug() << Q_FUNC_INFO;
    if (m_pmodel != model)
    {
        m_pmodel = model;
        emit modelChanged();
    }
}

void MainViewMgr::setModelProxy(QSortFilterProxyModel *proxyModel)
{
    qDebug() << Q_FUNC_INFO;
    if (m_pmodelProxy != proxyModel)
    {
        m_pmodelProxy = proxyModel;
        emit modelProxyChanged();
    }
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

void MainViewMgr::setEditMode(bool activeVal)
{
    qDebug() << Q_FUNC_INFO << " active: " << activeVal;
    if (m_editModeActive != activeVal)
    {
        m_editModeActive = activeVal;
        emit editModeChanged();
    }
}

QAbstractItemModel *MainViewMgr::model() const
{
    qDebug() << Q_FUNC_INFO;
    return m_pmodel;

}

QSortFilterProxyModel *MainViewMgr::modelProxy() const
{
    qDebug() << Q_FUNC_INFO;
    return m_pmodelProxy;

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

bool MainViewMgr::editMode() const
{
    qDebug() << Q_FUNC_INFO << " is current active: " << m_editModeActive ;
    return m_editModeActive;
}
