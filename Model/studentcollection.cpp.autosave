#include "studentcollection.h"
//#include <QList>


StudentCollection::~StudentCollection()
{
    qDebug() << "StudentCollection::~StudentCollection";
    if (!m_studentList->empty())
    {
        for (auto it = m_studentList->begin(); it != m_studentList->end(); it ++)
        {
            delete *it;
        }
    }
    delete m_studentList;
}


void StudentCollection::addEntry(StudentTerm *st)
{
    qDebug() << "StudentCollection::addEntry";
    m_studentList->append(st);
}


void StudentCollection::removeEntry(int index)
{
    qDebug() << "StudentCollection::removeEntry";
    m_studentList->removeAt(index);
    emit NotifyEntryRemoved(index);
}

void StudentCollection::updateEntry(int index, QVariant value, int attribute)
{
    qDebug() << "StudentCollection::updateEntry";
    StudentTerm *student = m_studentList->at(index);
    student->updateByValue(value, attribute);
}


StudentTerm* StudentCollection::getTermAt(int index)
{
    qDebug() << "StudentCollection::getTermAt";
    return m_studentList->at(index);
}


int StudentCollection::size() const
{
    qDebug() << "StudentCollection::size";
    qDebug() << "size = " << m_studentList->size();
    return m_studentList->size();
}


const QList<StudentTerm *>* StudentCollection::getList() const
{
    qDebug() << "StudentCollection::getList";
    return m_studentList;
}

std::ostream & operator<<(std::ostream &os,const StudentCollection &coll)
{
    qDebug() << "operator<< StudentCollection";
    int size = coll.size();
    int i;
    if (size > 0)
    {
        for (i = 0; i < size; i++)
        {
            os << *coll.getList()->at(i);
            if (i % 5 == 2)
                os << std::endl;
        } // for
        if (i % 5 != 3)
            os << std::endl;
    }
    return os;
}
