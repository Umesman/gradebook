#include "gradebookmodel.h"
#include "studentterm.h"
#include <QDebug>

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
    case FinalRole:
        return st_term->final();
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
    qDebug() << "GradebookModel::headerData " << section;
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
    {
        //return QString("Column %1").arg(section);
        return headerLabel(section);
    }
    else
        return QString("Row %1").arg(section);

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
        m_pcollection->append(new StudentTerm(st.id(), st.name(), st.group(), st.email(),
                                              st.assesments(),st.homework1(),st.homework2(),
                                              st.labGrade(), st.testGrade()));
        endInsertRows();
        return true;
    }
}

bool GradebookModel::removeRow(int row, const QModelIndex &parent)
{
    beginRemoveRows(QModelIndex(), row, row);
    m_pcollection->removeEntry(row);
    endRemoveRows();
    return true;
}

QHash<int, QByteArray> GradebookModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[NameRole] = "name";
    roles[IdRole] = "id";
    roles[GroupRole] = "group";
    roles[FinalRole] = "finalgrade";
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

QString GradebookModel::headerLabel(int section) const
{
    qDebug() << "GradebookModel::headerLabel";
    if (section < 0 || section > 6)
        return QString();

    QString ret_value;

    switch (section){
    case HeaderSection::Name :
        ret_value = "Name";
        break;
    case HeaderSection::Final :
        ret_value = "Final grade";
        break;
    case HeaderSection::Email :
        ret_value = "Email";
        break;
    case HeaderSection::Homework1 :
        ret_value = "Homework #1";
        break;
    case HeaderSection::Homework2 :
        ret_value = "Homework #2";
        break;
    case HeaderSection::Labgrade :
        ret_value = "Lab grade";
        break;
    case HeaderSection::TestGrade :
        ret_value = "Test grade";
        break;
    default:
        ret_value = "";
    }

    return ret_value;
}