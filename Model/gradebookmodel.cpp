#include "gradebookmodel.h"
#include "studentterm.h"


GradebookModel::GradebookModel(DataHandler *dataHandler)
    : m_phandler(dataHandler),
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

QVariant GradebookModel::headerData(int section, Qt::Orientation orientation, int role) const
{

}

Qt::ItemFlags GradebookModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}

bool GradebookModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
        return false;

    switch (role) {
    case NameRole:
        m_pcollection->updateEntry(index.row(), value, Attributes::NAME);
        break;
    case GroupRole:
        m_pcollection->updateEntry(index.row(), value, Attributes::GROUP);
        break;
    case EmailRole:
        m_pcollection->updateEntry(index.row(), value, Attributes::EMAIL);
        break;
    case AssessmentsRole:
        m_pcollection->updateEntry(index.row(), value, Attributes::ASSESSMENTS);
        break;
    case Homework1Role:
        m_pcollection->updateEntry(index.row(), value, Attributes::HOMEWORK1);
        break;
    case Homework2Role:
        m_pcollection->updateEntry(index.row(), value, Attributes::HOMEWORK2);
        break;
    case LabGradeRole:
        m_pcollection->updateEntry(index.row(), value, Attributes::LABGRADE);
        break;
    case TestGradeRole:
        m_pcollection->updateEntry(index.row(), value, Attributes::TESTGRADE);
        break;
    default:
        return false;
    }

    emit dataChanged(index, index);
    return true;


}

bool GradebookModel::addData(const StudentTerm &st)
{
    if (m_pcollection->isIdPresent(st.id()))
    {
        qDebug() << "Id already present.";
        return false;
    }
    else
    {
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        m_pcollection->append(new StudentTerm(st));
        endInsertRows();
    }
}

bool GradebookModel::removeRow(int row, const QModelIndex &parent)
{
    beginRemoveRows(QModelIndex(), row, row);
    m_pcollection->removeEntry(row);
    endRemoveRows();
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
        m_pcollection = const_cast<StudentCollection*> (m_phandler->getCollection());
}
