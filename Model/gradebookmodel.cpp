#include "gradebookmodel.h"
#include "studentterm.h"


GradebookModel::GradebookModel(DataHandler *dataHandler, QObject *parent)
    : QObject(parent),
      m_phandler(dataHandler),
      m_pcollection(NULL)
{
    setModelSource();
}

int GradebookModel::rowCount(const QModelIndex &parent) const
{
    return m_pcollection->count();
}

QVariant GradebookModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_pcollection->count())
        return QVariant();

    const StudentTerm *st_term = m_pcollection->getTermAt(index.row());

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

Qt::ItemFlags GradebookModel::flags(const QModelIndex &index) const
{
   if (!index.isValid())
       return Qt::ItemIsEnabled;

   return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}

bool GradebookModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

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
    if (m_phandler)
        m_pcollection = m_phandler->getCollection();
}
