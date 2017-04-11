#include "gradebookmodel.h"
#include "studentterm.h"


GradebookModel::GradebookModel(DataHandler *dataHandler, QObject *parent)
    : QObject(parent),
      p_handler(dataHandler),
      p_students_list(NULL)
{
    setModelSource();
}

int GradebookModel::rowCount(const QModelIndex &parent) const
{
    return p_students_list->count();
}

QVariant GradebookModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= p_students_list->count())
        return QVariant();

    const StudentTerm *st_term = p_students_list->at(index.row());

    switch(role) {
    case IdRole :
        return st_term->id();
        break;
    case NameRole :
        return st_term->name();
        break;
    case GroupRole :
        return st_term->group();
        break;
    case EmailRole :
        return st_term->email();
        break;
    case AssessmentsRole :
        return st_term->assesments();
        break;
    case Homework1Role :
        return st_term->homework1();
        break;
    case Homework2Role :
        return st_term->homework2();
        break;
    case LabGradeRole :
        return st_term->labGrade();
        break;
    case TestGradeRole :
        return st_term->testGrade();
        break;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> GradebookModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[GroupRole] = "group";
    roles[EmailRole] = "email";
    roles[AssessmentsRole] = "assessments";
    roles[Homework1Role] = "homework1";
    roles[Homework2Role] = "homework2";
    roles[LabGradeRole] = "labgrade";
    roles[TestGradeRole] = "testgrade";

    return roles;
}


void GradebookModel::setModelSource()
{
    if (nullptr != p_handler)
        p_students_list = p_handler->getCollectionList();
}
