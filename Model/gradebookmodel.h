#ifndef GRADEBOOKMODEL_H
#define GRADEBOOKMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "datahandler.h"

class StudentTerm;

class GradebookModel : public QAbstractListModel
{
    Q_OBJECT
    Q_ENUMS (HeaderSection)
public:
    enum StudentRoles {
        IdRole = Qt::UserRole + 1,
        FirstNameRole,
        LastNameRole,
        GroupRole,
        EmailRole,
        AssessmentsRole,
        FinalRole,
        Homework1Role,
        Homework2Role,
        LabGradeRole,
        TestGradeRole
    };

    enum HeaderSection {
        FirstName,
        LastName,
        Final,
        Email,
        Homework1,
        Homework2,
        Labgrade,
        TestGrade,
        LastSection
    };

    explicit GradebookModel(QObject *parent=0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    Q_INVOKABLE QVariant headerData(int section, Qt::Orientation orientation = Qt::Horizontal,
                           int role = Qt::DisplayRole) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole);

    bool addData(const StudentTerm &st);
    bool removeRow(int row, const QModelIndex &parent = QModelIndex());

    int sections() { return (int) HeaderSection::LastSection;}

    void setModelSource(StudentCollection *collection);

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QString headerLabel(int section) const;
    StudentCollection *m_pcollection;
};

#endif // GRADEBOOKMODEL_H
