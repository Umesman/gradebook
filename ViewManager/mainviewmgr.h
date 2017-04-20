#ifndef MAINVIEWMGR_H
#define MAINVIEWMGR_H

#include <QObject>
//#include "Model/modelmgr.h"

class ModelMgr;
class StudentTerm;
class QAbstractItemModel;

class MainViewMgr : public QObject
{
    Q_OBJECT

public:
    explicit MainViewMgr(ModelMgr *pmanager = 0);

    void setModel(QAbstractItemModel *model);
signals:
    void sgnAddRow(const StudentTerm &st);
    void sgnRemoveRow(int row);
    void sgnChangeStudentInfo(const QModelIndex &index, const QVariant &value, int role);
    void sgnPassedConditionChanged(bool cond);
    void sgnFilterChanged(int filter);

public slots:

private:
   ModelMgr* m_pmodelManager;
};

#endif // MAINVIEWMGR_H
