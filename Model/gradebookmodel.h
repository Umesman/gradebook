#ifndef GRADEBOOKMODEL_H
#define GRADEBOOKMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "datahandler.h"

class StudentTerm;

class GradebookModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum StudentRoles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        GroupRole,
        EmailRole,
        AssessmentsRole,
        Homework1Role,
        Homework2Role,
        LabGradeRole,
        TestGradeRole
    };

    GradebookModel(DataHandler *dataHandler,
                   QObject *parent =0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                           int role = Qt::DisplayRole) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole);

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    void setModelSource();
    DataHandler *p_handler;
    QList<StudentTerm *> * p_students_list;
};

#endif // GRADEBOOKMODEL_H
