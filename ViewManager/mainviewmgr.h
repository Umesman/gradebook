#ifndef MAINVIEWMGR_H
#define MAINVIEWMGR_H

#include <QObject>

class GradebookModel;
class StudentTerm;
class QAbstractItemModel;

class MainViewMgr : public QObject
{
    Q_OBJECT

public:
    explicit MainViewMgr(QObject *parent = 0);

    void setModel(QAbstractItemModel *);
signals:
    void sgnAddRow(const StudentTerm &st);
    void sgnRemoveRow(int row);
    void sgnChangeStudentInfo(const QModelIndex &index, const QVariant &value, int role);
    void sgnPassedConditionChanged(bool cond);
    void sgnFilterChanged(int filter);

public slots:

private:
   GradebookModel* m_pmodel;
};

#endif // MAINVIEWMGR_H
