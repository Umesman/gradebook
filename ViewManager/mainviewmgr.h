#ifndef MAINVIEWMGR_H
#define MAINVIEWMGR_H

#include <QObject>
//#include "Model/modelmgr.h"
#include <QPersistentModelIndex>

class ModelMgr;
class StudentTerm;
class EditForm;
class QAbstractItemModel;
class QSortFilterProxyModel;
//class QPersistentModelIndex;


class MainViewMgr : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool passed
               READ passed
               WRITE setPassed
               NOTIFY passedChanged)

    Q_PROPERTY(QAbstractItemModel* model
               READ model
               NOTIFY modelChanged)

    Q_PROPERTY(QSortFilterProxyModel* modelProxy
               READ modelProxy
               NOTIFY modelProxyChanged)

    Q_PROPERTY(bool editMode
               READ editMode
               WRITE setEditMode
               NOTIFY editModeChanged)

    Q_PROPERTY(int groupFilter
               READ groupFilter
               WRITE setGroupFilter
               NOTIFY groupFilterChanged)


public:
    explicit MainViewMgr(ModelMgr *pmanager = 0);
    virtual ~MainViewMgr();

    void setModel(QAbstractItemModel *model);
    void setModelProxy(QSortFilterProxyModel *proxyModel);
    void setPassed(bool passed);
    void setGroupFilter(int currentGroup);
    void setEditMode(bool active);
    Q_INVOKABLE void editStudentInfo(int id);


    QAbstractItemModel *model() const;
    QSortFilterProxyModel *modelProxy() const;
    int groupFilter() const;
    bool passed() const;
    bool editMode() const;


signals:
    void passedChanged();
    void modelChanged();
    void modelProxyChanged();
    void editModeChanged();
    void groupFilterChanged();

    void sgnAddRow(const StudentTerm &st);
    void sgnRemoveRow(int row);
    void sgnChangeStudentInfo(const QModelIndex &index, const QVariant &value, int role);
    void sgnPassedConditionChanged(bool cond);
    void sgnFilterChanged(int filter);

public slots:


private:
   ModelMgr *m_pmodelManager;
   QAbstractItemModel *m_pmodel;
   QSortFilterProxyModel *m_pmodelProxy;
   EditForm *m_pStudentForm;
   QPersistentModelIndex m_currentIndex;
   int m_groupFilter;
   bool m_passed;
   bool m_editModeActive;
};

#endif // MAINVIEWMGR_H
