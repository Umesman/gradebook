#include "gradebookmodel.h"
#include "studentterm.h"
#include <QDebug>

GradebookModel::GradebookModel(QObject *parent)
    : QAbstractListModel(parent),
      m_pcollection(Q_NULLPTR)
{
    qDebug() << Q_FUNC_INFO;
}

int GradebookModel::rowCount(const QModelIndex &parent) const
{
    return m_pcollection->count();
}

QVariant GradebookModel::data(const QModelIndex &index, int role) const
{
    //qDebug() << "GradebookModel::data for row" << index.row();
    if (index.row() < 0 || index.row() >= m_pcollection->count())
        return QVariant();

    const StudentTerm *st_term = m_pcollection->getTermAt(index.row());

    switch(role) {
    case IdRole :
        return st_term->id();
    case FirstNameRole :
        return st_term->firstName();
    case LastNameRole :
        return st_term->lastName();
    case GroupRole :
        return st_term->group();
    case EmailRole :
        return st_term->email();
    case FinalRole:
        return st_term->final();
    case AssessmentsRole :
        return st_term->assesments();
    case Homework1Role :
        return st_term->homework1();
    case Homework2Role :
        return st_term->homework2();
    case LabGradeRole :
        return st_term->labGrade();
    case TestGradeRole :
        return st_term->testGrade();
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
    qDebug() << Q_FUNC_INFO << index.row();
    if (!index.isValid())
        return false;

    switch (role) {
    case FirstNameRole:
        m_pcollection->updateEntry(index.row(), value, Attributes::FIRST_NAME);
        break;
    case LastNameRole:
        m_pcollection->updateEntry(index.row(), value, Attributes::LAST_NAME);
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
        qDebug() << Q_FUNC_INFO << " default: returning false.";
        return false;
    }

    emit dataChanged(index, index);
    qDebug() << Q_FUNC_INFO << "dataChanged emitted";
    return true;


}

bool GradebookModel::addData(const StudentTerm &st)
{
    if (m_pcollection->isIdPresent(st.id()).first)
    {
        qDebug() << "Id already present.";
        return false;
    }
    else
    {
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        //        m_pcollection->append(new StudentTerm(st.id(), st.firstName(), st.lastName(), st.group(), st.email(),
        //                                              st.assesments(),st.homework1(),st.homework2(),
        //                                              st.labGrade(), st.testGrade()));
        m_pcollection->append(new StudentTerm(st));
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

    roles[FirstNameRole] = "firstName";
    roles[LastNameRole] = "lastName";
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


void GradebookModel::setModelSource(StudentCollection *collection)
{
    if (collection)
        m_pcollection = collection;
}

int GradebookModel::indexOfId(const int id) const
{
    qDebug() << Q_FUNC_INFO << "id " << id;
    std::pair<bool, int> pair = m_pcollection->isIdPresent(id);
    if (!pair.first)
        qDebug() << Q_FUNC_INFO << " id " << id << " not found.";

    qDebug() << Q_FUNC_INFO << pair.second;
    return pair.second;
}

const StudentTerm *GradebookModel::listValueAt(int index)
{
    qDebug() << Q_FUNC_INFO << " row " << index;
    if (Q_NULLPTR != m_pcollection)
        return m_pcollection->getTermAt(index);

    return Q_NULLPTR;
}

QString GradebookModel::headerLabel(int section) const
{
    qDebug() << Q_FUNC_INFO;
    if (section < 0 || section > 8)
        return QString();

    QString ret_value;

    switch (section){
    case HeaderSection::FirstName :
        ret_value = "Name";
        break;
    case HeaderSection::LastName :
        ret_value = "Last Name";
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
    case HeaderSection::Actions :
        ret_value = "Actions";
        break;
    default:
        ret_value = "default";
    }

    qDebug() << Q_FUNC_INFO <<ret_value;
    return ret_value;
}
