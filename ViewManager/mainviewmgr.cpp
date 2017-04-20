#include "mainviewmgr.h"

MainViewMgr::MainViewMgr(ModelMgr *pmanager) :
    QObject((QObject*)pmanager),
    m_pmodelManager(pmanager)
{

}

void MainViewMgr::setModel(QAbstractItemModel *model)
{

}
