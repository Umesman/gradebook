#ifndef MAINVIEWMGR_H
#define MAINVIEWMGR_H

#include <QObject>
//#include "Model/modelmgr.h"
#include <QPersistentModelIndex>
#include "../publicdefinitions.h"

class ModelMgr;
class StudentTerm;
class EditForm;
class QAbstractItemModel;
class QSortFilterProxyModel;


class MainViewMgr : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool passed
               READ passed
               WRITE setPassed
               NOTIFY passedChanged)

    Q_PROPERTY(QSortFilterProxyModel* model
               READ model
               NOTIFY modelChanged)

    Q_PROPERTY(bool editMode
               READ editMode
               WRITE setEditMode
               NOTIFY editModeChanged)

    Q_PROPERTY(int groupFilter
               READ groupFilter
               WRITE setGroupFilter
               NOTIFY groupFilterChanged)

    Q_PROPERTY(int sortRole
               READ sortRole
               WRITE setSortRole
               NOTIFY sortRoleChanged)

public:
    explicit MainViewMgr(ModelMgr *pmanager = 0);
    virtual ~MainViewMgr();

    void setPassed(bool passed);
    void setGroupFilter(int currentGroup);
    void setSortRole (int attr);
    void setEditMode(bool active);
    Q_INVOKABLE void editStudentInfo(int id);

    QSortFilterProxyModel *model();
    EditForm *studentForm();
    int groupFilter() const;
    int sortRole() const;
    bool passed() const;
    bool editMode() const;

signals:
    void passedChanged();
    void modelChanged();
    void editModeChanged();
    void groupFilterChanged();
    void sortRoleChanged();

    void sgnAddRow(const StudentTerm &st);
    void sgnRemoveRow(int row);
    void sgnChangeStudentInfo(const QModelIndex &index, const QVariant &value, int role);

    void sgnPassedConditionChanged(bool cond);
    void sgnFilterChanged(int filter);
    void sgnSortRoleChanged(int role);

public slots:
    void sltNotifyStudentInfoChange(QVariant value, Attributes attribute, int studentId);


private:
    ModelMgr *m_pmodelManager;
    EditForm *m_pStudentForm;
    int m_groupFilter;
    int m_sortRole;
    bool m_passed;
    bool m_editModeActive;
};

#endif // MAINVIEWMGR_H
